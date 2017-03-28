#ifndef FINDINDOM_H
#define FINDINDOM_H

#include <QDomDocument>
#include <QStringList>
#include <QThread>
#include <qiterator.h>

namespace ndom{

   const int CDELDIR=1;
   const int CNODELDIR=2;
   const int CEXPFILTER=2;
   const int CSTRFILTER=1;

 struct SListVal
 {
   QStringList path;
   QStringList value;
 };

class WFindInDom
{
public:
    WFindInDom();
    int findInDir(QString dirFrom, QString pathTo,QStringList &listFilesFind,int ndomDel);
    int findInDirExp(QString dirFrom, QString pathTo,QStringList &listFilesFind,int ndomDel);
    bool findInFileExp(QString path);
    bool findInFile(QString path,QList<SListVal> &val);
    bool findInFile(QString path,QStringList &val);
    bool findInFile(QString path);
    void setFindAttr(QStringList teg,QString val);
    void setFindAttr(QList<QRegExp> tegs,QString val);
    void setFindAttr(QList<QStringList> tegs);
protected:
    QStringList listNamesTeg;
    QList<QStringList> listOftegs;
    QList<QRegExp> tegsExp;
    QString valFind;
};

class WFindThr:public QThread
{Q_OBJECT
 public:
  int id;
  WFindInDom *findInDom;
  QStringList listDirFrom;
  QString pathTo;
  int clearAll;
  void run();
 signals:
  void threadStop(int);
  void findFiles(QStringList);
};

class WFindThrExp:public QThread
{Q_OBJECT
 public:
  int id;
  WFindInDom *findInDom;
  QStringList listDirFrom;
  QString pathTo;
  int clearAll;
  void run();
 signals:
  void threadStop(int);
  void findFiles(QStringList);
};

class WFind:public QObject
{Q_OBJECT
  public:
  int id;
  void createObj(QStringList listDirFrom,QString dirTo,QStringList teg,QString val,bool flgClearAll=false);
  void createObj(QStringList listDirFrom,QString dirTo,QList<QRegExp> teg,QString val,bool flgClearAll=false);
  void destroyObj();
  void startThreads();
  void stopThreads();
public slots:
  void getSignalStop(int);
  void allThreadsFormLists(QStringList list){emit allThreadsLists(list);}
signals:
  void allThreadsStop(int);
  void allThreadsLists(QStringList);
protected:
  QList<WFindThr*> listThr;
  QList<WFindThrExp*> listThrExp;
  int threadsWork;
  int countThr;
  int flgStart;

};

}
#endif // FINDINDOM_H
