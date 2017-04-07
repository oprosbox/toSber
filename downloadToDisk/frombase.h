#ifndef FROMBASE_H
#define FROMBASE_H

#include "tobase.h"

//-------------------------------------------------------------------------------
struct SNotifDishon
{
  QString inn;
  QString name;
  QString inn_supp;
  QString name_supp;
  QString subjectContract;
  QDateTime date;
  QString guid;
  QString data;
  QString dataDishonSuplier;
};
//-----------------------------------------------------------------------------------------
struct SSelect
{
 QList<SNotifDishon> lstNotif;
 QDateTime tmBegin;
 QDateTime tmEnd;
 QString inn;
};

//-------------------------------------------------------------------------------
class WFromBASE:public WOpenBase
{
public:
    WFromBASE(){}
    void prepare();
    bool start(QString url,QString database,QString login, QString pass);
    void stop();
    bool selectNotif(QString inn,QDateTime tmBegin,QDateTime tmEnd,QStringList &notif);
    bool selectNotif(QDateTime tmBegin,QDateTime tmEnd,QStringList &notif);
    bool selectNotifDishon(QStringList &notif);
    bool selectDishon(QString inn,QStringList &dishon);
protected:
 QSqlQuery *queryNotifSelectData;
 QSqlQuery *queryContrDishData;
 QSqlQuery *queryNotifSelectDataSimple;
 QSqlQuery *queryDishonSelectData;
};
//-------------------------------------------------------------------------------------
class WBaseRD:protected WFromBASE
{
public:
bool connectToBase(QString url,QString database,QString login, QString pass);
void getFromBase(SSelect &query);
protected:
void toSNotifDishon(QStringList &list,QList<SNotifDishon> &lstNotif);
void toSDishon(QString inn,QString &date);
};
//--------------------------------------------------------------------------------------------
#endif // FROMBASE_H
