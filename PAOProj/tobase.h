#ifndef TOBASE_H
#define TOBASE_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class WToBASE
{
public:
    WToBASE();
    bool openMySQL();//открывает удаленное соединение с MySql
    bool openMSSQL();//открывает локальное соединение с MSSql
    void closeConn();
protected:
 QSqlDatabase sqlDataBase;
  QSqlQuery sqlQuery;
};

#endif // TOBASE_H
