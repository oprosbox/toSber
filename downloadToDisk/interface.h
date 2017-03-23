#ifndef INTERFACE_H
#define INTERFACE_H

#include "loadsave.h"
#include <QCheckBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QFileDialog>
#include <QCalendarWidget>
#include <QTextStream>
#include <QLabel>


namespace  wui {

  class WMainInterf : public QObject
  {
      Q_OBJECT
  public:
      WMainInterf();

  public slots:
   void getPath(void);
   void getDateBeg();
   void getDateEnd();
   void closeDateBeg(QDate);
   void closeDateEnd(QDate);
  signals:
    void setPath(QString path);
    void setDateBeg(QDate);
    void setDateEnd(QDate);
  protected:
    QCalendarWidget *dialogBeg;
    QCalendarWidget *dialogEnd;
  };

class QWidgetRegion:public QDialog
{Q_OBJECT
 public:
   void create(QStringList &regions,QString caption="223-ФЗ");
   void setRegionsCheck(QStringList &regions);
   void destr(void);
   QStringList listCurrRegions();
public slots:
   void addCheck(bool);
   void clickOk();
signals:
   void emitListReg(QStringList);
protected:
   QList<QCheckBox*> chkRegions;
   QPushButton *buttonOk;

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
  QPushButton *btn223fzNotif;
  QPushButton *btn223fzDish;
  QPushButton *btnDownloadStart;
  QLabel *regionsListNotif;
  QLabel *regionsListDish;
public slots:
  void createInterf(void);
  void btnStart(void);
  void set223fzRegionsNotif(QStringList);
  void set223fzRegionsDishon(QStringList);
  void exec223fzNotif();
  void exec223fzDishon();
protected:
ftpload::W223fz w223fzNotif;
ftpload::W223fz w223fzDishon;
QWidgetRegion w223fzNotifReg;
QWidgetRegion w223fzDishonReg;
QStringList regionsNotif;
QStringList regionsDishon;

};

}

#endif // INTERFACE_H
