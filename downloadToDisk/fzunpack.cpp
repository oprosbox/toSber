#include "fzunpack.h"

#include <QApplication>
#include <QFile>


 bool WPackUnpack7z::initObj(QString pathTo7z,QString logDir)
{
  path7z=pathTo7z;
  dirLog=logDir;
  return true;
}

void WPackUnpack7z::destroyObj(void)
{

}

void WPackUnpack7z::unpackZip(QString pathZip,QString dirOut,int id,bool delArh)
{
  QStringList comm;
  QString indStr;
  indStr.sprintf("%i",id);
  comm.push_back("/C "+path7z+" x -aoa "+pathZip+" "+"-o"+dirOut+" >> "+dirLog+"\\f7ZipLog_"+indStr+".txt");
  QProcess::execute("cmd.exe",comm);
  if(delArh)
     { QFile(pathZip).remove(); }
}

void WPackUnpack7z::packToZip(QString pathZip,QStringList files)
{
  QStringList comm;
  comm.push_back("/C "+path7z+" a -tzip "+pathZip);
  for(int i=0;i<files.size();i++)
  {comm[0]+=" "+files[i];}
QProcess::execute("cmd.exe",comm);
}

void WPackUnpack7z::command(QString command)
{
 QStringList comm;
 comm.push_back(command);
QProcess::execute("cmd.exe",comm);
}
