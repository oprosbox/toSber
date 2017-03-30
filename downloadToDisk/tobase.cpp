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

  queryNotif->prepare("INSERT INTO NOTIFI223FZ (id,inn,name_organization,type_notif,date_begin,date_beginUTC,date_end,date_endUTC,data_id)"
                     "VALUES (:id, :inn, :name, :type, :date_begin,:date_beginUTC, :date_end, :date_endUTC, :data_id);");

  queryDishon->prepare("INSERT INTO DISHON223FZ (id,inn,name_organization,date_add,date_addUTC,data_id)"
                      "VALUES (:id, :inn, :name, :date_add,:date_addUTC, :data_id);");

  queryNotifData->prepare("INSERT INTO NOTIF223FZDATA (id_data,data)"
                      "VALUES (:id, :data);");

  queryDishonData->prepare("INSERT INTO DISHON223FZDATA (id_data,data)"
                      "VALUES (:id, :data);");

  queryNotifSelectData->prepare("SELECT data FROM NOTIFI223FZDATA WHERE (data_id="
                               "(SELECT data_id FROM NOTIFI223FZ WHERE ((:inn=inn) AND (date_begin>:date_start) AND (date_begin>:date_stop))))");

  queryDishonSelectData->prepare("SELECT data FROM DISHON223FZDATA WHERE (data_id="
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
//------------------------------------------------------------------
bool WToBASE::createTable223Notif()
{ //QSqlQuery* query=new QSqlQuery(base);
  queryNotif->prepare(
        "CREATE TABLE NOTIFI223FZ ("
        "id INTEGER PRIMARY KEY NOT NULL,"
        "inn CHAR(10),"
        "name_organization varchar(3000),"
        "type_notif CHAR(20),"
        "date_begin INTEGER,"
        "date_beginUTC varchar(20),"
        "date_end INTEGER,"
        "date_endUTC varchar(20),"
        "data_id CHAR(40));"
        "CREATE TABLE NOTIFI223FZDATA ("
        "data_id CHAR(40) PRIMARY KEY,"
        "data varchar(MAX));"
       );
  //bool flg=query->exec();
  if(!queryNotif->exec())return false;
 return true;
}
//------------------------------------------------------------------
bool WToBASE::createTable223Dishon()
{
  queryDishon->prepare(
        "CREATE TABLE DISHON223FZ ("
        "id INTEGER PRIMARY KEY NOT NULL,"
        "inn CHAR(10),"
        "name_organization varchar(3000),"
        "date_add INTEGER,"
        "date_addUTC varchar(20),"
        "data_id CHAR(40));"
        "CREATE TABLE DISHON223FZDATA ("
        "data_id CHAR(40) PRIMARY KEY,"
        "data varchar(MAX));"
       );
  if(!queryDishon->exec())return false;
  return true;
}
//------------------------------------------------------------------
bool WToBASE::insertToBase223Dishon(SDishon &dish)
{ //QSqlDatabase::database().transaction();
  queryDishon->bindValue(":inn", dish.inn);
  queryDishon->bindValue(":name_organization", dish.name_organization);
  queryDishon->bindValue(":date_add", dish.date_add);
  queryDishon->bindValue(":date_addUTC", dish.date_addUTC);
  queryDishon->bindValue(":data_id",dish.guid);
  if(!queryDishon->exec())return false;

  queryDishonData->bindValue(":data_id", dish.guid);
  queryDishonData->bindValue(":data",dish.data);
  if(!queryDishonData->exec())return false;
 // QSqlDatabase::database().commit();
  return true;
}
//------------------------------------------------------------------
bool WToBASE::insertToBase223Notif(SNotif &notif)
{ //QSqlDatabase::database().transaction();
  queryNotif->bindValue(":inn", notif.inn);
  queryNotif->bindValue(":name_organization", notif.name_organization);
  queryNotif->bindValue(":date_begin", notif.date_begin);
  queryNotif->bindValue(":date_beginUTC", notif.date_beginUTC);
  queryNotif->bindValue(":date_end", notif.date_begin);
  queryNotif->bindValue(":date_endUTC", notif.date_beginUTC);
  queryNotif->bindValue(":data_id",notif.guid);
  queryNotif->bindValue(":type_notif",notif.type_notif);
  if(!queryNotif->exec())return false;

  queryNotifData->bindValue(":data_id", notif.guid);
  queryNotifData->bindValue(":data",notif.data);
  if(!queryNotifData->exec())return false;
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
{bool flgOpen=openMSSQL(url,database,login,pass);
if(flgOpen){prepare();}

return flgOpen;
}



//--------------------------------------------------------------------------------------------
bool WBaseWR::writeToNotif(QStringList findObjects)
{
QList<SNotif> lstNotif;
toSNotif(findObjects,lstNotif);
for(auto i=lstNotif.begin();i!=lstNotif.end();i++)
  {
if(insertToBase223Notif(*i)){}
                    else{return false;}
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

      ndom::WFindInDom::findInText(*i,QStringList({"publicationDate"}),temp);
      if(temp.size()!=0){notif.date_beginUTC=temp[0];
                         QDateTime time=QDateTime::fromString(temp[0],"yyyy-MM-ddTHH:mm:ss");
                         notif.date_begin=time.toTime_t();}
                     else{notif.date_begin=0;
                          notif.date_beginUTC="";
                          }
//      ndom::WFindInDom::findInText(*i,QStringList({"summingupTime"}),temp);
//      if(temp.size()!=0){notif.date_endUTC=temp[0];
//                         QDateTime time=QDateTime::fromString(temp[0],"yyyy-MM-ddTHH:mm:ss");
//                         notif.date_end=time.toTime_t();}
//                        else{notif.date_endUTC="";
//                             notif.date_end=0;}

      ndom::WFindInDom::findInText(*i,QStringList({"purchaseCodeName"}),temp);
      if(temp.size()!=0){notif.type_notif=temp[0];}
                        else{notif.type_notif="";}
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
