#ifndef WINTERFACE_H
#define WINTERFACE_H

#include <QObject>
#include <QTableWidget>
#include <QPushButton>
#include <QDateEdit>
#include <QLineEdit>
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
};
//----------------------------------------------------------------------------------

typedef  QList<STypeItem> WLines;

class WInterface:public QObject
{Q_OBJECT
public:
  QTableWidget* tableBase;
  QDateEdit* tmBegin;
  QDateEdit* tmEnd;
  QLineEdit* innLine;
  void createInterface();
public slots:
  void createTableReport();
  void refreshTable();
  void createBigReport();
  void createDataReport(QTableWidgetItem* item);
  void createDishonReport(QTableWidgetItem* item);
protected:
  void addObjectToTable(SNotifDishon &select,QList<STypeItem> &paramTable);
  void createTable(QList<STypeItem> heads);
  void addStringToTable(QList<STypeItem> &columns);
  WBaseRD *base;
  QList<STypeItem> baseLine;
  QList<WLines> infoTable;
  SSelect lastSelect;
};

#endif // WINTERFACE_H
