#ifndef LOADSAVE_H
#define LOADSAVE_H

#include "ftpclient.h"
#include "fzunpack.h"
#include "findindom.h"
#include "tobase.h"


namespace ftpload{

const int CNODELDIRANDARH=0;
const int CDELDIRANDARH=1;
const int CDELARHNOPROCESS=2;
//-----------------------------------------------------------------------------------------------
class WLoadZip:public QObject,protected WPackUnpack7z
{ Q_OBJECT
public:
  int id;
  WLoadZip();
  void createLZ(QString dirUnpack,QString pathTo, QStringList tegPathFind, QString val,int idNew,int flgClear);
  void createLZ(QString dirUnpack,QString pathTo, QList<QRegExp> tegPathFind, QString val,int idNew,int flgClear);
  void startUnpackWork(QStringList listPathZip);
  void startUnpackFind(QStringList listPathZip);//добавляет на обработку список zip и формирует в папке pathTo конечный список
  void startUnpack(QStringList listPathZip);//добавляет на обработку список zip и формирует в папке pathTo конечный список
  void fromDirToEnd(QStringList strList);//обрабатывает существующие директории
  void setUnpack(QStringList listPathZip);
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
  QList<QRegExp> tegFindExp;
  QString valFind;
  QList<ndom::WFind*> listThread;
  QStringList listZip;
  int countObj;
  int countId;
  int flgClearAll;
};
//-------------------------------------------------------------------------------------------------
class WLoadZipThread:public QThread
{Q_OBJECT
 public:
 WLoadZipThread(){ //LoadZip.moveToThread(this);
                 }
  WLoadZip LoadZip;
  QStringList listPathZip;
 void run(){LoadZip.startUnpackWork(listPathZip);}
            //this->deleteLater();}
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
 QList<QRegExp> tegExpPathFind;
 QString val;
 SFilterStr stFilt;
 int countToExitDirUrl;
 int flgDellArh;
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
  void endLoad(void);
  void nextUnpack(int,QStringList files);
  void getProcessFiles(QStringList procFiles){emit sGetFiles(procFiles);}
  void delObjectThatStop(int id);
signals:
  void sGetFiles(QStringList);
  void getDownloadFiles(int err,QStringList files);
  void allFilesDownload(int);
  void allFilesProcess(int);
protected:
QList<WLoadZipThread*> fromZip;
WNetFtpClient *client;
QStringList::iterator it;
SInputFtp params;
int countId;
bool flgDownloadsAll;
};
//--------------------------------------------------------------------------------------------------

class W223fz
{
  public:
    W223fz();
    ~W223fz();
    void create223fzNotif(QString dirToReport,QStringList regions,QDateTime tmBegin,QDateTime tmEnd,QString inn);
    void create223fzDish(QString dirToReport,QStringList regions,QDateTime tmBegin,QDateTime tmEnd);
    int getRegions(QStringList &regions);
    WLoadFtp *ftp223fz;
protected:
    SInputFtp inpFtp;
    WBaseWR *BD;
};

}

#endif // LOADSAVE_H
