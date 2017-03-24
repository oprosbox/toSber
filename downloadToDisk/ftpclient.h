#ifndef FTPCLIENT_H
#define FTPCLIENT_H

#include "qftp/qftp.h";
#include <QFile>
#include <QList>
#include <qiterator.h>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QNetworkReply>
#include <QThread>

#define CLOADFILES 1
#define CLOADCURRFILE 2
#define CLOADCURRDIR 3
#define CLOADLIST 4

struct SFilterStr
{
QDateTime dateBegin;
QDateTime dateEnd;
};

class WFtpFilter
{public:
 bool filter(QString urlFileName);
protected:
  SFilterStr stFilter;
};

class WNetworkFtp:public QObject
{Q_OBJECT
public:
  void createFtp(QString url);

  int getFile(QString urlFile, QString out);
  int getFiles(QStringList urlFileIn, QString outDir,QStringList &urlFileOut);
  QNetworkAccessManager  manager;
  QEventLoop    loop;
  public slots:
  void finishRequest(QNetworkReply *in);
protected:
  QNetworkReply * reply;
  QString urlBegin;
};
//--------------------------------------------------------------------------------------------------
class WNetworkFtpThread:public QThread
{ Q_OBJECT
public:
  WNetworkFtpThread(){ftp.manager.moveToThread(this);
                      ftp.loop.moveToThread(this);}
  int id;
  WNetworkFtp ftp;
  QStringList urlToGet;
  QString dirSave;
  void run();
 public slots:
 signals:
  void allStoped(int id,int err,QStringList listGet);
};

//----------------------------------------------------------------------------------------------------
class WFtpClient:public QObject,protected WFtpFilter
{Q_OBJECT
public:  
  WFtpClient();
  void setStFilter(SFilterStr toFilter){stFilter=toFilter;}
  int connectServ(QString serv,QString login,QString passv);//коннектится к ftp источнику
  void disconnectServ(void);//отключаем ftp
  void cd(QString cdFromNull);//переходим по указанной директории
  void readFiles(QString dirToSave);//читаем все файлы из неё и сохраняем на жесткий диск.
  int readFilesPosledov(QString dirToSave);
  void readList(QStringList listFiles);
  void readDirectories(void);//читаем список всех директорий из текущего положения
  void readCurrFiles(void);//читаем список всех файлов
  void save(void);//сохраняем уже полученые файлы на жесткий диск
QFtp *ftpLiders;
public slots:
  void reconToHost();
  void doneURLInfo(QUrlInfo urlInfo);//слот получает список всех файлов
  void ftpConnected(int id,bool hasError);//проверка на ошибки ftp;
  void commFinish(int id,bool hasBed);//окончание комманды
signals:
  void sendError(QString);//невозможно создать файл
  void sFiles(QStringList);
  void finished(QStringList);
  void finishedList(QStringList,QStringList);
  void errorTo();
protected:
//QFtp *ftpLiders;
QList<QFile*> openedFiles;
QString dirSave;
int toLoad;
QStringList urlFiles;
int idCurr;
QStringList::iterator it;
QFile *fileList;
QStringList FileListErrors;
QStringList listFiles;
QStringList listFilesAdd;
QString mserv;
QString mlogin;
QString mpassv;
int currCommGet;
};


class WNetFtpClient:public QObject
{ Q_OBJECT
public:
  void createFtp(QString serv,QString login,QString passv,QString cd,QString dirSave);
  void destroyFtp(void);
  void getList(void);
  void cd(QString path);
  WFtpClient ftpFiles;
  WNetworkFtpThread *ftpGet;
public slots:
  void start(QStringList);
  void downloadStop(int id, int err,QStringList list){emit downStop(id,err,list);}
signals:
   void downStop(int, int,QStringList);
protected:
  QString toNet;
  QString dirForSave;

};

#endif // FTPCLIENT_H
