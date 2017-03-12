#ifndef TOBASE_H
#define TOBASE_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>

class WToBASE
{
public:
    WToBASE();
    bool openMySQL();//открывает удаленное соединение с MySql
    bool openMSSQL();//открывает локальное соединение с MSSql
    void closeConn();//закрывает работающее соединение
protected:
 QSqlDatabase sqlDataBase;
 QSqlQuery sqlQuery;
 QSqlTableModel toViewTable;
};

#endif // TOBASE_H
