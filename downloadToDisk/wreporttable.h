#ifndef WREPORTTABLE_H
#define WREPORTTABLE_H

#include <QDomDocument>
#include <QDomNode>
#include <QTableWidget>

class WReportTable
{
public:
    WReportTable();
    static void createWriteAndStart(QTableWidget *docIn,QString name);
    static void createAndWrite(QTableWidget *docIn,QString &name,bool local=true);
   static void createWriteAndStart(QDomDocument &docIn,QString name);
   static void createAndWrite(QDomDocument &docIn,QString &name,bool local=true);
   static void reportTable(QDomDocument &docIn,QDomDocument &tableOut);
   static void reportTable(QTableWidget *docIn,QDomDocument &tableOut);
protected:
   static void reportTableRecurs(QDomNode docIn,QDomNode &docOut,QDomDocument &domDocument);
};

#endif // WREPORTTABLE_H
