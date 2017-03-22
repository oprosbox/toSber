#ifndef FZUNPACK_H
#define FZUNPACK_H

#include <QProcess>
#include <QDir>


class WPackUnpack7z
{
public:
  WPackUnpack7z(){}
  ~WPackUnpack7z(){destroyObj();}
  bool initObj(QString pathTo7z,QString logDir);
  void destroyObj(void);
  void unpackZip(QString pathZip,QString dirOut);//распасовка zip архива
  void packToZip(QString pathZip,QStringList files);//добавление файлов в zip архив
  void command(QString comm);//исполнение 7z комманды;
protected:
  QString path7z;
  QProcess proc;
  QString dirLog;
};


#endif // FZUNPACK_H
