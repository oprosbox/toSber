#include "tobase.h"
#include <QSqlError>

WToBASE::WToBASE()
{

}
//------открывает локальное соединение с MSSql--------------------
bool WToBASE::openMSSQL()
{
    sqlDataBase = QSqlDatabase::addDatabase("QODBC", "dbPAO");
    sqlDataBase.setDatabaseName("Driver={SQL Server};"
    "Server=LVVPC\\SQLEXPRESS;"
    "Database=PAO_SB;"
    "Trusted_Connection=yes;");
    bool ok=sqlDataBase.open("lenV","oprosboxopros19");
    if(ok)sqlQuery=new QSqlQuery(sqlDataBase);
    return ok;
}

//------закрывает работающее соединение----------------------------
void WToBASE::closeConn()
{
sqlDataBase.close();
delete sqlQuery;
}

//------закрывает работающее соединение----------------------------
bool WReadFromFile::read(QString name)
 {
    QFile file(name); // создаем объект класса QFile
    if (!file.open(QIODevice::ReadOnly)) // Проверяем, возможно ли открыть наш файл для чтения
        return false; // если это сделать невозможно, то завершаем функцию
    data = file.readAll();
    if(!toBASE.openMSSQL())return false;
    QString strExec="INSERT INTO regions VALUES(?,\"?\")";
    QString id,regns;

    toBASE.sqlQuery->prepare("INSERT INTO regions (id, region) VALUES (:id, :region)");



    for(int i=0;i<data.length();i++)
    {
     if((id.length()==2)&&(data[i]!=0)){regns+=data;}

     if(data[i]=='\n'){ toBASE.sqlQuery->bindValue(":id", id.toInt());
                        toBASE.sqlQuery->bindValue(":region", regns);

                        toBASE.sqlQuery->exec();
                        regns.clear();
                        id.clear();}
    }


 }
