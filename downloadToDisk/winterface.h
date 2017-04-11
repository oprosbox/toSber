#ifndef WINTERFACE_H
#define WINTERFACE_H

#include <QObject>
#include <QTableWidget>
#include <QPushButton>
#include <QDateEdit>
#include <QLineEdit>
#include <QCheckBox>
#include "frombase.h"

const int C_TYPEITEMSTRING=1;
const int C_TYPEITEMCHECK=2;
const int C_TYPEITEMBUTTONS=3;
//----------------------------------------------------------------------------------
struct STypeItem
{
   QString param;
   int C_TYPEITEM;
   void *widget;
   QString data;
};
//----------------------------------------------------------------------------------
typedef  QList<STypeItem> WLines;

class PSortLinesByDate
{
public:
  PSortLinesByDate(bool flgBy){flgByRet=flgBy;}
bool operator ()(WLines &first,WLines &second)
{
 QDateTime tm1=QDateTime::fromString(first.at(3).param,"yyyy-MM-dd");
 QDateTime tm2=QDateTime::fromString(second.at(3).param,"yyyy-MM-dd");
 if(flgByRet){if(tm1>tm2){return true;}else {return false;}}
            else{if(tm1<tm2){return true;}else {return false;}}
}
protected:
 bool flgByRet;
};
//----------------------------------------------------------------------------------


class WInterface:public QObject
{Q_OBJECT
public:
  QTableWidget* tableBase;
  QDateEdit* tmBegin;
  QDateEdit* tmEnd;
  QLineEdit* innLine;
  QCheckBox* dish223;
  QCheckBox* dish44;
  void createInterface();
public slots:
  void createTableReport();
  void refreshTable();
  void refreshTableComm(QString comm);
  void getDishonContrTable();
  void createBigReport();
  void createDataReport(QTableWidgetItem* item);
  void createDishonReport(QTableWidgetItem* item);
  void refreshTableByList(void);
  void sortTable(int ind);
  void addInn(QTableWidgetItem* item);
protected:
  void addObjectToTable(SNotifDishon &select,QList<STypeItem> &paramTable);
  void createTable(QList<STypeItem> heads);
  void addStringToTable(QList<STypeItem> &columns);
  WBaseRD *base;
  QList<STypeItem> baseLine;
  std::vector<WLines> infoTable;
  SSelect lastSelect;
  bool flgByRet;
};

#endif // WINTERFACE_H
