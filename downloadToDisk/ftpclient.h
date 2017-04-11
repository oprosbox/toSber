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
#include <QTimer>
#include <list>
#include <algorithm>
#include <iterator>


#define CLOADCURRFILE 2
#define CLOADCURRDIR 3


class WNetworkFtp;

struct SFilterStr
{
QDateTime dateBegin;
QDateTime dateEnd;
QRegExp findExp;
QString formDateBg;
QString formDateEnd;
};
//-----------------------------------------------------------------------------------------------
class WFtpFilter
{public:
 bool filter(QString urlFileName);
protected:
  SFilterStr stFilter;
};
//------------------------------------------------------------------------------------------------
struct SDownloads
{
  QNetworkReply *reply;
  QString path;
};
//---------------------------------------------------------------------------------------------------
class PDel
{public:
    PDel(QNetworkReply *reply){downl=reply;}
 bool operator ()(SDownloads &man1)
{if(downl->objectName()==man1.reply->objectName())
     {return true;}
 return false ;
 }
 protected:
    QNetworkReply * downl;
};

class WTimerControl:public QThread
{
public:
    WNetworkFtp* ftp;
    bool flagWork;
    bool flagControl;
    int countRefresh;
    int countPrev;
    void run();

};

//---------------------------------------------------------------------------------------------------
class WNetworkFtp:public QObject
{Q_OBJECT
public:
    WNetworkFtp();
    ~WNetworkFtp();
  void createFtp(QString out);
  int getFile(SDownloads &urlFile);
  int getFiles(void);
  void start(QStringList &urlToGet);
  void abortAll();
  public slots:
  void finishRequest(QNetworkReply *in);
  void errors(QNetworkReply::NetworkError);
  void downloadProgress(qint64 recv,qint64 total);
  void finished(QNetworkReply* reply);
  void functTimer(void);
  void startNext();
signals:
 void emit10Obj(int err,QStringList listGet);
 void allDownloads();
 void errorEmit();
 //void downlProgress(QString,qint64,qint64);
protected:
  QNetworkReply * reply;
  QString outDir;
  QNetworkAccessManager  *manager;
  QEventLoop    *loop;
  QStringList urlToGetLocal;
  std::list<SDownloads> listDownloads;
  QStringList currNames;
  QTimer *timer;
  WTimerControl control;
  int countErr;
  int maxLoad;
};
//----------------------------------------------------------------------------------------------------
class WFtpClient:public QObject,protected WFtpFilter
{Q_OBJECT
public:  
  WFtpClient();
  void setStFilter(SFilterStr toFilter){stFilter=toFilter;countTimer=0;toLoad=-1;
                                         connect(&timer,SIGNAL(timeout()),this,SLOT(functTimer()));
                                         timer.start(2000); }
  int connectServ(QString serv,QString login,QString passv);//коннектится к ftp источнику
  void disconnectServ(void);//отключаем ftp
  void cd(QString cdFromNull);//переходим по указанной директории
  void readDirectories(void);//читаем список всех директорий из текущего положения
  void readCurrFiles(void);//читаем список всех файлов
  void save(void);//сохраняем уже полученые файлы на жесткий диск
  QString cdBegin;
public slots:
  void reconToHost();
  void doneURLInfo(QUrlInfo urlInfo);//слот получает список всех файлов
  void commFinish(int id,bool hasBed);//окончание комманды
  void functTimer();
signals:
  void sendError(int,QString);//невозможно создать файл
  void sFiles(int err,QStringList);
  void finished(QStringList);
  void finishedList(QStringList,QStringList);
  void errorTo();
  void errBeg(void);
  void errEnd(void);
protected:
QFtp *ftpLiders;
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
QTimer timer;
int countTimer;
};


class WNetFtpClient:public QObject
{ Q_OBJECT
public:
  void createFtp(QString serv,QString login,QString passv,QString cd,QString dirSave);
  void destroyFtp(void); 
  void getListFiles(QStringList &dirList);
  WFtpClient ftpFiles;
public slots:
  void sgetListFiles(void);
  void getListFrom(int err,QStringList);
  void downloadStop( int err,QStringList list){emit downStop(err,list);}
  void downloadTen(int err,QStringList list){emit downlTen(err,list);}
  void startLoad(void){start(toNetList);toNetList.clear();}
  void getError(int error,QString errorText);
  void downloadProgress(QString,qint64,qint64);
  void endDownloads(void);
  //void functTimer(void);
signals:
   void downStop(int,QStringList);
   void downlTen(int,QStringList);
   void endFormList(void);
   void endDownload(void);

protected:
   void cd(QString path);
   //void getListFiles(void);
   void start(QStringList &listUrl);
   WNetworkFtp *ftpGet;
  QString toNet;
  QString tempCd;
  QStringList toNetList;
  QString dirForSave;
  QStringList::iterator itDirList;
  QStringList dirListBig;
  QTimer updateConnect;
};


#endif // FTPCLIENT_H
