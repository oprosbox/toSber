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
  queryNotifSelectData->prepare("SELECT data FROM NOTIFI223FZDATA WHERE (data_id="
                               "(SELECT data_id FROM NOTIFI223FZ WHERE ((:inn=inn) AND (date_begin>:date_start) AND (date_begin>:date_stop))))");

  queryNotifSelectDataSimple->prepare("SELECT data FROM NOTIFI223FZDATA WHERE (data_id="
                               "(SELECT data_id FROM NOTIFI223FZ WHERE ((date_begin>:date_start) AND (date_begin>:date_stop))))");

  queryDishonSelectData->prepare("SELECT data FROM DISHON223FZDATA WHERE (data_id="
                               "(SELECT data_id FROM DISHON223FZ WHERE (:inn=inn)));");

}
//----------------------------------------------------------------------
bool WToBASE::start(QString url,QString database,QString login, QString pass)
{   if(openMSSQL(url,database,login,pass))
    {
    queryNotifSelectData=new QSqlQuery(base);
    queryDishonSelectData=new QSqlQuery(base);
    queryNotifSelectDataSimple=new QSqlQuery(base);
    return true;}
    return false;
}

void WToBASE::stop()
{if(base.isOpen())
    {
    delete queryNotifSelectData;
    delete queryNotifSelectDataSimple;
    delete queryDishonSelectData;
    closeConn();}
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

//--------------------------------------------------------------------------------
bool WToBASE::selectNotif(QDateTime tmBegin,QDateTime tmEnd,QStringList &notif)
{ //QSqlDatabase::database().transaction();
  queryNotifSelectDataSimple->bindValue(":date_start", tmBegin.toTime_t());
  queryNotifSelectDataSimple->bindValue(":date_stop", tmEnd.toTime_t());
  if(queryNotifSelectDataSimple->exec())
  {
  QString data;
  notif.clear();
  while (queryNotifSelectDataSimple->next()) {
      data = queryNotifSelectDataSimple->value(0).toString();
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
bool WBaseRD::start(QString url,QString database,QString login, QString pass)
{bool flgOpen=openMSSQL(url,database,login,pass);
if(flgOpen){prepare();}

return flgOpen;
}
//-----------------------------------------------------------------------------------------------
void WBaseRD::getFrom(SSelect &query)
{
  QStringList xmlResult;

  if(query.innCustom==0){selectNotif(query.tmBegin,query.tmEnd,xmlResult);
                         if(xmlResult.size()!=0){toSNotifDishon(xmlResult,query.lstNotif);}
                        }
}
//---------------------------------------------------------------------------------------------
void WBaseRD::toSNotifDishon(QStringList &list,QList<SNotifDishon> &lstNotif)
{
  SNotifDishon notif;
  lstNotif.clear();
  QStringList temp;
  for(auto i=list.begin();i!=list.end();i++)
    {
      notif.inn=0;
      notif.data=*i;
      ndom::WFindInDom::findInText(*i,QStringList({"customer","mainInfo","inn"}),temp);
      if(temp.size()!=0){notif.inn=temp[0].toInt(); }

      ndom::WFindInDom::findInText(*i,QStringList({"customer","mainInfo","fullName"}),temp);
      if(temp.size()!=0){notif.name_organization=temp[0];}
                        else {notif.name_organization="";
                              continue;}

      ndom::WFindInDom::findInText(*i,QStringList({"publicationDateTime"}),temp);
      if(temp.size()!=0){notif.date_beginUTC=temp[0];
                         QDateTime time=QDateTime::fromString(temp[0],"yyyy-MM-ddTHH:mm:ss");
                         notif.date_begin=time.toTime_t();}
                     else{notif.date_begin=0;
                          notif.date_beginUTC="";
                          continue;}
      ndom::WFindInDom::findInText(*i,QStringList({"summingupTime"}),temp);
      if(temp.size()!=0){notif.date_endUTC=temp[0];
                         QDateTime time=QDateTime::fromString(temp[0],"yyyy-MM-ddTHH:mm:ss");
                         notif.date_end=time.toTime_t();}
                        else{notif.date_endUTC="";
                             notif.date_end=0;continue;}

      ndom::WFindInDom::findInText(*i,QStringList({"purchaseCodeName"}),temp);
      if(temp.size()!=0){notif.type_notif=temp[0];}
                        else{notif.type_notif="";continue;}

      ndom::WFindInDom::findInText(*i,QStringList({"header","guid"}),temp);
      if(temp.size()!=0){notif.guid=temp[0];}
                        else{notif.guid="";continue;}

      if(notif.inn!=0)lstNotif.push_back(notif);
    }
}
//---------------------------------------------------------------------------------------------
void WBaseRD::toSDishon(QStringList &list,QList<SDishon> &lstDish)
{
  for(auto i=list.begin();i!=list.end();i++)
    {

    }
}
