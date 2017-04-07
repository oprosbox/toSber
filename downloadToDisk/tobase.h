#ifndef TOBASE_H
#define TOBASE_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QDateTime>



const int CFZ223=223;
const int CFZ44=44;

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
  QString inn_supplier;
  QString name_organization_supplier;
  int date;
  QString dateUTC;
  QString guid;
  QString data;
};
//-------------------------------------------------------------------------------
class WToBASE:public WOpenBase
{
public:
    WToBASE();
    void prepare(int CFZ);
    bool start(QString url,QString database,QString login, QString pass);
    void stop();
    bool createTable223Notif();
    bool insertToBase223Notif(SNotif &notif,QSqlError &error);
    bool createTable223Dishon();
    bool insertToBase223Dishon(SDishon &dishon);
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
    bool start(QString url,QString database,QString login, QString pass,const int CNoFZ);
static int createTables(bool table223fz=true,bool table44fz=true,bool tableDishon223fz=true,bool tableDishon44fz=true);
public slots:
bool writeToNotif(QStringList findObjects);
bool writeToDishon(QStringList findObjects);
//void createTables(void);
signals:
void getError(QString error);
protected:
void toSNotif(QStringList &list,QList<SNotif> &lstNotif);
void toSDishon(QStringList &list,QList<SDishon> &lstDish);
void toSNotif44(QStringList &list,QList<SNotif> &lstNotif);
void toSDishon44(QStringList &list,QList<SDishon> &lstDish);
int CFZType;
};

//-------------------------------------------------------------------------------
#endif // TOBASE_H
