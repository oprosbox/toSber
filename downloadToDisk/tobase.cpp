#include "tobase.h"
#include <QSqlError>
#include "findindom.h"

WToBASE::WToBASE()
{

}
//------открывает локальное соединение с MSSql--------------------
bool WOpenBase::openMSSQL(QString url,QString database,QString login, QString pass)
{
    base = QSqlDatabase::addDatabase("QODBC", "dbPAO");
    base.setDatabaseName("Driver={SQL Server};"
    "Server="+url+";"
    "Database="+database+";"
    "Trusted_Connection=yes;");
    // "Server=LVVPC\\SQLEXPRESS;"
    //return base.open("lenV","oprosboxopros19");
   return base.open(login,pass);
}
//-------------------закрывает работающее соединение----------------------------
void WOpenBase::closeConn()
{
base.close();
QSqlDatabase::removeDatabase("dbPAO");
}
//-----------------------------------------------------------------------
void WToBASE::prepare()
{

  queryNotif->prepare("INSERT INTO NOTIFI223FZ(inn,name_organization,inn_supplier,name_organization_supplier,date,dateUTC,guid)"
                     "VALUES (:inn, :name, :inn_supplier, :name_supplier, :date,:dateUTC, :guid);");

  queryDishon->prepare("INSERT INTO DISHON223FZ (inn,name_organization,date_add,date_addUTC,guid)"
                      "VALUES (:inn, :name, :date_add,:date_addUTC, :guid);");

  queryNotifData->prepare("INSERT INTO NOTIFI223FZDATA (guid,data)"
                      "VALUES (:guid, :data);");

  queryDishonData->prepare("INSERT INTO DISHON223FZDATA (guid,data)"
                      "VALUES (:guid, :data);");

  queryNotifSelectData->prepare("SELECT data FROM NOTIFI223FZDATA WHERE (guid="
                               "(SELECT data_id FROM NOTIFI223FZ WHERE ((:inn=inn) AND (date_begin>:date_start) AND (date_begin>:date_stop))))");

  queryDishonSelectData->prepare("SELECT data FROM DISHON223FZDATA WHERE (guid="
                               "(SELECT data_id FROM DISHON223FZ WHERE (:inn=inn)));");

}
//----------------------------------------------------------------------
bool WToBASE::start(QString url,QString database,QString login, QString pass)
{   if(openMSSQL(url,database,login,pass))
    {queryNotif=new QSqlQuery(base);
    queryDishon=new QSqlQuery(base);
    queryNotifData=new QSqlQuery(base);
    queryDishonData=new QSqlQuery(base);
    queryNotifSelectData=new QSqlQuery(base);
    queryDishonSelectData=new QSqlQuery(base);
    return true;}
    return false;
}
//---------------------------------------------------------------------------------------------
void WToBASE::stop()
{if(base.isOpen())
    {delete queryNotif;
    delete queryDishon;
    delete queryNotifData;
    delete queryDishonData;
    delete queryNotifSelectData;
    delete queryDishonSelectData;
    closeConn();}
}
//---------------------------------------------------------------------------------------------------
bool WToBASE::createTable223Notif()
{
  queryNotif->prepare(
        "CREATE TABLE NOTIFI223FZ ("
        "id INTEGER PRIMARY KEY NOT NULL IDENTITY(1,1),"
        "inn varchar(20),"
        "name_organization varchar(3000),"
        "inn_supplier varchar(20),"
        "name_organization_supplier varchar(3000),"
        "date INTEGER,"
        "dateUTC varchar(20),"
        "guid varchar(50));"
        "CREATE TABLE NOTIFI223FZDATA ("
        "guid varchar(50) PRIMARY KEY,"
        "data varchar(MAX));"
       );
  if(!queryNotif->exec())return false;
 return true;
}
//------------------------------------------------------------------
bool WToBASE::createTable223Dishon()
{
  queryDishon->prepare(
        "CREATE TABLE DISHON223FZ ("
        "id INTEGER PRIMARY KEY NOT NULL IDENTITY(1,1),"
        "inn CHAR(20),"
        "name_organization varchar(3000),"
        "date_add INTEGER,"
        "date_addUTC varchar(20),"
        "guid varchar(50));"
        "CREATE TABLE DISHON223FZDATA ("
        "guid varchar(50) PRIMARY KEY,"
        "data varchar(MAX));"
       );
  if(!queryDishon->exec())return false;
  return true;
}
//------------------------------------------------------------------
bool WToBASE::insertToBase223Dishon(SDishon &dish)
{ //QSqlDatabase::database().transaction();
  queryDishon->bindValue(":inn", dish.inn);
  queryDishon->bindValue(":name", dish.name_organization);
  queryDishon->bindValue(":date_add", dish.date_add);
  queryDishon->bindValue(":date_addUTC", dish.date_addUTC);
  queryDishon->bindValue(":guid",dish.guid);
  if(!queryDishon->exec())return false;

  queryDishonData->bindValue(":guid", dish.guid);
  queryDishonData->bindValue(":data",dish.data);
  if(!queryDishonData->exec())return false;
 // QSqlDatabase::database().commit();
  return true;
}
//------------------------------------------------------------------
bool WToBASE::insertToBase223Notif(SNotif &notif,QSqlError &error)
{ //QSqlDatabase::database().transaction();
  queryNotif->bindValue(":inn", notif.inn);
  queryNotif->bindValue(":name", notif.name_organization);
  queryNotif->bindValue(":inn_supplier", notif.inn_supplier);
  queryNotif->bindValue(":name_supplier", notif.name_organization_supplier);
  queryNotif->bindValue(":date", notif.date);
  queryNotif->bindValue(":dateUTC", notif.dateUTC);
  queryNotif->bindValue(":guid",notif.guid);
  if(!queryNotif->exec()) {error=queryNotifData->lastError();return false;}

  queryNotifData->bindValue(":guid", notif.guid);
  queryNotifData->bindValue(":data",notif.data);
  if(!queryNotifData->exec()){error=queryNotifData->lastError();return false;}
  //QSqlDatabase::database().commit();
  return true;
}
//--------------------------------------------------------------------------------
bool WToBASE::selectNotif(int inn,QDateTime tmBegin,QDateTime tmEnd,QStringList &notif)
{ //QSqlDatabase::database().transaction();
  queryNotifSelectData->bindValue(":inn", inn);
  queryNotifSelectData->bindValue(":date_start", tmBegin.toTime_t());
  queryNotifSelectData->bindValue(":date_stop", tmEnd.toTime_t());
  if(queryNotifSelectData->exec())
  {
  QString data;
  notif.clear();
  while (queryNotifSelectData->next()) {
      data = queryNotifSelectData->value(0).toString();
      notif.push_back(data);
     }
 // QSqlDatabase::database().commit();
  return true;}
  return false;
}
//------------------------------------------------------------------------------
bool WToBASE::selectDishon(int inn,QStringList &dishon)
{// if(QSqlDatabase::database().transaction()){}
  queryDishonSelectData->bindValue(":inn", inn);
  if(queryDishonSelectData->exec())
  {
  QString data;
  dishon.clear();
  while (queryDishonSelectData->next()) {
      data = queryDishonSelectData->value(0).toString();
      dishon.push_back(data);
     }
 // QSqlDatabase::database().commit();
  return true;}
  return false;
}
//-------------------------------------------------------------------------------------------
bool WBaseWR::start(QString url,QString database,QString login, QString pass)
{
 bool flgOpen=WToBASE::start(url,database,login,pass);
if(flgOpen){prepare();}

return flgOpen;
}

//--------------------------------------------------------------------------------------------
bool WBaseWR::writeToNotif(QStringList findObjects)
{
QList<SNotif> lstNotif;
toSNotif(findObjects,lstNotif);
QSqlError error;
QString err;
for(auto i=lstNotif.begin();i!=lstNotif.end();i++)
  {
if(insertToBase223Notif(*i,error)){}
                    else{QString err=error.text();
                         int ou=0;}
  }
return true;
}
//---------------------------------------------------------------------------------------------
bool WBaseWR::writeToDishon(QStringList findObjects)
{
  QList<SDishon> lstDishon;
  toSDishon(findObjects,lstDishon);
  for(auto i=lstDishon.begin();i!=lstDishon.end();i++)
    {
  if(insertToBase223Dishon(*i)){}
                      else{return false;}
    }

  return true;
}
//---------------------------------------------------------------------------------------------
void WBaseWR::toSNotif(QStringList &list,QList<SNotif> &lstNotif)
{
  SNotif notif;
  lstNotif.clear();
  QStringList temp;
  for(auto i=list.begin();i!=list.end();i++)
    {
      notif.inn="";
      notif.data=*i;
      ndom::WFindInDom::findInText(*i,QStringList({"customer","mainInfo","inn"}),temp);
      if(temp.size()!=0){notif.inn=temp[0]; }

      ndom::WFindInDom::findInText(*i,QStringList({"customer","mainInfo","fullName"}),temp);
      if(temp.size()!=0){notif.name_organization=temp[0];}
                        else {notif.name_organization="";}

      ndom::WFindInDom::findInText(*i,QStringList({"supplierInfo","inn"}),temp);
      if(temp.size()!=0){notif.inn_supplier=temp[0]; }
                         else{notif.inn_supplier="";}

      ndom::WFindInDom::findInText(*i,QStringList({"supplierInfo","name"}),temp);
      if(temp.size()!=0){notif.name_organization_supplier=temp[0];}
      //else{ndom::WFindInDom::findInText(*i,QStringList({"contractInfo","supplierName"}),temp);
      //        if(temp.size()!=0) {notif.name_organization_supplier=temp[0];}
              else {notif.name_organization_supplier="";}

      ndom::WFindInDom::findInText(*i,QStringList({"contractDate"}),temp);
      if(temp.size()!=0){notif.dateUTC=temp[0];
                         QDateTime time=QDateTime::fromString(temp[0],"yyyy-MM-dd");
                         notif.date=time.toTime_t();}
                          else{notif.date=0;
                          notif.dateUTC="";
                          }

      ndom::WFindInDom::findInText(*i,QStringList({"header","guid"}),temp);
      if(temp.size()!=0){notif.guid=temp[0];}
                        else{notif.guid="";}

      if(notif.inn!="")lstNotif.push_back(notif);
    }
}
//---------------------------------------------------------------------------------------------
void WBaseWR::toSDishon(QStringList &list,QList<SDishon> &lstDish)
{
  for(auto i=list.begin();i!=list.end();i++)
    {

    }
}
