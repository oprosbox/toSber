#include "errorsLog.h"
#include <QFile>
#include <QDomDocument>
#include <QApplication>
#include <QDateTime>


WErrorsLog errorsLog;

WErrorsLog::WErrorsLog()
{
idAllErrorReports=0;
}

void WErrorsLog::toErrReportFile(QString errorStr,QString localPath)
{   ++idAllErrorReports;
    QString path;
    path.sprintf("%i",idAllErrorReports);
    path.push_front("err_");
    path.push_back("_");
    localPath.insert(localPath.lastIndexOf('/')+1,path);
    QFile fLog(QApplication::applicationDirPath()+ "/"+localPath);
    fLog.open(QFile::WriteOnly);
    fLog.write(errorStr.toLocal8Bit());
    fLog.close();
}

void WErrorsLog::toLogFile(QString errorStr,QString localPath)
{   QString errStr=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    errStr+="  "+errorStr+"\r\n";
    QFile fLog(QApplication::applicationDirPath()+ "/"+localPath);
    fLog.open(QFile::Append);
    fLog.write(errStr.toLocal8Bit());
    fLog.close();
}

QString WErrorsLog::fromIniFile(QString param,QString valNull,QString localPath)
{ QFile file(QApplication::applicationDirPath()+ "/"+localPath);
  QString val=valNull;
  if(file.open(QFile::ReadOnly)){//усли файл существует
                                 QDomDocument doc;
                                  doc.setContent(&file);
                                 QDomNodeList controls = doc.elementsByTagName(param);
                                 if(controls.size()!=0)//если тег найден
                                 {val=controls.at(0).toElement().text();}
                                 }
    file.close();
    return val;
}
