#ifndef FTPCLIENT_H
#define FTPCLIENT_H

#include "qftp/qftp.h";
#include <QFile>
#include <QList>
#include <qiterator.h>

#define CLOADFILES 1
#define CLOADCURRFILE 2
#define CLOADCURRDIR 3

struct SFilterStr
{
int i;
};

class WFtpFilter
{public:
 bool filter(QString urlFileName);
protected:
  SFilterStr stFilter;
};

class WFtpClient:public QObject,protected WFtpFilter
{Q_OBJECT
public:  
  WFtpClient();
  void setStFilter(SFilterStr toFilter){stFilter=toFilter;}
  void connectServ(QString serv,QString login,QString passv);//коннектится к ftp источнику
  void disconnectServ(void);//отключаем ftp
  void cd(QString cdFromNull);//переходим по указанной директории
  void readFiles(QString dirToSave);//читаем все файлы из неё и сохраняем на жесткий диск.
  void readDirectories(void);//читаем список всех директорий из текущего положения
  void readCurrFiles(void);//читаем список всех файлов
  void save(void);//сохраняем уже полученые файлы на жесткий диск
public slots:
  void doneURLInfo(QUrlInfo urlInfo);//слот получает список всех файлов
  void ftpConnected(bool hasError);//проверка на ошибки ftp;
  void commFinish(int id,bool hasBed);//окончание комманды
signals:
  void sendError(QString);//невозможно создать файл
  void endOperations(QStringList);
  void finished(QStringList);
protected:
QFtp *ftpLiders;
QList<QFile*> openedFiles;
QString dirSave;
int toLoad;
QStringList urlFiles;
int idCurr;
};

#endif // FTPCLIENT_H
