#include "loadsave.h"
#include <QApplication>

namespace ftpload{


WLoadZip::WLoadZip()
{
countObj=0;
}
//------------------------------------------------------------------------------------------------
void WLoadZip::createLZ(QString dirUnpack,QString pathTo, QStringList tegPathFind, QString val,int idNew,bool flgClear)
{
  tempDir=dirUnpack;
  pathToEnd=pathTo;
  tegFind=tegPathFind;
  valFind=val;
  countId=0;
  id=idNew;
  flgClearAll=flgClear;
  QString idStr;
  idStr.sprintf("%i",id);
  initObj(QApplication::applicationDirPath()+"/7-Zip/7z.exe",dirUnpack);
}
//------------------------------------------------------------------------------------------------
void WLoadZip::startUnpack(QStringList listPathZip)//добавляет на обработку только список zip
{
QString dirFromLoad=tempDir;
dirFromLoad.replace("/","\\");
QString dirUnpackTo;
QStringList listDir;
for(auto it=listPathZip.begin();it!=listPathZip.end();it++)
  {
    dirUnpackTo=*it;
    dirUnpackTo.replace(dirUnpackTo.lastIndexOf(".zip"),4,"");
   unpackZip(dirFromLoad+"\\"+*it,dirFromLoad+"\\"+dirUnpackTo,id,flgClearAll);
   listDir.push_back(tempDir+"/"+dirUnpackTo);
  }

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
  domObj->createObj(strListFrom,pathToEnd, tegFind, valFind,flgClearAll);
  domObj->startThreads();
  listThread.push_back(domObj);
}
//--------------------------------------------------------------------------------------------------
void  WLoadZip::delObjThreads(int idLocal)
{
--countObj;
  if(countObj<1)
    {for(auto it=listThread.begin();it!=listThread.end();it++)
        {
         if((*it)->id==idLocal){listThread.erase(it);break;}
        }
      emit allObjectsStop(id);
       }
}
//--------------------------------------------------------------------------------------------------
WLoadFtp::WLoadFtp()
{
  client=new WFtpClient;
}
//--------------------------------------------------------------------------------------------------
WLoadFtp::~WLoadFtp()
{
  delete client;
  for(auto i=fromZip.begin();i!=fromZip.end();i++)
  delete *i;

}
//------------------------------------------------------------------------------------------------
int WLoadFtp::createFtp(SInputFtp inputFtp)
{
  params=inputFtp;
  client->setStFilter(params.stFilt);
  countId=0;
  connect(client,SIGNAL(finishedList(QStringList,QStringList)),this,SLOT(nextLoad(QStringList,QStringList)));
  int conn=client->connectServ(params.url,params.login,params.password);
  if(conn!=-1)client->cd(params.urlPath);
  return conn;
}
//------------------------------------------------------------------------------------------------
void WLoadFtp::download()
{flgDownloadsAll=false;
it=params.urlList.begin();
client->cd(*it);
client->readFilesPosledov(params.pathTemp);
}
//------------------------------------------------------------------------------------------------
void  WLoadFtp::nextLoad(QStringList listGet,QStringList errors)
{
  emit getDownloadFiles(listGet,errors);
  WLoadZipThread *zip=new WLoadZipThread;
  zip->LoadZip=new WLoadZip;
  zip->LoadZip->createLZ(params.pathTemp,params.pathTo,params.tegPathFind,params.val,countId,true);
  ++countId;
  connect(zip->LoadZip,SIGNAL(signAddFiles(QStringList)),this,SLOT(getProcessFiles(QStringList)));
  connect(zip->LoadZip,SIGNAL(allObjectsStop(int)),this,SLOT(delObjectThatStop(int)));
  zip->listPathZip=listGet;
  fromZip.push_back(zip);
  zip->start();

  for(int i=0;i<params.countToExitDirUrl;i++)
  {client->cd("..");}
   ++it;

 if(it!=params.urlList.end())
   {client->cd(*it);
    client->readFilesPosledov(params.pathTemp);}
 else{emit allFilesDownload(id);
      flgDownloadsAll=true;}

}
//---------------------------------------------------------------------------------------------------
void WLoadFtp::delObjectThatStop(int idLocal)
{
  for(auto i=fromZip.begin();i!=fromZip.end();i++)
  {if((*i)->LoadZip->id==idLocal)
        {delete *i;
         fromZip.erase(i);
         break;}
  }
  if((flgDownloadsAll)&&(fromZip.size()==0))
    {emit allFilesProcess(id);}
}

}
