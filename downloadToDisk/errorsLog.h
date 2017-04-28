#ifndef ERRORSLOG_H
#define ERRORSLOG_H
#include <QString>

class WErrorsLog
{
public:
    WErrorsLog();
    void toErrReportFile(QString errorStr,QString localPath);
    void toLogFile(QString errorStr,QString localPath="logfile.txt");
    QString fromIniFile(QString param,QString valNull,QString localPath="initfile.xml");
protected:
    int idAllErrorReports;
};


extern WErrorsLog errorsLog;

#endif // ERRORSLOG_H
