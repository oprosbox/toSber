#include "tobase.h"
#include <QSqlError>

WToBASE::WToBASE()
{

}
//------открывает удаленное соединение с MySql--------------------
bool WToBASE::openMySQL()
{
//    sqlDataBase = sqlDataBase.addDatabase("QMYSQL", "dbPAO");
//    sqlDataBase.setPort(3306);
//    sqlDataBase.setHostName("93.189.44.55");
//    sqlDataBase.setDatabaseName("cp678518_PAO_SB");
//    bool ok=sqlDataBase.open("cp678518_len","oprosbox1905");
//    QSqlError err=sqlDataBase.lastError();

    sqlDataBase = QSqlDatabase::addDatabase("QODBC", "dbPAO");
    sqlDataBase.setDatabaseName("Driver={MySQL ODBC 5.3 Unicode Driver};"
    "Server=93.189.44.55:3306;"
    "Database=cp678518_PAO_SB;"
    "Trusted_Connection=yes;");
    bool ok = sqlDataBase.open("cp678518_len","oprosbox1905");
    QSqlError err=sqlDataBase.lastError();
    return ok;
}

//------открывает локальное соединение с MSSql--------------------
bool WToBASE::openMSSQL()
{
    sqlDataBase = QSqlDatabase::addDatabase("QODBC", "dbPAO");
    sqlDataBase.setDatabaseName("Driver={SQL Server};"
    "Server=LVVPC\\SQLEXPRESS;"
    "Database=PAO_SB;"
    "Trusted_Connection=yes;");
    return sqlDataBase.open("lenV","oprosboxopros19");
}

//------закрывает работающее соединение----------------------------
void WToBASE::closeConn()
{

}
