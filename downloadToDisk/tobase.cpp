#include "tobase.h"
#include <QSqlError>
#include "findindom.h"
#include <QFile>



//----------------------------------------------------------------------------------------------------------------
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
   return base.open(login,pass);
}
//----------------------------------------------------------------------------------------------------------------


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

  queryDishon->prepare("INSERT INTO DISHON223FZ (inn,name_organization,date,dateUTC,guid)"
                      "VALUES (:inn, :name, :date,:dateUTC, :guid);");

  queryNotifData->prepare("INSERT INTO NOTIFI223FZDATA (guid,data)"
                      "VALUES (:guid, :data);");

  queryDishonData->prepare("INSERT INTO DISHON223FZDATA (guid,data)"
                      "VALUES (:guid, :data);");

  queryNotifSelectData->prepare(//"DROP TABLE NOTIFI223FZ;"
                                //"DROP TABLE NOTIFI223FZDATA;"
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

  queryDishonSelectData->prepare(//"DROP TABLE DISHON223FZ;"
                                 //"DROP TABLE DISHON223FZDATA;"
        "CREATE TABLE DISHON223FZ ("
        "id INTEGER PRIMARY KEY NOT NULL IDENTITY(1,1),"
        "inn CHAR(20),"
        "name_organization varchar(3000),"
        "date INTEGER,"
        "dateUTC varchar(20),"
        "guid varchar(50));"
        "CREATE TABLE DISHON223FZDATA ("
        "guid varchar(50) PRIMARY KEY,"
        "data varchar(MAX));"
       );
     break;}
    case CFZ44:{queryNotif->prepare("INSERT INTO CONTRACT44FZ(inn,name_organization,inn_supplier,name_organization_supplier,date,dateUTC,idContract)"
                                   "VALUES (:inn, :name, :inn_supplier, :name_supplier, :date,:dateUTC, :guid);");

                queryDishon->prepare("INSERT INTO DISHON44FZ (inn,name_organization,date,dateUTC,idContract)"
                                    "VALUES (:inn, :name, :date,:dateUTC, :guid);");

                queryNotifData->prepare("INSERT INTO CONTRACT44FZDATA (idContract,data)"
                                    "VALUES (:guid, :data);");

                queryDishonData->prepare("INSERT INTO DISHON44FZDATA (idContract,data)"
                                    "VALUES (:guid, :data);");

                queryNotifSelectData->prepare(//"DROP TABLE CONTRACT44FZ;"
                                              //"DROP TABLE CONTRACT44FZDATA;"
                      "CREATE TABLE CONTRACT44FZ ("
                      "id INTEGER PRIMARY KEY NOT NULL IDENTITY(1,1),"
                      "inn varchar(20),"
                      "name_organization varchar(3000),"
                      "inn_supplier varchar(20),"
                      "name_organization_supplier varchar(3000),"
                      "date INTEGER,"
                      "dateUTC varchar(20),"
                      "idContract varchar(50));"
                      "CREATE TABLE CONTRACT44FZDATA ("
                      "idContract varchar(50) PRIMARY KEY,"
                      "data varchar(MAX));"
                     );

                queryDishonSelectData->prepare(//"DROP TABLE DISHON44FZ;"
                                               //"DROP TABLE DISHON44FZDATA;"
                      "CREATE TABLE DISHON44FZ ("
                      "id INTEGER PRIMARY KEY NOT NULL IDENTITY(1,1),"
                      "inn CHAR(20),"
                      "name_organization varchar(3000),"
                      "date INTEGER,"
                      "dateUTC varchar(20),"
                      "idContract varchar(50));"
                      "CREATE TABLE DISHON44FZDATA ("
                      "idContract varchar(50) PRIMARY KEY,"
                      "data varchar(MAX));"
                     );break;}
    }

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
    else{QString txt="base  connect"+base.lastError().text();
              ndom::toLogFile(txt); }
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

  if(!queryNotifSelectData->exec()){ QString txt="base create  notifTable"+queryNotifSelectData->lastError().text();
                           ndom::toLogFile(txt); return false;}
 return true;
}
//------------------------------------------------------------------
bool WToBASE::createTable223Dishon()
{

  if(!queryDishonSelectData->exec()){ QString txt="base create  dishonTable"+queryDishonSelectData->lastError().text();
                            ndom::toLogFile(txt); return false;}
  return true;
}
//------------------------------------------------------------------
bool WToBASE::insertToBase223Dishon(SDishon &dish)
{ //QSqlDatabase::database().transaction();
  queryDishon->bindValue(":inn", dish.inn);
  queryDishon->bindValue(":name", dish.name_organization);
  queryDishon->bindValue(":date", dish.date_add);
  queryDishon->bindValue(":dateUTC", dish.date_addUTC);
  queryDishon->bindValue(":guid",dish.guid);
  if(!queryDishon->exec()){ QString txt="base write  queryDishon"+queryDishon->lastError().text();
                            ndom::toLogFile(txt); return false;}

  queryDishonData->bindValue(":guid", dish.guid);
  queryDishonData->bindValue(":data",dish.data);
  if(!queryDishonData->exec()){ QString txt="base write  queryDishonData"+queryDishonData->lastError().text();
                                ndom::toLogFile(txt); return false;}
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
  if(!queryNotif->exec()){ QString txt="base write  queryNotif"+queryNotif->lastError().text();
                           ndom::toLogFile(txt); return false;}

  queryNotifData->bindValue(":guid", notif.guid);
  queryNotifData->bindValue(":data",notif.data);
  if(!queryNotifData->exec()){ QString txt="base write  queryNotifData"+queryNotifData->lastError().text();
                              ndom::toLogFile(txt); return false;}
  //QSqlDatabase::database().commit();
  return true;
}

//-------------------------------------------------------------------------------------------
bool WBaseWR::start(QString url,QString database,QString login, QString pass,int CNoFZ)
{CFZType=CNoFZ;
 bool flgOpen=WToBASE::start(url,database,login,pass);
if(flgOpen){prepare(CFZType);}

return flgOpen;
}

//--------------------------------------------------------------------------------------------
bool WBaseWR::writeToNotif(QStringList findObjects)
{
QList<SNotif> lstNotif;
switch(CFZType)
{case CFZ223:{ toSNotif(findObjects,lstNotif);break;}
 case CFZ44:{ toSNotif44(findObjects,lstNotif);break;}
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
                         //если формат времени не подходит пишет в лог
                         if(!time.isValid()){ QString txt="notif bad format date: "+temp[0];
                                             ndom::toLogFile(txt);
                                             }

                         notif.date=time.toTime_t();}
                          else{notif.date=0;
                          notif.dateUTC="";
                          }

      ndom::WFindInDom::findInText(*i,QStringList({"header","guid"}),temp);
      if(temp.size()!=0){notif.guid=temp[0];}
                        else{notif.guid="";}

      if((notif.inn=="")||(notif.guid=="")){}
                    else{lstNotif.push_back(notif);}
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
      ndom::WFindInDom::findInText(*i,QStringList({"customer","inn"}),temp);
      if(temp.size()!=0){notif.inn=temp[0]; }

      ndom::WFindInDom::findInText(*i,QStringList({"customer","fullName"}),temp);
      if(temp.size()!=0){notif.name_organization=temp[0];}
                        else {notif.name_organization="";}

      ndom::WFindInDom::findInText(*i,QStringList({"supplier","legalEntityRF","INN"}),temp);
      if(temp.size()!=0){notif.inn_supplier=temp[0]; }
                         else{notif.inn_supplier="";}

      ndom::WFindInDom::findInText(*i,QStringList({"supplier","legalEntityRF","fullName"}),temp);
      if(temp.size()!=0){notif.name_organization_supplier=temp[0];}
      //else{ndom::WFindInDom::findInText(*i,QStringList({"contractInfo","supplierName"}),temp);
      //        if(temp.size()!=0) {notif.name_organization_supplier=temp[0];}
              else {notif.name_organization_supplier="";}

      ndom::WFindInDom::findInText(*i,QStringList({"signDate"}),temp);
      if(temp.size()!=0){notif.dateUTC=temp[0];
                         QDateTime time=QDateTime::fromString(temp[0],"yyyy-MM-dd");
                         //если формат времени не подходит пишет в лог
                         if(!time.isValid()){ QString txt="notif bad format date: "+temp[0];
                                              ndom::toLogFile(txt);
                                             }

                         notif.date=time.toTime_t();}
                          else{notif.date=0;
                          notif.dateUTC="";
                          }

      ndom::WFindInDom::findInText(*i,QStringList({"contract","id"}),temp);
      if(temp.size()!=0){notif.guid=temp[0];}
                        else{notif.guid="";}

      if((notif.inn=="")||(notif.guid=="")){}
                    else{lstNotif.push_back(notif);}
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
      if(temp.size()!=0){dishon.inn=temp[0]; }


      ndom::WFindInDom::findInText(*i,QStringList({"supplier","name"}),temp);
      if(temp.size()!=0){dishon.name_organization=temp[0]; }
                        else{dishon.name_organization="";}

      ndom::WFindInDom::findInText(*i,QStringList({"includeDate"}),temp);
      if(temp.size()!=0){dishon.date_addUTC=temp[0];
                         QDateTime time=QDateTime::fromString(temp[0],"yyyy-MM-ddThh:mm:ss");
                         //если формат времени не подходит пишет в лог
                         if(!time.isValid()){ QString txt="dishon bad format date: "+temp[0];
                                             ndom::toLogFile(txt);
                                             }

                         dishon.date_add=time.toTime_t();}
                          else{dishon.date_add=0;
                          dishon.date_addUTC="";
                          }

      ndom::WFindInDom::findInText(*i,QStringList({"header","guid"}),temp);
      if(temp.size()!=0){dishon.guid=temp[0];}
                        else{dishon.guid="";}

      if((dishon.inn=="")||(dishon.guid=="")){}
                      else{lstDish.push_back(dishon);}

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
      ndom::WFindInDom::findInText(*i,QStringList({"supplier","inn"}),temp);
      if(temp.size()!=0){dishon.inn=temp[0]; }


      ndom::WFindInDom::findInText(*i,QStringList({"supplier","name"}),temp);
      if(temp.size()!=0){dishon.name_organization=temp[0]; }
                        else{dishon.name_organization="";}

      ndom::WFindInDom::findInText(*i,QStringList({"includeDate"}),temp);
      if(temp.size()!=0){dishon.date_addUTC=temp[0];
                         QDateTime time=QDateTime::fromString(temp[0],"yyyy-MM-ddThh:mm:ss");
                         //если формат времени не подходит пишет в лог
                         if(!time.isValid()){ QString txt="dishon bad format date: "+temp[0];
                                             ndom::toLogFile(txt);
                                             }

                         dishon.date_add=time.toTime_t();}
                          else{dishon.date_add=0;
                          dishon.date_addUTC="";
                          }

      ndom::WFindInDom::findInText(*i,QStringList({"header","guid"}),temp);
      if(temp.size()!=0){dishon.guid=temp[0];}
                        else{dishon.guid="";}

      if((dishon.inn=="")||(dishon.guid=="")){}
                      else{lstDish.push_back(dishon);}

    }
}

////---------------------------------------------------------------------------------------------
//void WBaseWR::createTables(void)
//{
//   if(createTable223Notif()){}else {emit getError("create dishon");return;}
//   if(createTable223Dishon()){}else {emit getError("create notif");return;}
//   emit getError("all right");
//}

int WBaseWR::createTables(bool table223fz,bool table44fz,bool tableDishon223fz,bool tableDishon44fz)
{    WToBASE BD;
     bool flg=BD.start("LVVPC\\SQLEXPRESS","PAO_SB","lenV","oprosboxopros19");
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
