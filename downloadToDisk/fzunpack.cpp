#include "fzunpack.h"

#include <QApplication>
#include <QFile>


bool WPackUnpack7z::initObj(QString pathTo7z)
{
  path7z=pathTo7z;
  return true;
}

void WPackUnpack7z::destroyObj(void)
{

}

void WPackUnpack7z::unpackZip(QString pathZip,QString dirOut)
{
  QStringList comm;
  comm.push_back("/C "+path7z+" x "+pathZip+" "+"-o"+dirOut);
  proc.start("cmd.exe",comm);
}

void WPackUnpack7z::packToZip(QString pathZip,QStringList files)
{
  QStringList comm;
  comm.push_back("/C "+path7z+" a -tzip "+pathZip);
  for(int i=0;i<+files.size();i++)
  {comm[0]+=" "+files[i];}
proc.startDetached("cmd.exe",comm);
}

void WPackUnpack7z::command(QString command)
{
 QStringList comm;
 comm.push_back(command);
proc.start("cmd.exe",comm);
}
