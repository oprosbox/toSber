#include "frombase.h"
#include "findindom.h"
#include <QSqlError>
//-----------------------------------------------------------------------
void WFromBASE::prepare()
{
  queryNotifSelectData->prepare("SELECT data FROM NOTIFI223FZDATA "
                                "WHERE (guid IN (SELECT guid FROM NOTIFI223FZ WHERE ((:inn=inn_supplier) AND (date>:date_start) AND (date<:date_stop))))");

  queryNotifSelectDataSimple->prepare("SELECT data FROM NOTIFI223FZDATA "
                                      "WHERE (guid IN (SELECT guid FROM NOTIFI223FZ WHERE ((date>:date_start) AND (date<:date_stop))));");

  queryDishonSelectData44->prepare("SELECT data FROM DISHON44FZDATA "
                                 " WHERE (:inn=inn);");

  queryDishonSelectData223->prepare("SELECT data FROM DISHON223FZDATA "
                                 " WHERE (:inn=inn);");

  queryContrDishData44->prepare( " SELECT data FROM NOTIFI223FZDATA "
                               " WHERE (guid IN (SELECT guid FROM NOTIFI223FZ WHERE (inn_supplier IN "
                               "                (SELECT inn FROM DISHON44FZDATA WHERE (inn<>''))))); ");

  queryContrDishData223->prepare( " SELECT data FROM NOTIFI223FZDATA "
                               " WHERE (guid IN (SELECT guid FROM NOTIFI223FZ WHERE (inn_supplier IN "
                               "                (SELECT inn FROM DISHON223FZDATA WHERE (inn<>''))))); ");


}
//----------------------------------------------------------------------
bool WFromBASE::start(void)
{   QString connStr=errorsLog.fromIniFile("dbConnString","Driver={SQL Server};"
                                                     "Server=LVVPC\\SQLEXPR;"
                                                     "Database=PAO_SB;"
                                                    "Uid=lenV;"
                                                     "Pwd=oprosboxopros19;");
    if(openMSSQL(connStr))
    {
    queryNotifSelectData=new QSqlQuery(base);
    queryDishonSelectData44=new QSqlQuery(base);
    queryDishonSelectData223=new QSqlQuery(base);
    queryNotifSelectDataSimple=new QSqlQuery(base);
    queryContrDishData44=new QSqlQuery(base);
    queryContrDishData223=new QSqlQuery(base);
    prepare();
    return true;}
    else{QString txt="base  con-58nect"+base.lastError().text();
        errorsLog.toLogFile(txt); }
    return false;
}
//------------------------------------------------------------------------------------------
void WFromBASE::stop()
{if(base.isOpen())
    {
    delete queryNotifSelectData;
    delete queryNotifSelectDataSimple;
    delete queryDishonSelectData44;
    delete queryDishonSelectData223;
    delete queryContrDishData44;
    delete queryDishonSelectData223;
    closeConn();}
}
//--------------------------------------------------------------------------------------------------
 bool WFromBASE::selectNotifDishon44(QStringList &notif)
 {

       if(queryContrDishData44->exec())
       {
       QString data;
       notif.clear();
       while (queryContrDishData44->next()) {
           data = queryContrDishData44->value(0).toString();
           notif.push_back(data);
          }
       return true;}
       return false;
 }

 //--------------------------------------------------------------------------------------------------
  bool WFromBASE::selectNotifDishon223(QStringList &notif)
  {

        if(queryContrDishData223->exec())
        {
        QString data;
        notif.clear();
        while (queryContrDishData223->next()) {
            data = queryContrDishData223->value(0).toString();
            notif.push_back(data);
           }
        return true;}
        return false;
  }

  //--------------------------------------------------------------------------------------------------
bool WFromBASE::selectNotifDishon44AND223(QStringList &notif)
 {
     if(queryContrDishData44->exec())
         {
         QString data;
         notif.clear();
         while (queryContrDishData44->next()) {
             data = queryContrDishData44->value(0).toString();
             notif.push_back(data);
            }
         if(queryContrDishData223->exec())
         {
         QString data;
         while (queryContrDishData223->next()) {
             data = queryContrDishData223->value(0).toString();
             notif.push_back(data);
            }
         return true;}
         }
         return false;
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
bool WFromBASE::selectDishon44(QString inn,QStringList &dishon)
{// if(QSqlDatabase::database().transaction()){}
  queryDishonSelectData44->bindValue(":inn", inn);
  if(queryDishonSelectData44->exec())
  {
  QString data;
  dishon.clear();
  while (queryDishonSelectData44->next()) {
      data = queryDishonSelectData44->value(0).toString();
      dishon.push_back(data);
     }
 // QSqlDatabase::database().commit();
  return true;}
  return false;
}
//------------------------------------------------------------------------------
bool WFromBASE::selectDishon223(QString inn,QStringList &dishon)
{// if(QSqlDatabase::database().transaction()){}
  queryDishonSelectData223->bindValue(":inn", inn);
  if(queryDishonSelectData223->exec())
  {
  QString data;
  dishon.clear();
  while (queryDishonSelectData223->next()) {
      data = queryDishonSelectData223->value(0).toString();
      dishon.push_back(data);
     }
 // QSqlDatabase::database().commit();
  return true;}
  return false;
}
//-------------------------------------------------------------------------------------------
bool WBaseRD::connectToBase()
{
bool flgOpen=start();
return flgOpen;
}
//-----------------------------------------------------------------------------------------------
void WBaseRD::getFromBase(SSelect &query,int type)
{
  QStringList xmlResult;

if(query.inn=="")
              {selectNotif(query.tmBegin,query.tmEnd,xmlResult);}
else if (query.inn=="getDishon")
              {switch(type)
               { case CFSD44:{selectNotifDishon44(xmlResult);break;}
                case CFSD223:{selectNotifDishon223(xmlResult);break;}
                case (CFSD44+CFSD223):{selectNotifDishon44AND223(xmlResult);}
                }
               }
         else {selectNotif(query.inn,query.tmBegin,query.tmEnd,xmlResult);}

    if(xmlResult.size()!=0)
       {
        toSNotifDishon(xmlResult,query.lstNotif,type);
       }
}
//-----------------------------------------------------------------------------------------------------
void WBaseRD::toSNotifDishon(QStringList &list,QList<SNotifDishon> &lstNotif,int typeFS)
{
  SNotifDishon dataStruct;
  QString out;
  QList<QStringList> listInn;
  listInn.push_back(QStringList({"customer","mainInfo","inn"}));
 QList<QStringList> listName;
  listName.push_back(QStringList({"customer","mainInfo","fullName"}));

  for(auto it=list.begin();it!=list.end();it++)
  {

      dataStruct.data=*it;

      ndom::WFindInDom::findInText(*it,listInn,dataStruct.inn);

      ndom::WFindInDom::findInText(*it,listName,dataStruct.name);

      ndom::WFindInDom::findInText(*it,QStringList({"supplierInfo","inn"}),dataStruct.inn_supp);

      ndom::WFindInDom::findInText(*it,QStringList({"supplierInfo","name"}),dataStruct.name_supp);

      ndom::WFindInDom::findInText(*it,QStringList({"subjectContract"}),dataStruct.subjectContract);

      ndom::WFindInDom::findInText(*it,QStringList({"contractDate"}),out);
      out.resize(10);
      dataStruct.date=QDateTime::fromString(out,"yyyy-MM-dd");

      ndom::WFindInDom::findInText(*it,QStringList({"header","guid"}),dataStruct.guid);


      toSDishon(dataStruct.inn_supp,dataStruct.dataDishonSuplier,typeFS);


      lstNotif.push_back(dataStruct);
  }

}
//-------------------------------------------------------------------------------------------------------------------
void WBaseRD::toSDishon(QString inn,QString &data,int typeFS)
{
    QStringList dishonList,dishonList1;
    switch (typeFS) {
    case CFSD44:{selectDishon44(inn,dishonList);break;}
    case CFSD223:{selectDishon223(inn,dishonList);break;}
    case (CFSD44+CFSD223):{selectDishon44(inn,dishonList);
                           selectDishon223(inn,dishonList1);
                           dishonList<<dishonList1;}
    }

if(dishonList.size()!=0)data=dishonList.back();
 else data="";
}
//--------------------------------------------------------------------------------------------------------------------
