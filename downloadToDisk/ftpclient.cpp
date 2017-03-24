#include "ftpclient.h"

#include <QDir>
#include <QApplication>
#include <QDateTime>

#include <QFile>
#include <QTextStream>

WFtpClient::WFtpClient()
{
fileList = new QFile();
}

bool WFtpFilter::filter(QString url)
{
  int indUrl;
  indUrl=url.indexOf(QRegExp("[0-9]{8}_[0-9]{6}_[0-9]{8}_[0-9]{6}"),0);
  QString dateStrBeg;
  QString dateStrEnd;
  dateStrBeg.insert(0,url.data()+indUrl,15);
  dateStrEnd.insert(0,url.data()+indUrl+16,8);
  QDateTime dateBegin,dateEnd;
  dateBegin=QDateTime::fromString(dateStrBeg,"yyyyMMdd_HHmmss");
  dateEnd=QDateTime::fromString(dateStrEnd,"yyyyMMdd");

  if((stFilter.dateBegin<=dateBegin)&&(stFilter.dateEnd>=dateEnd))
    {return true;}
return false;
}

//-------------------------------коннектится к ftp источнику------------------------------------------------
int WFtpClient::connectServ(QString serv,QString login,QString passv)
{
  ftpLiders = new QFtp(this);
  connect(this,SIGNAL(errorTo()),this,SLOT(reconToHost()));
  connect(ftpLiders, SIGNAL(commandFinished(int,bool)), this, SLOT(commFinish(int,bool)));
  connect(ftpLiders, SIGNAL(listInfo(QUrlInfo)), this, SLOT(doneURLInfo(QUrlInfo)));
  connect(ftpLiders, SIGNAL(commandFinished(int,bool)), this, SLOT(ftpConnected(int,bool)));
  mserv=serv;
  mlogin=login;
  mpassv=passv;
  currCommGet=-1;
  ftpLiders->connectToHost(mserv);
  ftpLiders->login(mlogin,mpassv);
  return 1;
}
//----------------------------------окончание комманды--------------------------------------------------------
void WFtpClient::commFinish(int id,bool)
{
 if(id==idCurr){switch(toLoad)
                 {case CLOADCURRFILE:{emit sFiles(urlFiles);break;}
                   case CLOADLIST:{readList(urlFiles);}
                  }
               }
}
//------------------------------переходим по указанной директории------------------------------------------------------
void WFtpClient::cd(QString cdFromNull)
{
 ftpLiders->cd(cdFromNull);
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
                        emit sendError(dirSave+"/"+urlInfo.name());
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
  emit sendError(dirSave+"/"+*it);
  return;}
  QFile errorsN(QApplication::applicationDirPath()+"/errorsFtp.txt");
  if (!errorsN.open(QIODevice::WriteOnly)) {}
  listFilesAdd.push_back(*it);
  currCommGet=ftpLiders->get(*it, fileList);

}
//----------------------------------------------------------------------------------------
void WFtpClient::reconToHost(void)
{ QThread::usleep(100000);
  delete ftpLiders;
  int ret=connectServ(mserv,mlogin,mpassv);
  int yu=0;
}

//-------------------------------------------слот получает соединение-------------------------------------------
void WFtpClient::ftpConnected(int id,bool hasError)
{ if(hasError){QString err=ftpLiders->errorString();
               QFile errorsN(QApplication::applicationDirPath()+"/errorsFtp.txt");
               if (!errorsN.open(QIODevice::Append)) {}
                QTextStream out(&errorsN);
                out<<*it<<err;
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
                          emit sendError(dirSave+"/"+*it);
                          return;}
                          currCommGet=ftpLiders->get(*it, fileList);
                          listFilesAdd.push_back(*it);



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

int WNetworkFtp::getFile(QString urlFile, QString out)
{

 QUrl url(urlBegin+"/"+urlFile);
 reply =  manager.get(QNetworkRequest(url));
 QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
 loop.exec();
 if(reply->error()==QNetworkReply::NoError)
   { QFile  file(out);
     file.open(QIODevice::WriteOnly);
     file.write(reply->readAll());
   delete reply;}
 else
   {delete reply;
     return -1;}

 return 0;
}
//-------------------------------------------------------------------------------------------------
int WNetworkFtp::getFiles(QStringList urlFileIn, QString outDir,QStringList &urlFileOut)
 {urlFileOut.clear();
  for(auto i=urlFileIn.begin();i!=urlFileIn.end();i++)
    {
     if(getFile(*i,outDir+"/"+*i)!=-1){urlFileOut.push_back(*i);
                                       }else{return -1;}
    }
  return 0;
 }
//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void WNetworkFtp::createFtp(QString url)
{
 urlBegin= url;
 connect(&manager, SIGNAL(finished ( QNetworkReply *)), this, SLOT(finishRequest(QNetworkReply *)));
 }
//---------------------------------------------------------------------------------
void WNetworkFtp::finishRequest(QNetworkReply *Reply)
{

}
//---------------------------------------------------------------------------------------------------
void WNetworkFtpThread::run()
{
 // ftp.createFtp("ftp://fz223free:fz223free@ftp.zakupki.gov.ru/out/published/Moskva/purchaseNoticeZK/daily");
 // ftp.getFile("purchaseNoticeZK_Moskva_20170316_000000_20170316_235959_daily_001.xml.zip",QApplication::applicationDirPath()+"/"+"purchaseNoticeZK_Moskva_20170316_000000_20170316_235959_daily_001.xml.zip");
//  int i=0;

 QStringList fileGet;
 int err=ftp.getFiles(urlToGet,dirSave,fileGet);
 emit allStoped(id,err,fileGet);

}

void WNetFtpClient::start(QStringList listFiles)
{ ftpGet=new WNetworkFtpThread;
  connect(ftpGet,SIGNAL(allStoped(int,int,QStringList)),this,SLOT(downloadStop(int,int,QStringList)));
  ftpGet->dirSave=dirForSave;
  ftpGet->ftp.createFtp(toNet);
  ftpGet->urlToGet=listFiles;
  ftpGet->start();
}

void WNetFtpClient::getList()
{
ftpFiles.readCurrFiles();
}

void WNetFtpClient::createFtp(QString serv,QString login,QString passv,QString cd,QString dirSave)
{
  QDir  dirTo;
        if(dirTo.exists(dirSave)){}
                     else{dirTo.mkdir(dirSave);
                          if(dirTo.exists(dirSave)){}else return ;}
 ftpFiles.connectServ(serv,login,passv);
 ftpFiles.cd(cd);
 dirForSave=dirSave;
 toNet="ftp://"+login+":"+passv+"@"+serv+"/"+cd;
connect(&ftpFiles,SIGNAL(sFiles(QStringList)),this,SLOT(start(QStringList)));
}

void WNetFtpClient::cd(QString path)
{
if(path!=".."){toNet+="/"+path;}
               else{int pos=toNet.lastIndexOf("/");
                   toNet.resize(pos);}
ftpFiles.cd(path);
}

void WNetFtpClient::destroyFtp()
{

}
