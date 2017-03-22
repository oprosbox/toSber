#ifndef INTERFACE_H
#define INTERFACE_H

#include "loadsave.h"
#include <QCheckBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QWidget>

namespace  wui {

class QWidgetRegion:public QWidget
{Q_OBJECT
 public:
   void create(QStringList &regions);
   QStringList listCurrRegions();
public slots:
   void addCheck(bool);
protected:
   QList<QCheckBox*> chkRegions;

};

class WUI:public QObject
{Q_OBJECT
public:
  QCheckBox *chk223fzNotif;
  QCheckBox *chk223fzDishon;
  QLineEdit *edt223fzNotif;
  QLineEdit *edt223fzDishon;
  QDateEdit *tm223fzNotifBeg;
  QDateEdit *tm223fzNotifEnd;
  QDateEdit *tm223fzDishonBeg;
  QDateEdit *tm223fzDishonEnd;
  QLineEdit *edt223fzInn;
public slots:
  void btnStart(void);
  protected:
  void getRegionsNotif(QStringList &regions);
  void getRegionsDishon(QStringList &regions);
ftpload::W223fz w223fzNotif;
ftpload::W223fz w223fzDishon;
QWidgetRegion *w223fzNotifReg;
QWidgetRegion *w223fzDishonReg;
};

}

#endif // INTERFACE_H
