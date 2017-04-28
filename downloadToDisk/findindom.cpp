#include "findindom.h"
#include <QFile>
#include <QDomNodeList>
#include <QDomElement>
#include <QDir>
#include <QDateTime>
#include <QApplication>

namespace ndom{

  //рекурсивная функция проверяет путь вложения list, элемент с которого начинается проверка на вложение считается последним в списке list
bool controlNode(const QDomNode &controls,QStringList &list,int i)
  { --i;
    if(i==-1)return true;
    QString name=controls.nodeName();
    name.remove(0,name.lastIndexOf(':')+1);
    if(name==list.at(i)){
        return controlNode(controls.parentNode(),list,i);}
    else{return false;}
  }

//рекурсивная функция проверяет путь вложения list, элемент с которого начинается проверка на вложение считается последним в списке list
bool controlNode(const QDomNode &controls,QList<QRegExp> &list,int i)
{ --i;
  if(i==-1)return true;
  QString name=controls.nodeName();
  if(name.indexOf(list.at(i))!=-1){
      return controlNode(controls.parentNode(),list,i);}
  else{return false;}
}
//-------------------------------------------------------------------------------
bool removePath(const QString &path)
{
      bool result = true;
      QFileInfo info(path);
      if (info.isDir()) {
          QDir dir(path);
          foreach (const QString &entry, dir.entryList(QDir::AllDirs | QDir::Files | QDir::Hidden | QDir::NoDotAndDotDot)) {
              result &= removePath(dir.absoluteFilePath(entry));
          }
          if (!info.dir().rmdir(info.fileName()))
              return false;
      } else {
          result = QFile::remove(path);
      }
      return result;
}
//-------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------
bool WFindInDom::findInText(QString xmlText,QStringList teg,QStringList &valOut)
{QDomDocument doc;//QRegExp("[a-z]{1,3}[0-9]:")
  //xmlText.replace(QRegExp("[a-z]{1,2}[0-9,a-z]{1}:{1}"),"");
  valOut.clear();
  doc.setContent(xmlText);
  QDomNodeList controls = doc.elementsByTagName(teg.back());
  bool flgIt;
  for(int i=0;i<controls.length();i++)
  {  //ищем необходимое вложение
      flgIt=controlNode(controls.at(i),teg,teg.size());
     if(!flgIt){}
     else{ //добавляет значения в список
           valOut.push_back(controls.at(i).toElement().text());
           }
  }
       return true;
}

//----------------------------------------------------------------------------------------------
bool WFindInDom::findInText(QString xmlText,QStringList teg,QString &valOut)
{QDomDocument doc;//QRegExp("[a-z]{1,3}[0-9]:")
  xmlText.replace(QRegExp("[o,s,n]{2,3}[0-9]{0,1}:{1}"),"");
  valOut.clear();
  doc.setContent(xmlText);
  QDomNodeList controls = doc.elementsByTagName(teg.back());
  bool flgIt,flgFind=false;
  for(int i=0;i<controls.length();i++)
  {  //ищем необходимое вложение
      flgIt=controlNode(controls.at(i),teg,teg.size());
     if(!flgIt){}
     else{ //добавляет значения в список
           valOut=controls.at(i).toElement().text();
           flgFind=true;
           break;
           }
  }
       return flgFind;
}
//----------------------------------------------------------------------------------------------
bool WFindInDom::findInText(QString xmlText,QList<QStringList> teg,QString &valOut)
{ bool flgFind=false;
    for(auto it=teg.begin() ;it!=teg.end();it++)
    {
     flgFind=findInText(xmlText,*it,valOut);
     if(flgFind){
                 break;
                 }
    }
    return flgFind;
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
bool WFindInDom::findInFileAdd(QString path,QStringList &fileFind)
{
QDomDocument doc;
if(path.lastIndexOf(".xml")!=path.size()-4)
    {return false;}
QFile file(path);
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
   return false;
QString xml=file.readAll();
file.close();
xml.replace(QRegExp("[o,n,s]{2,3}[0-9]{0,1}:{1}"),"");
doc.setContent(xml);
QDomNodeList controls;
if(listNamesTeg.size()!=0){
                           controls = doc.elementsByTagName(listNamesTeg.back());}//присутствует условие
else if(doc.childNodes().size()==0){return false;}//файл пустой
      else {fileFind.push_back(doc.toString());
            return true;}//файл не пустой
bool flgIt;
for(int i=0;i<controls.length();i++)
{  //ищем необходимое вложение
    flgIt=controlNode(controls.at(i),listNamesTeg,listNamesTeg.size());
   if(!flgIt){}
   else{ //сравниваем с заданным значением тега
         QString val=controls.at(i).toElement().text();
        if(val==valFind)
        {fileFind.push_back(doc.toString());return true;}}
}
     return false;
}
//--------------------------------------------------------------------------------------------------
 bool WFindInDom::findInFileExpAdd(QString path,QStringList &fileFind)
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
         flgIt=controlNode(controls.at(i),tegsExp,tegsExp.size());
        if(!flgIt){}
        else{ //сравниваем с заданным значением тега
              QString val=controls.at(i).toElement().text();
             if(val==valFind){fileFind.push_back(doc.toString());return true;}}
     }
          return false;
 }

//----------------------------------------------------------------------------------------------
void WFindInDom::setFindAttr(QStringList tegs,QString val)
{
    listNamesTeg=tegs;
    valFind=val;
}

void WFindInDom::setFindAttr(QList<QRegExp> tegs,QString val)
{
    tegsExp=tegs;
    valFind=val;
}
//----последовательно перебирает возможные значения-----------------------------------------
int WFindInDom::findInDir(QString pathFrom, QString pathTo,QStringList &listAllFind,QStringList &fileFind,int ndomDel)
{ QDir dirFrom, dirTo;
    //QStringList fileFind;
  int ret=0;
    if(dirTo.exists(pathTo)){}
                 else{dirTo.mkdir(pathTo);
                      if(dirTo.exists(pathTo)){}else return -1;}
    dirFrom.cd(pathFrom);

     listAllFind = dirFrom.entryList(QDir::Files);

    for (auto i=listAllFind.begin();i!=listAllFind.end();i++)
    {
     if(!findInFileAdd(pathFrom+"/"+*i,fileFind)){}
           else{QFile::copy(pathFrom+"/"+*i,pathTo+"/"+*i);++ret;}
    }

    if(ndom::CDELDIR==ndomDel)
    {removePath(pathFrom);}
    return ret;
}
//-------------последовательно перебирает и ищет через exp фильтр----------------------------------------------------
int WFindInDom::findInDirExp(QString pathFrom, QString pathTo,QStringList &listAllFind,QStringList &fileFind,int ndomDel)
{
    QDir dirFrom, dirTo;
      int ret=0;
        if(dirTo.exists(pathTo)){}
                     else{dirTo.mkdir(pathTo);
                          if(dirTo.exists(pathTo)){}else return -1;}
        dirFrom.cd(pathFrom);

         listAllFind = dirFrom.entryList(QDir::Files);

        for (auto i=listAllFind.begin();i!=listAllFind.end();i++)
        {
         if(!findInFileExpAdd(pathFrom+"/"+*i,fileFind)){}
               else{QFile::copy(pathFrom+"/"+*i,pathTo+"/"+*i);++ret;}
        }

        if(ndom::CDELDIR==ndomDel)
        {removePath(pathFrom);}
        return ret;
}
//----------------------------------------------------------------------------------------------
void WFindThr::process()
{
  QStringList allFiles;
  QStringList listFind;
  for(auto i=listDirFrom.begin();i!=listDirFrom.end();i++)
  { listFilesFind.clear();
    findInDom->findInDir(*i,pathTo,allFiles,listFind,clearAll);
 listFilesFind<<listFind;
  }
  delete findInDom;
  emit finished();
  //this->deleteLater();
}
//----------------------------------------------------------------------------------------------
void WFindThrExp::process()
{
    QStringList allFiles;
    QStringList listFind;
  for(auto i=listDirFrom.begin();i!=listDirFrom.end();i++)
  { listFilesFind.clear();
    findInDom->findInDirExp(*i,pathTo,allFiles,listFind,clearAll);
  listFilesFind<<listFind;
  }
  delete findInDom;
  emit finished();
  //this->deleteLater();
}
//-------------Создает потоки для последующего запуска и обработки--------------------
void WFind::createObj(QStringList listDirFrom,QString dirTo,QStringList teg,QString val,bool flgClearAll)
{ flgStart=CSTRFILTER;
 int maxThreadsWork=QThread::idealThreadCount();

 if(maxThreadsWork!=1){--maxThreadsWork;}
 WFindThr* thrStart;
 int sz,szBeg;threadsWork=0;
 sz=(int)(listDirFrom.size()/maxThreadsWork);
 szBeg=listDirFrom.size()-sz*(maxThreadsWork-1);
 QStringList::iterator it;
 for(int i=0;i<maxThreadsWork;i++)
 {if(i==0){if(szBeg==0){threadsWork=0;
                        emit allThreadsStop(id);
                        break;}}
   thrStart=new WFindThr;
   thrStart->findInDom=new WFindInDom;
   thrStart->findInDom->setFindAttr(teg,val);
   thrStart->pathTo=dirTo;
   thrStart->id=i;
   if(flgClearAll){thrStart->clearAll=ndom::CDELDIR;}else{thrStart->clearAll=ndom::CNODELDIR;}
   if(i==0){for(it=listDirFrom.begin();it!=listDirFrom.begin()+szBeg;it++)
                thrStart->listDirFrom.push_back(*it);
           }
         else{for(;it!=listDirFrom.begin()+(szBeg+(i)*sz);it++)
                  thrStart->listDirFrom.push_back(*it);}
   listThr.push_back(thrStart);
   connect(thrStart,SIGNAL(finished()),this,SLOT(getSignalStop()));
   if(sz==0){threadsWork=1;break;}
  ++threadsWork;
 }
}
//-----------------Создает потоки для последующего запуска и обработки, использует фильтр QReg-------------------------------------
void WFind::createObj(QStringList listDirFrom,QString dirTo,QList<QRegExp> teg,QString val,bool flgClearAll)
{
   flgStart=CEXPFILTER;
   int maxThreadsWork=1;//QThread::idealThreadCount();
   if(maxThreadsWork!=1){--maxThreadsWork;}
   WFindThrExp* thrStart;
   int sz,szBeg;threadsWork=0;
   sz=(int)(listDirFrom.size()/maxThreadsWork);
   szBeg=listDirFrom.size()-sz*(maxThreadsWork-1);
   QStringList::iterator it;
 for(int i=0;i<maxThreadsWork;i++)
   {if(i==0){if(szBeg==0){threadsWork=0;
                        emit allThreadsStop(id);
                        break;}}
     thrStart=new WFindThrExp;
     thrStart->findInDom=new WFindInDom;
     thrStart->findInDom->setFindAttr(teg,val);
     thrStart->pathTo=dirTo;
     thrStart->id=i;
     if(flgClearAll){thrStart->clearAll=ndom::CDELDIR;}else{thrStart->clearAll=ndom::CNODELDIR;}
     if(i==0){for(it=listDirFrom.begin();it!=listDirFrom.begin()+szBeg;it++)
                  thrStart->listDirFrom.push_back(*it);
             }
           else{for(;it!=listDirFrom.begin()+(szBeg+(i)*sz);it++)
                    thrStart->listDirFrom.push_back(*it);}
     listThrExp.push_back(thrStart);
     connect(thrStart,SIGNAL(finished()),this,SLOT(getSignalStop()));
     if(sz==0){threadsWork=1;break;}
   ++threadsWork;
   }
}
//----------------------------------------------------------------------------------------------
void WFind::destroyObj()
{   stopThreads();
    for(int i=0;i<threadsWork;i++)
    {
     delete listThr.at(i)->findInDom;
      listThr.at(i)->deleteLater();
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
{ if(flgStart==CSTRFILTER)
      {listThr.at(i)->process();}
  if(flgStart==CEXPFILTER)
      {listThrExp.at(i)->process();}
}
}
//----------------------------------------------------------------------------------------------
void WFind::stopThreads()
{
    for(int i=0;i<threadsWork;i++)
    {if(flgStart==CEXPFILTER)
        {
      listThrExp.at(i)->deleteLater();}
     else if(flgStart==CSTRFILTER)
        {
         listThr.at(i)->deleteLater();}
    }
    countThr=0;
    emit allThreadsStop(id);
}
//----------------------------------------------------------------------------------------------
void WFind::getSignalStop()
{
--countThr;
    if(countThr==0){QStringList list;
                    if(listThr.size()!=0)
                    for(auto i=listThr.begin();i!=listThr.end();i++)
                      {
                        list<<(*i)->listFilesFind;
                        (*i)->listFilesFind.clear();
                      }
                    if(listThrExp.size()!=0)
                    for(auto i=listThrExp.begin();i!=listThrExp.end();i++)
                      {
                        list<<(*i)->listFilesFind;
                        (*i)->listFilesFind.clear();
                        //(*i)->deleteLater();
                      }
                    emit allThreadsLists(list);
                    emit allThreadsStop(id);}
}

}
