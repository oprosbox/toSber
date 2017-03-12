#ifndef TOBASE_H
#define TOBASE_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>

#include <QDataStream>
#include <QFile>

class WToBASE
{
public:
    WToBASE();
    bool openMSSQL();//открывает локальное соединение с MSSql
    void closeConn();//закрывает работающее соединение
    QSqlQuery *sqlQuery;
protected:
 QSqlDatabase sqlDataBase; 
 QSqlTableModel toViewTable;
};



class WReadFromFile
{
  public:
    WReadFromFile(){}
   bool read(QString name);
   QByteArray data;
   WToBASE toBASE;
};

#endif // TOBASE_H
