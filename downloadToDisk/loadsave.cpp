#include "loadsave.h"
#include <QApplication>
#include <QTextStream>

namespace ftpload{


WLoadZip::WLoadZip()
{
countObj=0;
}
//------------------------------------------------------------------------------------------------
void WLoadZip::createLZ(QString dirUnpack,QString pathTo, QStringList tegPathFind, QString val,int idNew,int flgClear)
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

if(flgClearAll<CDELARHNOPROCESS)fromDirToEnd(listDir);
else{emit allObjectsStop(id);}
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
//--------------------------------------------------------------------------------------------------------------------
void W223fz::create223fzNotif(QString dirToReport,QStringList regions,QDateTime tmBegin,QDateTime tmEnd,QString inn)
{
  ftp223fz=new  WLoadFtp;

    inpFtp.url="ftp.zakupki.gov.ru";
    inpFtp.login="fz223free";
    inpFtp.password="fz223free";
    inpFtp.countToExitDirUrl=3;
    inpFtp.stFilt.dateBegin=tmBegin;
    inpFtp.stFilt.dateEnd=tmEnd;
    inpFtp.pathTo=dirToReport;
    inpFtp.pathTemp=QApplication::applicationDirPath()+"/temp223Notif";
    inpFtp.tegPathFind.push_back("customer");
    inpFtp.tegPathFind.push_back("mainInfo");
    inpFtp.tegPathFind.push_back("inn");
    inpFtp.val=inn;
    inpFtp.urlPath="out/published";
    for(auto i=regions.begin();i!=regions.end();i++)
    {
      inpFtp.urlList.push_back(*i+"/purchaseNoticeEP/daily");
      inpFtp.urlList.push_back(*i+"/purchaseNoticeOK/daily");
      inpFtp.urlList.push_back(*i+"/purchaseNoticeOA/daily");
      inpFtp.urlList.push_back(*i+"/purchaseNoticeIS/daily");
      inpFtp.urlList.push_back(*i+"/purchaseNoticeAE/daily");
      inpFtp.urlList.push_back(*i+"/purchaseNoticeAE94/daily");
      inpFtp.urlList.push_back(*i+"/purchaseNoticeZK/daily");
    }
     inpFtp.flgDellArh=CDELDIRANDARH;

     ftp223fz->createFtp(inpFtp);
}
//--------------------------------------------------------------------------------------------------------------------
void W223fz::create223fzDish(QString dirToReport,QStringList regions,QDateTime tmBegin,QDateTime tmEnd)
{
    ftp223fz=new  WLoadFtp;

      inpFtp.url="ftp.zakupki.gov.ru";
      inpFtp.login="fz223free";
      inpFtp.password="fz223free";
      inpFtp.countToExitDirUrl=3;
      inpFtp.stFilt.dateBegin=tmBegin;
      inpFtp.stFilt.dateEnd=tmEnd;
      inpFtp.pathTo=dirToReport;
      inpFtp.pathTemp=QApplication::applicationDirPath()+"/temp223Dish";
      inpFtp.urlPath="out/published";
      for(auto i=regions.begin();i!=regions.end();i++)
      {
        inpFtp.urlList.push_back(*i+"/dishonestSupplier/daily");
      }
       inpFtp.flgDellArh=CDELARHNOPROCESS;

       ftp223fz->createFtp(inpFtp);
}
//--------------------------------------------------------------------------------------------------------------------
int W223fz::getRegions(QStringList &regions)
{
    QFile *file=new QFile(QApplication::applicationDirPath()+"/regions223FZ.txt");
     if (!file->open(QIODevice::ReadOnly)) {return (-1);}
regions.clear();
     QTextStream ts(file); // из файла
while(!ts.atEnd())
    regions << ts.readLine();

delete file;
return 1;
}
//--------------------------------------------------------------------------------------------------------------------
}
