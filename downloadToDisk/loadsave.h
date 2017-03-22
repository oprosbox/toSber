#ifndef LOADSAVE_H
#define LOADSAVE_H

#include "ftpclient.h"
#include "fzunpack.h"
#include "findindom.h"


namespace ftpload{
//-----------------------------------------------------------------------------------------------
class WLoadZip:public QObject,protected WPackUnpack7z
{ Q_OBJECT
public:
  int id;
  WLoadZip();
  void createLZ(QString dirUnpack,QString pathTo, QStringList tegPathFind, QString val,int idNew,bool flgClear);
  void startUnpack(QStringList listPathZip);//добавляет на обработку список zip и формирует в папке pathTo конечный список
  void fromDirToEnd(QStringList strList);//обрабатывает существующие директории
public slots:
  void  delObjThreads(int id);
  void  formListFiles(QStringList);
signals:
 void allObjectsStop(int);
 void signAddFiles(QStringList);
protected:
  QString tempDir;
  QString pathToEnd;
  QStringList tegFind;
  QString valFind;
  QList<ndom::WFind*> listThread;
  QStringList listZip;
  int countObj;
  int countId;
  bool flgClearAll;
};
//-------------------------------------------------------------------------------------------------
class WLoadZipThread:public QThread
{
 public:
  ~WLoadZipThread(){terminate();delete LoadZip;}
  WLoadZip *LoadZip;
  QStringList listPathZip;
 void run(){LoadZip->startUnpack(listPathZip);}
};
//--------------------------------------------------------------------------------------------------
struct SInputFtp
{QString url;
 QString login;
 QString password;
 QString urlPath;
 QStringList urlList;
 QString pathTemp;
 QString pathTo;
 QStringList tegPathFind;
 QString val;
 SFilterStr stFilt;
 int countToExitDirUrl;
 bool flgDellArh;
};
//---------------------------------------------------------------------------------------------------
class WLoadFtp:public QObject
{Q_OBJECT
public:
  WLoadFtp();
  ~WLoadFtp();
  int createFtp(SInputFtp inpFtp);
  int id;
public slots:
  void download();
  void nextLoad(QStringList getPath,QStringList errors);
  void getProcessFiles(QStringList procFiles){sProcessFiles(procFiles);}
  void delObjectThatStop(int id);
signals:
  void sProcessFiles(QStringList);
  void getDownloadFiles(QStringList files,QStringList errors);
  void allFilesDownload(int);
  void allFilesProcess(int);
protected:
QList<WLoadZipThread*> fromZip;
WFtpClient *client;
QStringList::iterator it;
SInputFtp params;
int countId;
bool flgDownloadsAll;
};
//--------------------------------------------------------------------------------------------------
}

#endif // LOADSAVE_H
