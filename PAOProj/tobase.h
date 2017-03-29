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
  int inn;
  QString name_organization;
  int date_add;
  QString date_addUTC;
  QString guid;
  QString data;
};
//-------------------------------------------------------------------------------
struct SNotifDishon
{
  int inn;
  QString name_organization;
  QString type_notif;
  int date_begin;
  QString date_beginUTC;
  int date_end;
  QString date_endUTC;
  QString guid;
  QString data;
  QStringList dataDishon;
};

struct SSelect
{
 QList<SNotifDishon> lstNotif;
 QDateTime tmBegin;
 QDateTime tmEnd;
 int innCustom;
};

//-------------------------------------------------------------------------------
class WToBASE:public WOpenBase
{
public:
    WToBASE();
    void prepare();
    bool start(QString url,QString database,QString login, QString pass);
    void stop();
    bool selectNotif(int inn,QDateTime tmBegin,QDateTime tmEnd,QStringList &notif);
    bool selectNotif(QDateTime tmBegin,QDateTime tmEnd,QStringList &notif);
    bool selectDishon(int inn,QStringList &dishon);
protected:
 QSqlQuery *queryNotifSelectData;
 QSqlQuery *queryNotifSelectDataSimple;
 QSqlQuery *queryDishonSelectData;
};

class WBaseRD:protected WToBASE
{
public:
bool start(QString url,QString database,QString login, QString pass);
void getFrom(SSelect &query);
protected:
void toSNotifDishon(QStringList &list,QList<SNotifDishon> &lstNotif);
void toSDishon(QStringList &list,QList<SDishon> &lstDish);
};

//-------------------------------------------------------------------------------
#endif // TOBASE_H
