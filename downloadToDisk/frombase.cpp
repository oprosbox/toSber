#include "frombase.h"
#include "findindom.h"
//-----------------------------------------------------------------------
void WFromBASE::prepare()
{
  queryNotifSelectData->prepare("SELECT data FROM NOTIFI223FZDATA "
                                "WHERE (guid IN (SELECT guid FROM NOTIFI223FZ WHERE ((:inn=inn_supplier) AND (date>:date_start) AND (date<:date_stop))))");

  queryNotifSelectDataSimple->prepare("SELECT data FROM NOTIFI223FZDATA "
                                      "WHERE (guid IN (SELECT guid FROM NOTIFI223FZ WHERE ((date>:date_start) AND (date<:date_stop))));");

  queryDishonSelectData->prepare("SELECT data FROM DISHON223FZDATA "
                                 "WHERE (guid IN (SELECT guid FROM DISHON223FZ WHERE (:inn=inn)));");

}
//----------------------------------------------------------------------
bool WFromBASE::start(QString url,QString database,QString login, QString pass)
{   if(openMSSQL(url,database,login,pass))
    {
    queryNotifSelectData=new QSqlQuery(base);
    queryDishonSelectData=new QSqlQuery(base);
    queryNotifSelectDataSimple=new QSqlQuery(base);
    prepare();
    return true;}
    return false;
}
//------------------------------------------------------------------------------------------
void WFromBASE::stop()
{if(base.isOpen())
    {
    delete queryNotifSelectData;
    delete queryNotifSelectDataSimple;
    delete queryDishonSelectData;
    closeConn();}
}
//--------------------------------------------------------------------------------
bool WFromBASE::selectNotif(QString inn,QDateTime tmBegin,QDateTime tmEnd,QStringList &notif)
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
bool WFromBASE::selectNotif(QDateTime tmBegin,QDateTime tmEnd,QStringList &notif)
{ //QSqlDatabase::database().transaction();
    int timeTemp= tmBegin.toTime_t();
  queryNotifSelectDataSimple->bindValue(":date_start",timeTemp);
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
bool WFromBASE::selectDishon(QString inn,QStringList &dishon)
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
bool WBaseRD::connectToBase(QString url,QString database,QString login, QString pass)
{bool flgOpen=start(url,database,login,pass);
return flgOpen;
}
//-----------------------------------------------------------------------------------------------
void WBaseRD::getFromBase(SSelect &query)
{
  QStringList xmlResult;
if(query.inn=="")
  {selectNotif(query.tmBegin,query.tmEnd,xmlResult);}
else{selectNotif(query.inn,query.tmBegin,query.tmEnd,xmlResult);}

    if(xmlResult.size()!=0)
       {toSNotifDishon(xmlResult,query.lstNotif);}
}
//-----------------------------------------------------------------------------------------------------
void WBaseRD::toSNotifDishon(QStringList &list,QList<SNotifDishon> &lstNotif)
{
  SNotifDishon dataStruct;
  QString out;
  for(auto it=list.begin();it!=list.end();it++)
  {

      dataStruct.data=*it;

      ndom::WFindInDom::findInText(*it,QStringList({"customer","mainInfo","inn"}),dataStruct.inn);

      ndom::WFindInDom::findInText(*it,QStringList({"customer","mainInfo","fullName"}),dataStruct.name);

      ndom::WFindInDom::findInText(*it,QStringList({"supplierInfo","inn"}),dataStruct.inn_supp);

      ndom::WFindInDom::findInText(*it,QStringList({"supplierInfo","name"}),dataStruct.name_supp);

      ndom::WFindInDom::findInText(*it,QStringList({"subjectContract"}),dataStruct.subjectContract);

      ndom::WFindInDom::findInText(*it,QStringList({"contractDate"}),out);
      dataStruct.date=QDateTime::fromString(out,"yyyy-MM-dd");

      ndom::WFindInDom::findInText(*it,QStringList({"header","guid"}),dataStruct.guid);

      toSDishon(dataStruct.inn_supp,dataStruct.dataDishonSuplier);

      lstNotif.push_back(dataStruct);
  }
}
//-------------------------------------------------------------------------------------------------------------------
void WBaseRD::toSDishon(QString inn,QString &data)
{
    QStringList dishonList;
selectDishon(inn,dishonList);
if(dishonList.size()!=0)data=dishonList.back();
 else data="";
}
//--------------------------------------------------------------------------------------------------------------------
