#ifndef FROMBASE_H
#define FROMBASE_H

#include "tobase.h"

const int CFSD223=223;
const int CFSD44=44;

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
    bool start(void);
    void stop();
    bool selectNotif(QString inn,QDateTime tmBegin,QDateTime tmEnd,QStringList &notif);
    bool selectNotif(QDateTime tmBegin,QDateTime tmEnd,QStringList &notif);
    bool selectNotifDishon44(QStringList &notif);
    bool selectNotifDishon223(QStringList &notif);
    bool selectNotifDishon44AND223(QStringList &notif);
    bool selectDishon44(QString inn,QStringList &dishon);
    bool selectDishon223(QString inn,QStringList &dishon);
protected:
 QSqlQuery *queryNotifSelectData;
 QSqlQuery *queryContrDishData44;
 QSqlQuery *queryContrDishData223;
 QSqlQuery *queryNotifSelectDataSimple;
 QSqlQuery *queryDishonSelectData44;
 QSqlQuery *queryDishonSelectData223;
};
//-------------------------------------------------------------------------------------
class WBaseRD:protected WFromBASE
{
public:
bool connectToBase(void);
void getFromBase(SSelect &query,int typeFSD);
protected:
void toSNotifDishon(QStringList &list,QList<SNotifDishon> &lstNotif,int typeFSD);
void toSDishon(QString inn,QString &date,int typeFSD);
};
//--------------------------------------------------------------------------------------------
#endif // FROMBASE_H
