#ifndef LOADSAVE_H
#define LOADSAVE_H

#include "ftpclient.h"
#include "fzunpack.h"
#include "findindom.h"


namespace ftpload{

class WLoadZip:public QObject,protected WPackUnpack7z
{ Q_OBJECT
public:
  int id;
  WLoadZip();
  void createLZ(QString dirUnpack,QString pathTo, QStringList tegPathFind, QString val);
  void startUnpack(QStringList listPathZip);//добавляет на обработку список zip и формирует в папке pathTo конечный список
  void fromDirToEnd(QStringList strList);//обрабатывает существующие директории
public slots:
  void  delObjThreads(int id);
signals:
 void allObjectsStop(int);
protected:
  QString tempDir;
  QString pathToEnd;
  QStringList tegFind;
  QString valFind;
  QList<ndom::WFind*> listThread;
  int countObj;
};

struct SInputFtp
{
 QStringList urlList;
 QString pathTemp;
 QString pathTo;
 QStringList tegPathFind;
 QString val;
 SFilterStr stFilt;
 int countToExitDirUrl;
};

class WLoadFtp:public QObject
{Q_OBJECT
public:
  WLoadFtp();
  ~WLoadFtp();
  void createFtp(SInputFtp);
public slots:
  void download();
  void nextLoad(QStringList getPath);
protected:
WLoadZip *fromZip;
WFtpClient *client;
QStringList urlListDirs;
QStringList::iterator it;
QString pathTempDownl;
int countToExit;
};











}

#endif // LOADSAVE_H
