#include "loadsave.h"

namespace ftpload{


WLoadZip::WLoadZip()
{
countObj=0;
}
//------------------------------------------------------------------------------------------------
void WLoadZip::createLZ(QString dirUnpack,QString pathTo, QStringList tegPathFind, QString val)
{
  tempDir=dirUnpack;
  pathToEnd=pathTo;
  tegFind=tegPathFind;
  valFind=val;
  countId=0;
}
//------------------------------------------------------------------------------------------------
void WLoadZip::startUnpack(QStringList listPathZip)//добавляет на обработку только список zip
{
QString dirFromLoad=tempDir;
dirFromLoad.replace("/","\\");
for(auto it=listPathZip.begin();it!=listPathZip.end();it++)
  {
   unpackZip(dirFromLoad+"\\"+*it,dirFromLoad);
  }

QDir dirFrom;
dirFrom.cd(tempDir);
QStringList listDir = dirFrom.entryList(QDir::Dirs);
listDir.removeAll("..");
listDir.removeAll(".");
fromDirToEnd(listDir);
}
//-------------------------------------------------------------------------------------------------
void  WLoadZip::formListFiles(QStringList listFiles)
{
  emit signAddFiles(listFiles);
}
//------------------------------------------------------------------------------------------------
void WLoadZip::fromDirToEnd(QStringList strListFrom)//обрабатывает существующие директории
{
  ndom::WFind* domObj;
  domObj=new ndom::WFind;
  ++countObj;
  domObj->id=countId;++countId;
  connect(domObj,SIGNAL(allThreadsStop(int)),this,SLOT(delObjThreads(int)));
  connect(domObj,SIGNAL(allThreadsLists(QStringList)),this,SLOT(formListFiles(QStringList)));
  domObj->createObj(strListFrom,pathToEnd, tegFind, valFind);
  domObj->startThreads();
  listThread.push_back(domObj);
}
//--------------------------------------------------------------------------------------------------
void  WLoadZip::delObjThreads(int ids)
{
--countObj;
  if(countObj<1)
    {for(auto it=listThread.begin();it!=listThread.end();it++)
        {
         if((*it)->id==ids){listThread.erase(it);break;}
        }
      emit allObjectsStop(id);}
}
//--------------------------------------------------------------------------------------------------
WLoadFtp::WLoadFtp()
{
  fromZip=new WLoadZip;
  client=new WFtpClient;
}
//--------------------------------------------------------------------------------------------------
WLoadFtp::~WLoadFtp()
{
  delete client;
  delete fromZip;

}
//------------------------------------------------------------------------------------------------
void WLoadFtp::createFtp(SInputFtp inputFtp)
{
  urlListDirs=inputFtp.urlList;
  pathTempDownl=inputFtp.pathTemp;
  client->setStFilter(inputFtp.stFilt);
  fromZip->createLZ(inputFtp.pathTemp,inputFtp.pathTo,inputFtp.tegPathFind,inputFtp.val);
  connect(client,SIGNAL(finishedList(QStringList,QStringList)),this,SLOT(nextLoad(QStringList,QStringList)));
  countToExit=inputFtp.countToExitDirUrl;
  client->connectServ(inputFtp.url,inputFtp.login,inputFtp.password);
  client->cd(inputFtp.urlPath);
}
//------------------------------------------------------------------------------------------------
void WLoadFtp::download()
{
it=urlListDirs.begin();
client->cd(*it);
client->readFilesPosledov(pathTempDownl);
}
//------------------------------------------------------------------------------------------------
void  WLoadFtp::nextLoad(QStringList listGet,QStringList errors)
{
  fromZip->startUnpack(listGet);
  for(int i=0;i<countToExit;i++)
  {client->cd("..");}
   ++it;

 if(it!=urlListDirs.end()){
                           client->cd(*it);
                           client->readFilesPosledov(pathTempDownl);}

}


}
