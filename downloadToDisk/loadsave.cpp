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

void WLoadZip::createLZ(QString dirUnpack,QString pathTo, QList<QRegExp> tegPathFind, QString val,int idNew,int flgClear)
{
      tempDir=dirUnpack;
      pathToEnd=pathTo;
      tegFindExp=tegPathFind;
      valFind=val;
      countId=0;
      id=idNew;
      flgClearAll=flgClear;
      QString idStr;
      idStr.sprintf("%i",id);
      initObj(QApplication::applicationDirPath()+"/7-Zip/7z.exe",dirUnpack);
}
//------------------------------------------------------------------------------------------------
void WLoadZip::startUnpackFind(QStringList listPathZip)//добавляет на обработку только список zip
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

void WLoadZip::startUnpack(QStringList listPathZip)//добавляет на обработку только список zip
{
QString dirFromLoad=tempDir;
dirFromLoad.replace("/","\\");
QString dirUnpackTo;
QStringList listDir;
for(auto it=listPathZip.begin();it!=listPathZip.end();it++)
  {
   unpackZip(dirFromLoad+"\\"+*it,pathToEnd,id,flgClearAll);
   listDir.push_back(tempDir+"/"+dirUnpackTo);
  }
emit allObjectsStop(id);
}

//------------------------------------------------------------------------------------------------
void WLoadZip::startUnpackWork(QStringList listPathZip)//добавляет на обработку только список zip
{
 if(CDELARHNOPROCESS==flgClearAll)
     {startUnpack(listPathZip);}
              else{startUnpackFind(listPathZip);}
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
  if(tegFind.size()>0)domObj->createObj(strListFrom,pathToEnd, tegFind, valFind,flgClearAll);
  else domObj->createObj(strListFrom,pathToEnd, tegFindExp, valFind,flgClearAll);
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
         if((*it)->id==idLocal){(*it)->deleteLater();
                                listThread.erase(it);
                                break;}
        }
      emit allObjectsStop(id);
       }
}
//--------------------------------------------------------------------------------------------------
WLoadFtp::WLoadFtp()
{
  client=new WNetFtpClient;
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

  client->ftpFiles.setStFilter(params.stFilt);

  countId=0;
  connect(client,SIGNAL(endDownload()),this,SLOT(endLoad()));
  connect(client,SIGNAL(downlTen(int,QStringList)),this,SLOT(nextUnpack(int,QStringList)));
  client->createFtp(params.url,params.login,params.password,params.urlPath,params.pathTemp);

  return 0;
}
//------------------------------------------------------------------------------------------------
void WLoadFtp::download()
{flgDownloadsAll=false;
client->getList(params.urlList,params.countToExitDirUrl);
}

void WLoadFtp::nextUnpack(int err,QStringList listGet)
{
    emit getDownloadFiles(err,listGet);
    WLoadZipThread *zip=new WLoadZipThread;

    if(params.tegPathFind.size()>0)zip->LoadZip.createLZ(params.pathTemp,params.pathTo,params.tegPathFind,params.val,countId,true);
       else{zip->LoadZip.createLZ(params.pathTemp,params.pathTo,params.tegExpPathFind,params.val,countId,true);}
    ++countId;
    connect(&zip->LoadZip,SIGNAL(signAddFiles(QStringList)),this,SLOT(getProcessFiles(QStringList)));
    connect(&zip->LoadZip,SIGNAL(allObjectsStop(int)),this,SLOT(delObjectThatStop(int)));
    zip->listPathZip=listGet;
    fromZip.push_back(zip);
    zip->start();
}

//------------------------------------------------------------------------------------------------
void  WLoadFtp::endLoad(void)
{
     emit allFilesDownload(id);

}
//---------------------------------------------------------------------------------------------------
void WLoadFtp::delObjectThatStop(int idLocal)
{
  for(auto i=fromZip.begin();i!=fromZip.end();i++)
  {if((*i)->LoadZip.id==idLocal)
        {(*i)->deleteLater();
         fromZip.erase(i);
         break;}
  }
  if((flgDownloadsAll)&&(fromZip.size()==0))
    {emit allFilesProcess(id);}
}
//--------------------------------------------------------------------------------------------------------------------
void W223fz::create223fzNotif(QString dirToReport,QStringList regions,QDateTime tmBegin,QDateTime tmEnd,QString inn)
{

    //QObject::connect(ftp223fz,SIGNAL(sGetFiles(QStringList)),BD,SLOT(writeToNotif(QStringList)));
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
//      inpFtp.urlList.push_back(*i+"/purchaseNoticeEP/daily");
//      inpFtp.urlList.push_back(*i+"/purchaseNoticeOK/daily");
//      inpFtp.urlList.push_back(*i+"/purchaseNoticeOA/daily");
//      inpFtp.urlList.push_back(*i+"/purchaseNoticeIS/daily");
//      inpFtp.urlList.push_back(*i+"/purchaseNoticeAE/daily");
//      inpFtp.urlList.push_back(*i+"/purchaseNoticeAE94/daily");
//      inpFtp.urlList.push_back(*i+"/purchaseNoticeZK/daily");
//      inpFtp.urlList.push_back(*i+"/ListsGWS/daily");
//      inpFtp.urlList.push_back(*i+"/ListsInnov/daily");
//      inpFtp.urlList.push_back(*i+"/VolumePurchases/daily");
//      inpFtp.urlList.push_back(*i+"/attachedOrderClause/daily");
//      inpFtp.urlList.push_back(*i+"/changeRequirements/daily");
      inpFtp.urlList.push_back(*i+"/complainWithdraw/daily");
      inpFtp.urlList.push_back(*i+"/complaint/daily");

//      inpFtp.urlList.push_back(*i+"/complaintDecision/daily");
//      inpFtp.urlList.push_back(*i+"/complaintVerificationPlan/daily");
//      inpFtp.urlList.push_back(*i+"/complaintVerificationResult/daily");
      inpFtp.urlList.push_back(*i+"/contract/daily");
      inpFtp.urlList.push_back(*i+"/contractCompleting/daily");
      inpFtp.urlList.push_back(*i+"/contractInfo/daily");
      inpFtp.urlList.push_back(*i+"/explanation/daily");

      inpFtp.urlList.push_back(*i+"/lotCancellation/daily");
      inpFtp.urlList.push_back(*i+"/orderClause/daily");
      inpFtp.urlList.push_back(*i+"/protocolLotAllocation/daily");
      inpFtp.urlList.push_back(*i+"/purchaseContract/daily");
      inpFtp.urlList.push_back(*i+"/purchaseContractAccount/daily");
      //inpFtp.urlList.push_back(*i+"/purchasePlan/daily");
      //inpFtp.urlList.push_back(*i+"/purchasePlanProject/daily");
    }
     inpFtp.flgDellArh=CDELDIRANDARH;

     ftp223fz->createFtp(inpFtp);
}
//--------------------------------------------------------------------------------------------------------------------
void W223fz::create223fzDish(QString dirToReport,QStringList regions,QDateTime tmBegin,QDateTime tmEnd)
{

      QObject::connect(ftp223fz,SIGNAL(sProcessFiles(QStringList)),BD,SLOT(writeToDishon(QStringList)));
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
//---------------------------------------------------------------------------------------------------------------------
W223fz::W223fz()
{
   BD=new WBaseWR;
   ftp223fz=new  WLoadFtp;

}
//---------------------------------------------------------------------------------------------------------------------
 W223fz::~W223fz()
 {
  delete BD;
 }
//----------------------------------------------------------------------------------------------------------------------
}
