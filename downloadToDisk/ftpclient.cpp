#include "ftpclient.h"

#include <QDir>
#include <QApplication>
#include <QtGlobal>

WFtpClient::WFtpClient()
{

}

bool WFtpFilter::filter(QString url)
{

return false;
}

//-------------------------------коннектится к ftp источнику------------------------------------------------
void WFtpClient::connectServ(QString serv,QString login,QString passv)
{
  ftpLiders = new QFtp(this);
  connect(ftpLiders, SIGNAL(commandFinished(int,bool)), this, SLOT(commFinish(int,bool)));
  connect(ftpLiders, SIGNAL(listInfo(QUrlInfo)), this, SLOT(doneURLInfo(QUrlInfo)));
  connect(ftpLiders, SIGNAL(done(bool)), this, SLOT(ftpConnected(bool)));
  ftpLiders->connectToHost(serv);
  ftpLiders->login(login,passv);
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
  fileList = new QFile(dirSave+"/"+*it);
  if(filter(*it))ftpLiders->get(*it, fileList);
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
      case CLOADLIST:{ delete fileList;
                        do{++it;}
                        while((it!=listFiles.end())&&(!filter(*it)));
                        if(hasError){FileListErrors.push_back( ftpLiders->errorString().replace("\n", " "));}
                                else{FileListErrors.push_back("");}
                         if(it!=listFiles.end()){}else{emit finishedList(listFiles,FileListErrors);
                                                  return;}
                          fileList = new QFile(dirSave+"/"+*it);
                         if(filter(*it))ftpLiders->get(*it, fileList);
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

void  WFtpClient::readFilesPosledov(QString dirToSave)
{
    toLoad=CLOADLIST;
    urlFiles.clear();
    idCurr=ftpLiders->list();
}
