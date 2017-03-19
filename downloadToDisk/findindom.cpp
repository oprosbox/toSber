#include "findindom.h"
#include <QFile>
#include <QDomNodeList>
#include <QDomElement>
#include <QDir>

namespace ndom{


WFindInDom::WFindInDom()
{

}
//---------------------------------------------------------------------------------
bool WFindInDom::findInFile(QString path,QList<SListVal> &value)
{
    QDomDocument doc;

    QFile file(path);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       return false;

    doc.setContent(&file);
    file.close();

    SListVal listVal;
    for(auto it=listOftegs.begin();it!=listOftegs.end();it++)
    {
     listVal.path=*it;
    QDomNodeList controls = doc.elementsByTagName((*it).back());
    bool flgIt;
    for(int i=0;i<controls.length();i++)
    {  //ищем необходимое вложение
        flgIt=controlNode(controls.at(i),(*it),(*it).size());
       if(!flgIt){}
       else{ //добавляет значения в список
             listVal.value.push_back(controls.at(i).toElement().text());

       }
    }
    value.push_back(listVal);
    }
         return true;
}

//рекурсивная функция проверяет путь вложения list, элемент с которого начинается проверка на вложение считается последним в списке list
bool controlNode(const QDomNode &controls,QStringList &list,int i)
{ --i;
  if(i==-1)return true;
  QString name=controls.nodeName();
  name.indexOf(':');
  name.remove(0,name.indexOf(':')+1);
  if(name==list.at(i)){
      return controlNode(controls.parentNode(),list,i);}
  else{return false;}
}
//----------------------------------------------------------------------------------------------
bool WFindInDom::findInFile(QString path,QStringList &listVal)
{
    QDomDocument doc;

    QFile file(path);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       return false;

    doc.setContent(&file);
    file.close();
    QDomNodeList controls = doc.elementsByTagName(listNamesTeg.back());
    bool flgIt;
    for(int i=0;i<controls.length();i++)
    {  //ищем необходимое вложение
        flgIt=controlNode(controls.at(i),listNamesTeg,listNamesTeg.size());
       if(!flgIt){}
       else{ //добавляет значения в список
             listVal.push_back(controls.at(i).toElement().text());
             }
    }
         return true;
}
//----------------------------------------------------------------------------------------------
bool WFindInDom::findInFile(QString path)
{
QDomDocument doc;

QFile file(path);
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
   return false;

doc.setContent(&file);
file.close();
QDomNodeList controls = doc.elementsByTagName(listNamesTeg.back());
bool flgIt;
for(int i=0;i<controls.length();i++)
{  //ищем необходимое вложение
    flgIt=controlNode(controls.at(i),listNamesTeg,listNamesTeg.size());
   if(!flgIt){}
   else{ //сравниваем с заданным значением тега
         QString val=controls.at(i).toElement().text();
        if(val==valFind)return true;}
}
     return false;
}
//----------------------------------------------------------------------------------------------
void WFindInDom::setFindAttr(QStringList tegs,QString val)
{
    listNamesTeg=tegs;
    valFind=val;
}

//----последовательно перебирает возможные значения-----------------------------------------
int WFindInDom::findInDir(QString pathFrom, QString pathTo, int ndomDel)
{ QDir dirFrom, dirTo;
  int ret=0;
    if(!dirTo.cd(pathTo)){}
                 else{dirTo.mkdir(pathTo);
                      if(dirTo.cd(pathTo)){}else return -1;}
    dirFrom.cd(pathFrom);

    QStringList listDir = dirFrom.entryList(QDir::Files);

    for (auto i=listDir.begin();i!=listDir.end();i++)
    {
     if(!findInFile(pathFrom+"/"+*i)){}
           else{QFile::copy(pathFrom+"/"+*i,pathTo+"/"+*i);++ret;}
    }

    if(ndom::CDELDIR==ndomDel)
    {dirTo.rmdir(pathFrom);}
    return ret;
}
//----------------------------------------------------------------------------------------------
void WFindThr::run()
{
  for(auto i=listDirFrom.begin();i!=listDirFrom.end();i++)
  {
    findInDom->findInDir(*i,pathTo,ndom::CNODELDIR);
  }

  emit threadStop(id);
}
//----------------------------------------------------------------------------------------------
void WFind::createObj(QStringList listDirFrom,QString dirTo,QStringList teg,QString val)
{
 threadsWork=QThread::idealThreadCount();

 if(threadsWork!=1){--threadsWork;}
 WFindThr* thrStart;
 int sz,szBeg;
 sz=(int)(listDirFrom.size()/threadsWork);
 szBeg=listDirFrom.size()-sz*(threadsWork-1);
 QStringList::iterator it;
 for(int i=0;i<threadsWork;i++)
 {
   thrStart=new WFindThr;
   thrStart->findInDom=new WFindInDom;
   thrStart->findInDom->setFindAttr(teg,val);
   thrStart->pathTo=dirTo;
   thrStart->id=i;
   if(i==0){for(it=listDirFrom.begin();it!=listDirFrom.begin()+szBeg;it++)
                thrStart->listDirFrom.push_back(*it);
           }
         else{for(;it!=listDirFrom.begin()+(szBeg+(i)*sz);it++)
                  thrStart->listDirFrom.push_back(*it);}
   listThr.push_back(thrStart);
   connect(thrStart,SIGNAL(threadStop(int)),this,SLOT(getSignalStop(int)));
 }
}
//----------------------------------------------------------------------------------------------
void WFind::destroyObj()
{   stopThreads();
    for(int i=0;i<threadsWork;i++)
    {
     delete listThr.at(i)->findInDom;
     delete listThr.at(i);
    }
   threadsWork=0;
   countThr=0;
   listThr.clear();
}
//----------------------------------------------------------------------------------------------
void WFind::startThreads()
{
countThr=threadsWork;
for(int i=0;i<threadsWork;i++)
{
  listThr.at(i)->start();
}
}
//----------------------------------------------------------------------------------------------
void WFind::stopThreads()
{
    for(int i=0;i<threadsWork;i++)
    {
      listThr.at(i)->terminate();
    }
    countThr=0;
    emit allThreadsStop();
}
//----------------------------------------------------------------------------------------------
void WFind::getSignalStop(int id)
{
--countThr;
    if(countThr==0){emit allThreadsStop();}
}

}
