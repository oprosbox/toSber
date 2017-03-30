#ifndef TOBASE_H
#define TOBASE_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QDateTime>
//-------------------------------------------------------------------------------
class WOpenBase
{
public:
  // bool openMySQL();//открывает удаленное соединение с MySql
   bool openMSSQL(QString url,QString database,QString login, QString pass);//открывает соединение с MSSql
   void closeConn();//закрывает работающее соединение
   QSqlDatabase base;
};
//-------------------------------------------------------------------------------
struct SDishon
{
  QString inn;
  QString name_organization;
  int date_add;
  QString date_addUTC;
  QString guid;
  QString data;
};
//-------------------------------------------------------------------------------
struct SNotif
{
  QString inn;
  QString name_organization;
  QString type_notif;
  int date_begin;
  QString date_beginUTC;
  int date_end;
  QString date_endUTC;
  QString guid;
  QString data;
};
//-------------------------------------------------------------------------------
class WToBASE:public WOpenBase
{
public:
    WToBASE();
    void prepare();
    bool start(QString url,QString database,QString login, QString pass);
    void stop();
    bool createTable223Notif();
    bool insertToBase223Notif(SNotif &notif);
    bool createTable223Dishon();
    bool insertToBase223Dishon(SDishon &dishon);
    bool selectNotif(int inn,QDateTime tmBegin,QDateTime tmEnd,QStringList &notif);
    bool selectDishon(int inn,QStringList &dishon);
protected:
 QSqlTableModel toViewTable;
 QSqlQuery *queryNotif;
 QSqlQuery *queryDishon;
 QSqlQuery *queryNotifData;
 QSqlQuery *queryDishonData;
 QSqlQuery *queryNotifSelectData;
 QSqlQuery *queryDishonSelectData;
};

class WBaseWR:public QObject,protected WToBASE
{Q_OBJECT
public:
bool start(QString url,QString database,QString login, QString pass);
public slots:
bool writeToNotif(QStringList findObjects);
bool writeToDishon(QStringList findObjects);
protected:
void toSNotif(QStringList &list,QList<SNotif> &lstNotif);
void toSDishon(QStringList &list,QList<SDishon> &lstDish);
};

//-------------------------------------------------------------------------------
#endif // TOBASE_H
