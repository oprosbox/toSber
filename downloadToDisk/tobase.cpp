#include "tobase.h"
#include <QSqlError>
#include "findindom.h"
#include <QFile>



//----------------------------------------------------------------------------------------------------------------
WToBASE::WToBASE()
{

}
int paramConn=0;
//------открывает локальное соединение с MSSql--------------------
bool WOpenBase::openMSSQL(QString connStr)
{ QString nameConn="ODBCPAO_";
    nameConn+=QString::asprintf("%i",paramConn);
    ++paramConn;
    base = QSqlDatabase::addDatabase("QODBC",nameConn);
    base.setDatabaseName(connStr);
   return base.open();
}
//-------------------закрывает работающее соединение----------------------------
void WOpenBase::closeConn()
{
base.close();
QSqlDatabase::removeDatabase("dbPAO");
}
//------------------подготавливает запросы--------------------------------
void WToBASE::prepare(int CFZ)
{  switch(CFZ)
 { case CFZ223:{
  queryNotif->prepare("INSERT INTO NOTIFI223FZ(inn,name_organization,inn_supplier,name_organization_supplier,date,dateUTC,guid)"
                     "VALUES (:inn, :name, :inn_supplier, :name_supplier, :date,:dateUTC, :guid);");

  queryNotifData->prepare("INSERT INTO NOTIFI223FZDATA (guid,data)"
                      "VALUES (:guid, :data);");

  queryDishonData->prepare("INSERT INTO DISHON223FZDATA (inn,name,data)"
                      "VALUES (:inn, :name, :data);");

  queryNotifSelectData->prepare(//"DROP TABLE NOTIFI223FZ;"
                                //"DROP TABLE NOTIFI223FZDATA;"
        "CREATE TABLE NOTIFI223FZ ("
        "inn varchar(20),"
        "name_organization varchar(3000),"
        "inn_supplier varchar(20),"
        "name_organization_supplier varchar(3000),"
        "date INTEGER,"
        "dateUTC varchar(20),"
        "guid varchar(50) PRIMARY KEY NOT NULL);"
        "CREATE TABLE NOTIFI223FZDATA ("
        "guid varchar(50) PRIMARY KEY NOT NULL,"
        "data varchar(MAX));"
       );

  queryDishonSelectData->prepare(
        "CREATE TABLE DISHON223FZDATA ("
        "id INTEGER PRIMARY KEY NOT NULL IDENTITY(1,1),"
        "inn varchar(20),"
        "name varchar(3000),"
        "data varchar(MAX));"
       );
     break;}
    case CFZ44:{queryNotif->prepare("INSERT INTO CONTRACT44FZ(inn,name_organization,inn_supplier,name_organization_supplier,date,dateUTC,idContract)"
                                   "VALUES (:inn, :name, :inn_supplier, :name_supplier, :date,:dateUTC, :guid);");

                queryNotifData->prepare("INSERT INTO CONTRACT44FZDATA (idContract,data)"
                                    "VALUES (:guid, :data);");

                queryDishonData->prepare("INSERT INTO DISHON44FZDATA (inn,name,data)"
                                    "VALUES (:inn, :name, :data);");

                queryNotifSelectData->prepare(
                      "CREATE TABLE CONTRACT44FZ ("
                      "inn varchar(20),"
                      "name_organization varchar(3000),"
                      "inn_supplier varchar(20),"
                      "name_organization_supplier varchar(3000),"
                      "date INTEGER,"
                      "dateUTC varchar(20),"
                      "idContract varchar(50) PRIMARY KEY NOT NULL);"
                      "CREATE TABLE CONTRACT44FZDATA ("
                      "idContract varchar(50) PRIMARY KEY NOT NULL,"
                      "data varchar(MAX));"
                     );

                queryDishonSelectData->prepare(
                      "CREATE TABLE DISHON44FZDATA ("
                      "id INTEGER PRIMARY KEY NOT NULL IDENTITY(1,1),"
                      "inn varchar(20),"
                      "name varchar(3000),"
                      "data varchar(MAX));"
                     );break;}
    }

}
//----------------------------------------------------------------------
bool WToBASE::start()
{   QString connStr=errorsLog.fromIniFile("dbConnString","Driver={SQL Server};"
                                                     "Server=LVVPC\\SQLEXPR;"
                                                     "Database=PAO_SB;"
                                                    "Uid=lenV;"
                                                     "Pwd=oprosboxopros19;");
    if(openMSSQL(connStr))
    {queryNotif=new QSqlQuery(base);
    queryNotifData=new QSqlQuery(base);
    queryDishonData=new QSqlQuery(base);
    queryNotifSelectData=new QSqlQuery(base);
    queryDishonSelectData=new QSqlQuery(base);
    return true;}
    else{QString txt="base  connect"+base.lastError().text();
              errorsLog.toLogFile(txt); }
    return false;
}
//---------------------------------------------------------------------------------------------
void WToBASE::stop()
{if(base.isOpen())
    {delete queryNotif;
    delete queryNotifData;
    delete queryDishonData;
    delete queryNotifSelectData;
    delete queryDishonSelectData;
    closeConn();}
}
//---------------------------------------------------------------------------------------------------
bool WToBASE::createTable223Notif()
{

  if(!queryNotifSelectData->exec()){ QString txt="base create  notifTable"+queryNotifSelectData->lastError().text();
                           errorsLog.toLogFile(txt); return false;}
 return true;
}
//------------------------------------------------------------------
bool WToBASE::createTable223Dishon()
{

  if(!queryDishonSelectData->exec()){ QString txt="base create  dishonTable: "+queryDishonSelectData->lastError().text();
                            errorsLog.toLogFile(txt); return false;}
  return true;
}
//------------------------------------------------------------------
bool WToBASE::insertToBase223Dishon(SDishon &dish)
{

  queryDishonData->bindValue(":inn", dish.inn);
  queryDishonData->bindValue(":name",dish.name_organization);
  queryDishonData->bindValue(":data",dish.data);
  if(!queryDishonData->exec()){ QString txt="base write  queryDishonData: "+queryDishonData->lastError().text();
                                errorsLog.toLogFile(txt); return false;}
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
  if(!queryNotif->exec()){ QString txt="base write  queryNotif: "+queryNotif->lastError().text();
                           errorsLog.toLogFile(txt); return false;}

  queryNotifData->bindValue(":guid", notif.guid);
  queryNotifData->bindValue(":data",notif.data);
  if(!queryNotifData->exec()){ QString txt="base write  queryNotifData: "+queryNotifData->lastError().text();
                              errorsLog.toLogFile(txt); return false;}
  //QSqlDatabase::database().commit();
  return true;
}

//-------------------------------------------------------------------------------------------
bool WBaseWR::start(int CNoFZ)
{CFZType=CNoFZ;
 bool flgOpen=WToBASE::start();
if(flgOpen){prepare(CFZType);}

return flgOpen;
}

//--------------------------------------------------------------------------------------------
bool WBaseWR::writeToNotif(QStringList findObjects)
{
QList<SNotif> lstNotif;
switch(CFZType)
{case CFZ223:{ toSNotif(findObjects,lstNotif);break;}
 case CFZ44:{ toSNotif44(findObjects,lstNotif);}
}
QSqlError error;
for(auto i=lstNotif.begin();i!=lstNotif.end();i++)
  {
if(insertToBase223Notif(*i,error)){}
                    else{QString err="write  223Notif";
                         emit getError(err);}
  }
return true;
}
//---------------------------------------------------------------------------------------------
bool WBaseWR::writeToDishon(QStringList findObjects)
{
  QList<SDishon> lstDishon;
  toSDishon(findObjects,lstDishon);
  switch(CFZType)
  {case CFZ223:{ toSDishon(findObjects,lstDishon);break;}
   case CFZ44:{ toSDishon44(findObjects,lstDishon);}
  }

  for(auto i=lstDishon.begin();i!=lstDishon.end();i++)
    {
  if(insertToBase223Dishon(*i)){}
                      else{ QString err="write  223Dishon";
                            emit getError(err);}
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
      ndom::WFindInDom::findInText(*i,QStringList({"header","guid"}),temp);
      if(temp.size()!=0){notif.guid=temp[0];}
                        else{notif.guid="";
                             errorsLog.toErrReportFile(*i,"logReports223/header_guid.xml");
                                       continue;}

      ndom::WFindInDom::findInText(*i,QStringList({"customer","mainInfo","inn"}),temp);
      if(temp.size()!=0){notif.inn=temp[0];
                         notif.inn.replace(" ","");}
      if(notif.inn==""){errorsLog.toErrReportFile(*i,"logReports223/customer_mainInfo_inn.xml");
                        continue;}

      ndom::WFindInDom::findInText(*i,QStringList({"customer","mainInfo","fullName"}),temp);
      if(temp.size()!=0){notif.name_organization=temp[0];}
                        else {notif.name_organization="";
                              errorsLog.toErrReportFile(*i,"logReports223/customer_mainInfo_fullName.xml");
                                       continue;}

      ndom::WFindInDom::findInText(*i,QStringList({"supplierInfo","inn"}),temp);
      if(temp.size()!=0){notif.inn_supplier=temp[0]; }
                         else{ndom::WFindInDom::findInText(*i,QStringList({"subcontractor","inn"}),temp);
                             if(temp.size()!=0){notif.inn_supplier=temp[0]; }
                              else{notif.inn_supplier="";
                                   errorsLog.toErrReportFile(*i,"logReports223/supplierInfo_inn.xml");}
                                      }

      ndom::WFindInDom::findInText(*i,QStringList({"supplierInfo","name"}),temp);
      if(temp.size()!=0){notif.name_organization_supplier=temp[0];}
              else {  ndom::WFindInDom::findInText(*i,QStringList({"subcontractor","name"}),temp);
                      if(temp.size()!=0){notif.name_organization_supplier=temp[0];}
                         else {notif.name_organization_supplier="";
                            errorsLog.toErrReportFile(*i,"logReports223/supplierInfo_name.xml");
                             if(notif.inn_supplier=="")
                              continue;}
                     }

      ndom::WFindInDom::findInText(*i,QStringList({"contractDate"}),temp);
      if(temp.size()!=0){notif.dateUTC=temp[0];
                         notif.dateUTC.resize(10);
                         QDateTime time=QDateTime::fromString(notif.dateUTC,"yyyy-MM-dd");
                         notif.date=time.toTime_t();
                         if(notif.date==-1){errorsLog.toErrReportFile(*i,"logReports223/contractDate_minus1.xml");
                                                continue;}
                         }
                          else{notif.date=0;
                          notif.dateUTC="";
                          errorsLog.toErrReportFile(*i,"logReports223/contractDate.xml");
                          continue;
                          }

   lstNotif.push_back(notif);
    }
}

//---------------------------------------------------------------------------------------------
void WBaseWR::toSNotif44(QStringList &list,QList<SNotif> &lstNotif)
{
  SNotif notif;
  lstNotif.clear();
  QStringList temp;

 for(auto i=list.begin();i!=list.end();i++)
    {
      notif.inn="";
      notif.data=*i;
      ndom::WFindInDom::findInText(*i,QStringList({"contract","id"}),temp);
      if(temp.size()!=0){notif.guid=temp[0];}
                        else{errorsLog.toErrReportFile(*i,"logReports44/contract_id.xml");
                             continue;}

      ndom::WFindInDom::findInText(*i,QStringList({"customer","inn"}),temp);
      if(temp.size()!=0){notif.inn=temp[0];
                         notif.inn.replace(" ","");}
      if(notif.inn==""){errorsLog.toErrReportFile(*i,"logReports44/customer_inn.xml");
                        continue;}


      ndom::WFindInDom::findInText(*i,QStringList({"customer","fullName"}),temp);
      if(temp.size()!=0){notif.name_organization=temp.at(0);}
                        else {notif.name_organization="";
                              errorsLog.toErrReportFile(*i,"logReports44/customer_fullName.xml");
                                        continue;}

      ndom::WFindInDom::findInText(*i,QStringList({"supplier","legalEntityRF","INN"}),temp);
      if(temp.size()!=0){notif.inn_supplier=temp.at(0); }
                         else{ ndom::WFindInDom::findInText(*i,QStringList({"supplier","individualPersonRF","INN"}),temp);
                               if(temp.size()!=0){notif.inn_supplier=temp.at(0); }
                               else{
                                notif.inn_supplier="";
                                errorsLog.toErrReportFile(*i,"logReports44/supplier_legalEntityRF_INN.xml");
                                }
                              }
QString name;
      ndom::WFindInDom::findInText(*i,QStringList({"supplier","legalEntityRF","fullName"}),temp);
      if(temp.size()!=0){notif.name_organization_supplier=temp.at(0);
                         }
              else {
                    ndom::WFindInDom::findInText(*i,QStringList({"supplier","individualPersonRF","lastName"}),temp);
                    if(temp.size()!=0)name=temp.at(0);name+=" ";
                    ndom::WFindInDom::findInText(*i,QStringList({"supplier","individualPersonRF","firstName"}),temp);
                    if(temp.size()!=0)name+=temp.at(0); name+=" ";
                    ndom::WFindInDom::findInText(*i,QStringList({"supplier","individualPersonRF","middleName"}),temp);
                     if(temp.size()!=0)name+=temp.at(0);
                    if(name.size()>2){notif.name_organization_supplier=name;}

                    else{ndom::WFindInDom::findInText(*i,QStringList({"supplier","legalEntityForeignState","fullName"}),temp);
                          if(temp.size()!=0){notif.name_organization_supplier=temp.at(0);}
                                            else{ ndom::WFindInDom::findInText(*i,QStringList({"supplier","individualPersonForeignState","lastName"}),temp);
                                                   if(temp.size()!=0)name=temp.at(0);name+=" ";
                                                   ndom::WFindInDom::findInText(*i,QStringList({"supplier","individualPersonForeignState","firstName"}),temp);
                                                   if(temp.size()!=0)name+=temp.at(0); name+=" ";
                                                    ndom::WFindInDom::findInText(*i,QStringList({"supplier","individualPersonForeignState","middleName"}),temp);
                                                    if(temp.size()!=0)name+=temp.at(0);
                                                    if(name.size()>2){notif.name_organization_supplier=name;}
                                                       else{
                                                              notif.name_organization_supplier="";
                                                              errorsLog.toErrReportFile(*i,"logReports44/supplier_legalEntityRF_fullName.xml");
                                                              if(notif.inn_supplier=="")
                                                      continue;}
                                                    }
                          }
                   }


      ndom::WFindInDom::findInText(*i,QStringList({"signDate"}),temp);
      if(temp.size()!=0){notif.dateUTC=temp[0];
                          notif.dateUTC.resize(10);
                         QDateTime time=QDateTime::fromString(notif.dateUTC,"yyyy-MM-dd");
                         //если формат времени не подходит пишет в лог
                         if(!time.isValid()){
                                              errorsLog.toErrReportFile(*i,"logReports44/signDate_badTime.xml");
                                              continue;
                                             }
                         notif.date=time.toTime_t();
                          }
                          else{notif.date=0;
                          notif.dateUTC="";
                          errorsLog.toErrReportFile(*i,"logReports44/signDate.xml");
                                    continue;
                                }
     lstNotif.push_back(notif);
    }

}


//---------------------------------------------------------------------------------------------
void WBaseWR::toSDishon(QStringList &list,QList<SDishon> &lstDish)
{ SDishon dishon;
    lstDish.clear();
    QStringList temp;

  for(auto i=list.begin();i!=list.end();i++)
    {
      dishon.inn="";
      dishon.data=*i;


      ndom::WFindInDom::findInText(*i,QStringList({"supplier","inn"}),temp);

      if(temp.size()!=0){dishon.inn=temp[0];
                         dishon.inn.replace(" ","");}
                        else{ ndom::WFindInDom::findInText(*i,QStringList({"unfairSupplier","inn"}),temp);
                              if(temp.size()!=0){dishon.inn=temp[0];
                               dishon.inn.replace(" ","");}
                             }
      if(dishon.inn==""){errorsLog.toErrReportFile(*i,"logReports223d/supplier_inn.xml");
                         }

      ndom::WFindInDom::findInText(*i,QStringList({"supplier","name"}),temp);
      if(temp.size()!=0){dishon.name_organization=temp[0]; }
                        else{ ndom::WFindInDom::findInText(*i,QStringList({"supplier","supplierName"}),temp);
                              if(temp.size()!=0){dishon.name_organization=temp[0]; }
                             else{ndom::WFindInDom::findInText(*i,QStringList({"unfairSupplier","fullName"}),temp);
                                  if(temp.size()!=0){dishon.name_organization=temp[0]; }
                                  else{
                                  dishon.name_organization="";
                                   errorsLog.toErrReportFile(*i,"logReports223d/supplier_name.xml");
                                  if(dishon.inn=="")
                                      continue;}
                                }
                           }

      lstDish.push_back(dishon);
    }
}

//---------------------------------------------------------------------------------------------
void WBaseWR::toSDishon44(QStringList &list,QList<SDishon> &lstDish)
{ SDishon dishon;
    lstDish.clear();
    QStringList temp;
  for(auto i=list.begin();i!=list.end();i++)
    {
      dishon.inn="";
      dishon.data=*i;

      ndom::WFindInDom::findInText(*i,QStringList({"unfairSupplier","inn"}),temp);
      if(temp.size()!=0){dishon.inn=temp[0];
                         dishon.inn.replace(" ","");}
      //if(dishon.inn==""){errorsLog.toErrReportFile(*i,"logReports44d/unfairSupplier_inn.xml");
      //                   }


      ndom::WFindInDom::findInText(*i,QStringList({"unfairSupplier","fullName"}),temp);
      if(temp.size()!=0){dishon.name_organization=temp[0]; }
                        else{dishon.name_organization="";
          errorsLog.toErrReportFile(*i,"logReports44d/unfairSupplier_fullName.xml");
          if(dishon.inn=="")continue;}

      lstDish.push_back(dishon);

    }
}

//---------------------------------------------------------------------------------------------
//void WBaseWR::createTables(void)
//{
//   if(createTable223Notif()){}else {emit getError("create dishon");return;}
//   if(createTable223Dishon()){}else {emit getError("create notif");return;}
//   emit getError("all right");
//}

int WBaseWR::createTables(bool table223fz,bool table44fz,bool tableDishon223fz,bool tableDishon44fz)
{    WToBASE BD;
     bool flg=BD.start();
     if(!flg){return -1;}
     BD.prepare(CFZ223);
     if(table223fz){flg=BD.createTable223Notif();
                     if(!flg){return -2;}}
     if(tableDishon223fz){flg=BD.createTable223Dishon();
                          if(!flg){return -3;}}
     BD.prepare(CFZ44);
     if(table44fz){flg=BD.createTable223Notif();
                   if(!flg){return -4;}}
     if(tableDishon44fz){flg=BD.createTable223Dishon();
                         if(!flg){return -5;}}
}
