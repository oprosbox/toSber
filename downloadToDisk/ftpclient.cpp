#include "ftpclient.h"

#include <QDir>
#include <QApplication>
#include <QDateTime>

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
  connect(ftpLiders, SIGNAL(commandFinished(int,bool)), this, SLOT(commFinish(int,bool)));
  connect(ftpLiders, SIGNAL(listInfo(QUrlInfo)), this, SLOT(doneURLInfo(QUrlInfo)));
  connect(ftpLiders, SIGNAL(done(bool)), this, SLOT(ftpConnected(bool)));
  int conn=ftpLiders->connectToHost(serv);
  if(conn!=-1)conn=ftpLiders->login(login,passv);
  return conn;
}
//----------------------------------окончание комманды--------------------------------------------------------
void WFtpClient::commFinish(int id,bool)
{
 if(id==idCurr){switch(toLoad)
                 {case CLOADCURRFILE:{ emit endOperations(urlFiles);break;}
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
                                             {urlFiles.push_back(urlInfo.name());}
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

  listFilesAdd.push_back(*it);

  ftpLiders->get(*it, fileList);

}

//-------------------------------------------слот получает соединение-------------------------------------------
void WFtpClient::ftpConnected(bool hasError)
{
   switch (toLoad)
     {case CLOADFILES:{QStringList filename;
                       for (int i = 0; i < (int)openedFiles.size(); ++i)
                       {filename.push_back(openedFiles.at(i)->fileName());
                        delete openedFiles[i];
                        }
                        emit finished(filename);
                        break;}
      case CLOADLIST:{ fileList->close();
                        do{++it;}
                        while((it!=listFiles.end())&&(!filter(*it)));
                        if(hasError){FileListErrors.push_back( ftpLiders->errorString().replace("\n", " "));}
                                else{FileListErrors.push_back("good");}
                         if(it!=listFiles.end()){}else{toLoad=-1;
                                                       emit finishedList(listFilesAdd,FileListErrors);
                                                       return;}
                          fileList->setFileName(dirSave+"/"+*it);
                          if (!fileList->open(QIODevice::WriteOnly)) {
                          emit sendError(dirSave+"/"+*it);
                          return;}
                          listFilesAdd.push_back(*it);
                         ftpLiders->get(*it, fileList);
                       }
     }
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
  save();
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
