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
  if(tegFindExp.size()==0){domObj->createObj(strListFrom,pathToEnd, tegFind, valFind,flgClearAll);}
  else if(tegFindExp.size()>0){domObj->createObj(strListFrom,pathToEnd, tegFindExp, valFind,flgClearAll);}
  domObj->startThreads();
  listThread.push_back(domObj);
}
//--------------------------------------------------------------------------------------------------
void  WLoadZip::delObjThreads(int idLocal)
{
    for(auto it=listThread.begin();it!=listThread.end();it++)
            {
             if((*it)->id==idLocal){(*it)->deleteLater();
                                    listThread.erase(it);
                                    break;}
            }
--countObj;
  if(countObj<1)
    {
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
client->getListFiles(params.urlList);
}
//-------------------------------------------------------------------------------------------------
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
{    flgDownloadsAll=true;
     emit allFilesDownload(id);

}
//---------------------------------------------------------------------------------------------------
void WLoadFtp::delObjectThatStop(int idLocal)
{
  for(auto i=fromZip.begin();i!=fromZip.end();i++)
  {if((*i)->LoadZip.id==idLocal)
        {
         fromZip.erase(i);
         break;}
  }
  if((flgDownloadsAll)&&(fromZip.size()==0))
    {emit allFilesProcess(id);}
}
//-------------------------------------------------------------------------------------------------------------------
void W223fz::baseConnect(void)
{
switch(CFZ)
{case CFZ223:
 case CFZ44:{ QObject::connect(ftp223fz,SIGNAL(sGetFiles(QStringList)),BD,SLOT(writeToNotif(QStringList)));break;}
 case CFZ223Dish:
 case CFZ44Dish:{ QObject::connect(ftp223fz,SIGNAL(sGetFiles(QStringList)),BD,SLOT(writeToDishon(QStringList)));}
}

}

//--------------------------------------------------------------------------------------------------------------------
void W223fz::create223fzNotif(QString dirToReport,QStringList regions,QDateTime tmBegin,QDateTime tmEnd,QString inn)
{
    BD->start(CFZ223);
    CFZ=CFZ223;
    inpFtp.url="ftp.zakupki.gov.ru";
    inpFtp.login="fz223free";
    inpFtp.password="fz223free";
    inpFtp.stFilt.dateBegin=tmBegin;
    inpFtp.stFilt.dateEnd=tmEnd;
    inpFtp.stFilt.findExp.setPattern("[0-9]{8}_[0-9]{6}_[0-9]{8}_[0-9]{6}");
    inpFtp.stFilt.formDateBg="yyyyMMdd_HHmmss";
    inpFtp.stFilt.formDateEnd="yyyyMMdd";
    inpFtp.pathTo=dirToReport;
    inpFtp.pathTemp=QApplication::applicationDirPath()+"/temp223Notif";
    inn.replace(" ","");
    if(inn!="")
    {inpFtp.tegPathFind.push_back("customer");
    inpFtp.tegPathFind.push_back("mainInfo");
    inpFtp.tegPathFind.push_back("inn");}
    inpFtp.val=inn;
    inpFtp.urlPath="out/published";
    for(auto i=regions.begin();i!=regions.end();i++)
    {
      inpFtp.urlList.push_back(*i+"/contract/daily");
      //inpFtp.urlList.push_back(*i+"/contractCompleting/daily");
      //inpFtp.urlList.push_back(*i+"/contractInfo/daily");
    }
     inpFtp.flgDellArh=CDELDIRANDARH;

     ftp223fz->createFtp(inpFtp);
}
//--------------------------------------------------------------------------------------------------------------------
void W223fz::create223fzDish(QString dirToReport,QStringList regions,QDateTime tmBegin,QDateTime tmEnd)
{
       BD->start(CFZ223);
       CFZ=CFZ223Dish;
      inpFtp.url="ftp.zakupki.gov.ru";
      inpFtp.login="fz223free";
      inpFtp.password="fz223free";
      inpFtp.stFilt.dateBegin=tmBegin;
      inpFtp.stFilt.dateEnd=tmEnd;
      inpFtp.stFilt.findExp.setPattern("[0-9]{8}_[0-9]{6}_[0-9]{8}_[0-9]{6}");
      inpFtp.stFilt.formDateBg="yyyyMMdd_HHmmss";
      inpFtp.stFilt.formDateEnd="yyyyMMdd";
      inpFtp.pathTo=dirToReport;
      inpFtp.pathTemp=QApplication::applicationDirPath()+"/temp223Dish";
      inpFtp.urlPath="out/published";
      for(auto i=regions.begin();i!=regions.end();i++)
      {
        inpFtp.urlList.push_back(*i+"/dishonestSupplier/daily");
      }
       inpFtp.flgDellArh=CDELDIRANDARH;

       ftp223fz->createFtp(inpFtp);
}
//--------------------------------------------------------------------------------------------------------------------
void W223fz::create44fzNotif(QString dirToReport,QStringList regions,QDateTime tmBegin,QDateTime tmEnd,QString inn)
{
     BD->start(CFZ44);
     CFZ=CFZ44;
    inpFtp.url="ftp.zakupki.gov.ru";
    inpFtp.login="free";
    inpFtp.password="free";
    inpFtp.stFilt.dateBegin=tmBegin;
    inpFtp.stFilt.dateEnd=tmEnd;
    inpFtp.stFilt.findExp.setPattern("[0-9]{10}_[0-9]{10}");
    inpFtp.stFilt.formDateBg="yyyyMMddHH";
    inpFtp.stFilt.formDateEnd="yyyyMMdd";
    inpFtp.val=inn;
    inpFtp.pathTo=dirToReport;
    inpFtp.pathTemp=QApplication::applicationDirPath()+"/temp44Contr";
    inpFtp.urlPath="fcs_regions";
    if(inn!=""){
    inpFtp.tegPathFind.push_back("customer");
    inpFtp.tegPathFind.push_back("inn");}
    for(auto i=regions.begin();i!=regions.end();i++)
    {
      inpFtp.urlList.push_back(*i+"/contracts/prevMonth");
      inpFtp.urlList.push_back(*i+"/contracts/currMonth");
    }
     inpFtp.flgDellArh=CDELDIRANDARH;

     ftp223fz->createFtp(inpFtp);
}

//--------------------------------------------------------------------------------------------------------------------
void W223fz::create44fzDish(QString dirToReport,QDateTime tmBegin,QDateTime tmEnd)
{
    BD->start(CFZ44);
    CFZ=CFZ44Dish;
    inpFtp.url="ftp.zakupki.gov.ru";
    inpFtp.login="free";
    inpFtp.password="free";
    inpFtp.stFilt.dateBegin=tmBegin;
    inpFtp.stFilt.dateEnd=tmEnd;
    inpFtp.stFilt.findExp.setPattern("[0-9]{10}_[0-9]{10}");
    inpFtp.stFilt.formDateBg="yyyyMMddHH";
    inpFtp.stFilt.formDateEnd="yyyyMMdd";
    inpFtp.pathTo=dirToReport;
    inpFtp.pathTemp=QApplication::applicationDirPath()+"/temp44Dish";
    inpFtp.urlPath="fcs_fas";
    inpFtp.urlList.push_back("unfairSupplier");
    inpFtp.urlList.push_back("unfairSupplier/currMonth");
    inpFtp.flgDellArh=CDELDIRANDARH;
     ftp223fz->createFtp(inpFtp);
}

//--------------------------------------------------------------------------------------------------------------------
int W223fz::getRegions(QStringList &regions,const int CFZ)
{ QString path;
    switch(CFZ)
    {case CFZ223:{path=QApplication::applicationDirPath()+"/regions223FZ.txt";break;}
     case CFZ44:{path=QApplication::applicationDirPath()+"/regions44FZ.txt";}
    }

    QFile *file=new QFile(path);
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
