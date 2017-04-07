#include "ftpclient.h"

#include <QDir>
#include <QApplication>
#include <QDateTime>

#include <QFile>
#include <QTextStream>
#include "findindom.h"

WFtpClient::WFtpClient()
{
fileList = new QFile();
}
//----------------------фильтр обеспечивает фильтрацию архивов по времени с ftp сервера при создании списка--------------------
bool WFtpFilter::filter(QString url)
{
  int indUrl;
  //indUrl=url.indexOf(QRegExp("[0-9]{8}_[0-9]{6}_[0-9]{8}_[0-9]{6}"),0);
  indUrl=url.indexOf(stFilter.findExp,0);
  QString dateStrBeg;
  QString dateStrEnd;
  dateStrBeg.insert(0,url.data()+indUrl,stFilter.formDateBg.length());
  dateStrEnd.insert(0,url.data()+indUrl+stFilter.formDateBg.length()+1,stFilter.formDateEnd.length());
  QDateTime dateBegin,dateEnd;
  //dateBegin=QDateTime::fromString(dateStrBeg,"yyyyMMdd_HHmmss");
  //dateEnd=QDateTime::fromString(dateStrEnd,"yyyyMMdd");
  dateBegin=QDateTime::fromString(dateStrBeg,stFilter.formDateBg);
  dateEnd=QDateTime::fromString(dateStrEnd,stFilter.formDateEnd);
 // if(dateStrBeg=="2017030100")
 // {int u=0;}
 // if((stFilter.dateBegin<=dateBegin)&&(stFilter.dateEnd>=dateEnd))
  //условие пересечения двух отрезков
  if(((stFilter.dateEnd>=dateBegin)&&
       (stFilter.dateBegin<=dateEnd)))
  {return true;}
return false;
}

//-------------------------------коннектится к ftp источнику для получения фильтра------------------------------------------------
int WFtpClient::connectServ(QString serv,QString login,QString passv)
{
  ftpLiders = new QFtp(this);
  connect(this,SIGNAL(errorTo()),this,SLOT(reconToHost()));
  connect(ftpLiders, SIGNAL(commandFinished(int,bool)), this, SLOT(commFinish(int,bool)));
  connect(ftpLiders, SIGNAL(listInfo(QUrlInfo)), this, SLOT(doneURLInfo(QUrlInfo)));
  connect(ftpLiders, SIGNAL(commandFinished(int,bool)), this, SLOT(ftpConnected(int,bool)));
  connect(ftpLiders, SIGNAL(done(bool)), this, SLOT(doneEnd(bool)));
  mserv=serv;
  mlogin=login;
  mpassv=passv;
  currCommGet=-1;
  ftpLiders->connectToHost(mserv);
  ftpLiders->login(mlogin,mpassv);
  idCurr=0;
  return 1;
}
//------------------------------------------------------------------------------------------------------------
void WFtpClient::doneEnd(bool hasGood)
{
    if(hasGood)
    {int i=0;}
    else{int i=0;}
}

void WFtpClient::functTimer()
{
 if(toLoad!=-1)
       {++countTimer;
 if(countTimer>4)
      {reconToHost();
       countTimer=0;
       cd(cdBegin);
       emit errBeg();}
            }

}

//----------------------------------окончание комманды--------------------------------------------------------
void WFtpClient::commFinish(int id,bool hasGood)
{if(!hasGood){}else{QString txt="ftp error getList: "+ftpLiders->errorString().replace("\n"," ") ;
                    ndom::toLogFile(txt);
                    countTimer=0;}
 if(id==idCurr){switch(toLoad)
                 {case CLOADCURRFILE:{toLoad=-1;
                                      countTimer=0;
                                      emit sFiles(ftpLiders->error(),urlFiles);
                                      break;}
                   case CLOADCURRDIR:{toLoad=-1;
                                      countTimer=0;
//                                      qDebug()<<urlFiles;
//                                      QFile fLog(QApplication::applicationDirPath()+ "/regions44fz.txt");
//                                      fLog.open(QFile::WriteOnly);
//                                      for(int i=0;i<urlFiles.size();i++)
//                                      {  QString str=urlFiles.at(i)+"\r\n";
//                                      fLog.write(str.toLocal8Bit());}

//                                      fLog.close();
                                      emit sFiles(ftpLiders->error(),urlFiles);
                                      break;}
                   case CLOADLIST:{readList(urlFiles);}
                  }
               }
}
//------------------------------переходим по указанной директории------------------------------------------------------
void WFtpClient::cd(QString cdFromNull)
{
 if(cdFromNull!="")ftpLiders->cd(cdFromNull);
}
//------------------------------читаем все файлы из неё и сохраняем на жесткий диск-------------------------------------------------
void WFtpClient::readFiles(QString dirToSave)
{
 dirSave=dirToSave;
 toLoad=CLOADFILES;
 QDir dir(QApplication::applicationDirPath());
 if(!QDir(QApplication::applicationDirPath()+dirSave).exists())dir.mkdir(dirSave);
 idCurr=ftpLiders->list();
}
//-----------------------------------------слот получает список всех файлов-------------------------------------------
void WFtpClient::doneURLInfo(QUrlInfo urlInfo)
{
  switch (toLoad)
    {case CLOADCURRDIR:{if(urlInfo.isDir())
                          {urlFiles.push_back(urlInfo.name());}
                        break;}

     case CLOADCURRFILE:case CLOADLIST:{ if (urlInfo.isFile() && urlInfo.isReadable())
                                             {if(filter(urlInfo.name()))urlFiles.push_back(urlInfo.name());}
                                          break;}

     case CLOADFILES:{if (urlInfo.isFile() && urlInfo.isReadable()) {
                        QFile *file = new QFile(dirSave+"/"+urlInfo.name());
                        if (!file->open(QIODevice::WriteOnly)) {
                        //emit sendError(dirSave+"/"+urlInfo.name());
                        return;}
                        if(filter(urlInfo.name()))ftpLiders->get(urlInfo.name(), file);
                        openedFiles.push_back(file);}}
    }
}
//--------------------------------------------------------------------------------------------------------------
void WFtpClient::readList(QStringList lstFiles)
{ listFiles=lstFiles;
  toLoad=CLOADLIST;
  it=listFiles.begin();
  listFilesAdd.clear();
  FileListErrors.clear();
  do{++it;}
  while((it!=listFiles.end())&&(!filter(*it)));
  if(it!=listFiles.end()){}else{toLoad=-1;
                                emit finishedList(listFilesAdd,FileListErrors);
                           return;}
  fileList->setFileName(dirSave+"/"+*it);
  QString name=*it;
  if (!fileList->open(QIODevice::WriteOnly)) {
  //emit sendError(dirSave+"/"+*it);
  return;}
  QFile errorsN(QApplication::applicationDirPath()+"/errorsFtp.txt");
  if (!errorsN.open(QIODevice::WriteOnly)) {}
  listFilesAdd.push_back(*it);
  currCommGet=ftpLiders->get(*it, fileList);

}
//----------------------------------------------------------------------------------------
void WFtpClient::reconToHost(void)
{
  delete ftpLiders;
  int ret=connectServ(mserv,mlogin,mpassv);
  int yu=0;
}

//-------------------------------------------слот получает соединение-------------------------------------------
void WFtpClient::ftpConnected(int id,bool hasError)
{ //toLoad=-1;

    if(hasError){
                //emit sendError(ftpLiders->error(),ftpLiders->errorString());
                //QString err=ftpLiders->errorString();
                //emit sFiles(ftpLiders->error(),urlFiles);
                //reconToHost();
               //QFile errorsN(QApplication::applicationDirPath()+"/errorsFtp.txt");
               //if (!errorsN.open(QIODevice::Append)) {}
                //QTextStream out(&errorsN);
                //out<<*it<<err;
                 }
  //             return;}

  if(currCommGet==id)
  {
   switch (toLoad)
     {case CLOADFILES:{QStringList filename;
                       for (int i = 0; i < (int)openedFiles.size(); ++i)
                       {filename.push_back(openedFiles.at(i)->fileName());
                        delete openedFiles[i];
                        }
                        emit finished(filename);
                        break;}
      case CLOADLIST:{   fileList->close();

                         do{++it;}
                          while((it!=listFiles.end())&&(!filter(*it)));

                          if(it!=listFiles.end()){}else{toLoad=-1;
                                     emit finishedList(listFilesAdd,FileListErrors);
                                     return;}

                          fileList->setFileName(dirSave+"/"+*it);
                          if (!fileList->open(QIODevice::WriteOnly)) {
                          //emit sendError(dirSave+"/"+*it);
                          return;}
                          currCommGet=ftpLiders->get(*it, fileList);
                          listFilesAdd.push_back(*it);
                          break;
                       }

     }}
}
//------------------------------сохраняем уже полученые файлы на жесткий диск------------------------------------------------
void WFtpClient::save(void)
{
  for(auto i=openedFiles.begin(); i!=openedFiles.end();i++)
    {
     (*i)->close();
    }
}
//-----------------------------------------------отключаем ftp--------------------------------------------
void WFtpClient::disconnectServ(void)
{
  ftpLiders->close();
  delete ftpLiders;
  //save();
}
//----------------------------------читаем список всех директорий из текущего положения----------------------------------------
void WFtpClient::readDirectories(void)
{
toLoad=CLOADCURRDIR;
urlFiles.clear();
idCurr=ftpLiders->list();
}
//---------------------------------------читаем список всех файлов-----------------------------------------
void WFtpClient::readCurrFiles(void)
{
 toLoad=CLOADCURRFILE;
 urlFiles.clear();
 //countTimer=0;
 idCurr=ftpLiders->list();
}

int  WFtpClient::readFilesPosledov(QString dirToSave)
{    QDir  dirTo;
       if(dirTo.exists(dirToSave)){}
                    else{dirTo.mkdir(dirToSave);
                         if(dirTo.exists(dirToSave)){}else return -1;}
    toLoad=CLOADLIST;
    urlFiles.clear();
    dirSave=dirToSave;
    idCurr=ftpLiders->list();

}

void WNetworkFtp::errors(QNetworkReply::NetworkError err)
{emit errorEmit();}

//int WNetworkFtp::getFile(QString urlFile, QString out,QString &name)
//{

// QUrl url(urlFile);
// int pos=urlFile.lastIndexOf("/")+1;
// name=QString(urlFile.constData()+pos);
// currName=name;
// reply =  manager->get(QNetworkRequest(url));
// QObject::connect(reply,SIGNAL(finished()),loop,SLOT(quit()));
// QObject::connect(reply,SIGNAL(error(QNetworkReply::NetworkError)),this,SLOT(errors(QNetworkReply::NetworkError)));
// QObject::connect(this,SIGNAL(errorEmit()),loop,SLOT(quit()));
// QObject::connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(downloadProgress(qint64,qint64)));
// loop->exec();
// loop->disconnect();
// if(reply->error()==QNetworkReply::NoError)
//   { QFile  file(out+"/"+name);
//     file.open(QIODevice::WriteOnly);
//     file.write(reply->readAll());
//   delete reply;}
// else
//   {delete reply;
//     return -1;}

// return 0;
//}

 void WTimerControl::run()
 {flagWork=true;
   while(flagWork)
   {QThread::usleep(10000000);

    if(flagControl){
     ftp->functTimer();
    }
   }
 }
//------------------------------------------------------------------------------------------------
WNetworkFtp::WNetworkFtp()
{              manager=new QNetworkAccessManager;
               loop=new QEventLoop;
               timer=new QTimer;
 }
//--------------------------------------------------------------------------------------------------
WNetworkFtp::~WNetworkFtp()
              {delete timer;
               delete manager;
               delete loop;}
//-------------------------------------------------------------------------------------------------
void WNetworkFtp::downloadProgress(qint64 recv,qint64 total)
{
 ++control.countRefresh;
 control.countRefresh%=500000;
}
//---------------------------------------------------------------------------------------------------
int WNetworkFtp::getFile(SDownloads &urlFile)
{
 QUrl url(urlFile.path);
 urlFile.reply =  manager->get(QNetworkRequest(url));
 QString name;
 int pos=urlFile.path.lastIndexOf("/")+1;
 name=QString(urlFile.path.constData()+pos);
 urlFile.reply->setObjectName(name);
 connect(urlFile.reply,SIGNAL(error(QNetworkReply::NetworkError)),this,SLOT(errors(QNetworkReply::NetworkError)));
 connect(urlFile.reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(downloadProgress(qint64,qint64)));
 return 0;
}
//----------------------------------------------------------------------------------------------------
void WNetworkFtp::finished(QNetworkReply* reply)
{
    if(reply->error()==QNetworkReply::NoError)
      { QFile  file(outDir+"/"+reply->objectName());
        file.open(QIODevice::WriteOnly);
        file.write(reply->readAll());
        file.close();
        listDownloads.remove_if(PDel(reply));
        currNames.push_back(reply->objectName());
        reply->deleteLater();
        //if(currNames.size()==10){currNames.clear();}
    }
    else{

    }
}
//-------------------------------------------------------------------------------------------------
 void WNetworkFtp::functTimer(void)
 {if((listDownloads.size()!=0)&&(timer->isActive()))
   {
   if(control.countPrev==control.countRefresh)
       {QString txt="ftp error getFile: abort";
                 ndom::toLogFile(txt);
        abortAll();
        control.flagControl=false;
       }
         control.countPrev=control.countRefresh;
   }
     else{control.flagControl=false;}
 }
//------------------------------------------------------------------------------------------------
 void WNetworkFtp::startNext()
 {
   if((!control.flagControl)&&(listDownloads.size()!=0))
   {control.countPrev=control.countRefresh+1;
       getFiles();}
   if((listDownloads.size()==0)&&(currNames.size()!=0)) {emit emit10Obj(1,currNames);
                                                         currNames.clear();
                                                         manager->deleteLater();
                                                         emit allDownloads();
                                                         control.flagControl=false;
                                                         timer->stop();
                                                         }
   if((currNames.size()>10)) {emit emit10Obj(1,currNames);
                                    currNames.clear();
                                   }

 }
//------------------------------------------------------------------------------------------------
void WNetworkFtp::abortAll()
{

    for(auto it=listDownloads.begin();it!=listDownloads.end();it++)
      {
        (*it).reply->abort();
        (*it).reply->deleteLater();
      }
    manager->deleteLater();
}

//-------------------------------------------------------------------------------------------------
int WNetworkFtp::getFiles()
 {
    manager=new QNetworkAccessManager;
  QObject::connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));
    int ind=0;
  for(auto i=listDownloads.begin();i!=listDownloads.end();i++)
    {
     if(getFile((*i))!=-1){}else{break;}
  ++ind;
    }
control.flagControl=true;
  return 0;
 }


//------------------------------------------------------------------------------------------------
void WNetworkFtp::createFtp(QString out)
{ control.countRefresh=0;
  control.countPrev=10;
 outDir=out;
 control.ftp=this;

 QObject::connect(timer,SIGNAL(timeout()),this,SLOT(startNext()));
 //connect(&manager, SIGNAL(finished ( QNetworkReply *)), this, SLOT(finishRequest(QNetworkReply *)));
 }
//---------------------------------------------------------------------------------
void WNetworkFtp::finishRequest(QNetworkReply *Reply)
{

}
//---------------------------------------------------------------------------------------------------
void WNetworkFtp::start(QStringList &urlToGet)
{SDownloads temp;
    for(auto i=urlToGet.begin();i!=urlToGet.end();i++)
      {
        temp.path=*i;
        listDownloads.push_back(temp);
      }
getFiles();
control.flagControl=true;
control.countPrev=control.countRefresh+1;
if (!control.isRunning())control.start();
timer->start(2000);
}
//------------------------------------------------------------------------------------------------------
void WNetFtpClient::start(QStringList &listFiles)
{
  ftpGet->start(listFiles);
}

//-------------------------------------------------------------------------------------------------------------------------
 void WNetFtpClient::endDownloads()
 {
   if(dirListBig.size()==0)
     { emit endDownload();}
   else{sgetListFiles();}

 }
//-------------------------------------------------------------------------------------------------------------------------
void WNetFtpClient::createFtp(QString serv,QString login,QString passv,QString cd,QString dirSave)
{
  QDir  dirTo;
        if(dirTo.exists(dirSave)){}
                     else{dirTo.mkdir(dirSave);
                          if(dirTo.exists(dirSave)){}else return ;}
 ftpFiles.connectServ(serv,login,passv);
 ftpFiles.cdBegin=cd;
 ftpFiles.cd(cd);
 dirForSave=dirSave;
 toNet="ftp://"+login+":"+passv+"@"+serv+"/"+cd;
 ftpGet=new WNetworkFtp;
 connect(ftpGet,SIGNAL(emit10Obj(int,QStringList)),this,SLOT(downloadTen(int,QStringList)));
 connect(ftpGet,SIGNAL(allDownloads()),this,SLOT(endDownloads()));
 ftpGet->createFtp(dirForSave);
//connect(ftpGet,SIGNAL(allStoped(int,int,QStringList)),this,SLOT(downloadStop(int,int,QStringList)));
connect(&ftpFiles,SIGNAL(sFiles(int,QStringList)),this,SLOT(getListFrom(int,QStringList)));
connect(&ftpFiles,SIGNAL(sendError(int,QString)),this,SLOT(getError(int,QString)));
this->updateConnect.setInterval(5000);
//connect(&this->updateConnect,SIGNAL(timeout()),this,SLOT(sgetListFiles()));
connect(&ftpFiles,SIGNAL(errBeg()),this,SLOT(sgetListFiles()));
//connect(&ftpFiles,SIGNAL(errEnd()),&this->updateConnect,SLOT(stop()));



}

void WNetFtpClient::getListFiles(QStringList &dirList)
{
    dirListBig=dirList;
    itDirList=dirListBig.begin();
    ftpFiles.cd(*itDirList);
    ftpFiles.readCurrFiles();
   // ftpFiles.readDirectories();
}
//---------------------------------------------------------------------------------------------------
void WNetFtpClient::sgetListFiles(void)
{
   itDirList=dirListBig.begin();
    ftpFiles.cd(*itDirList);
    ftpFiles.readCurrFiles();
}
//----------------------------------------------------------------------------------------------------------
void WNetFtpClient::getListFrom(int err,QStringList list)
{
  for(auto it=list.begin();it!=list.end();it++)
    {
     toNetList.push_back(toNet+"/"+*itDirList+"/"+*it);
    }

  dirListBig.erase(itDirList);

QString itOldList=*itDirList;

 itDirList=dirListBig.begin();

    if(itDirList!=dirListBig.end()){
if(err==QFtp::NoError)
    { int size=0;
      qCount(itOldList,'/',size);//находим сколько раз необходимо вернуться
      ++size;
     for(int i=0;i<size;i++)
       {ftpFiles.cd("..");}
    }

if(toNetList.size()<200)
    {ftpFiles.cd(*itDirList);
     ftpFiles.readCurrFiles();}
    else{startLoad();return;}
    }
    else{startLoad();return;}
}
//-----------------------------------------------------------------------------------------------
 void WNetFtpClient::getError(int error,QString errorText)
 {
  // QString text=*itDirList;
  // int i=0;
 }
//-----------------------------------------------------------------------------------------------------------
void WNetFtpClient::cd(QString path)
{
if(path!=".."){toNet+="/"+path;}
               else{int pos=toNet.lastIndexOf("/");
                   toNet.resize(pos);}
ftpFiles.cd(path);
}
//-----------------------------------------------------------------------------------------------------------
void WNetFtpClient::destroyFtp()
{
delete ftpGet;
}

//--------------------------------------------------------------------------------------------------------
void WNetFtpClient::downloadProgress(QString name,qint64 getInf,qint64 totalInf)
{
  int i=0;
}
//-------------------------------------------------------------------------------------------------------------
