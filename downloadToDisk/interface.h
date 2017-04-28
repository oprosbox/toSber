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


//---------------------------------------------------------------------------------
class QWidgetRegion:public QDialog//создан объект отображающий регионы
{Q_OBJECT
 public:
   QWidgetRegion(){lblRegions=NULL;}
   void create(QStringList &regions,QString caption="223-ФЗ");
   void setRegionsCheck(QStringList &regions);
   void destr(void);
   QStringList listCurrRegions();
   QLabel *lblRegions;
public slots:
   void addCheck(bool);
   void clickOk();
signals:
   void emitListReg(QStringList);
protected:
   QList<QCheckBox*> chkRegions;
   QPushButton *buttonOk;

};
//---------------------------------------------------------------------------------
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
  QCheckBox *chk44fzNotif;
  QCheckBox *chk44fzDishon;
  QLineEdit *edt44fzNotif;
  QLineEdit *edt44fzDishon;
  QDateEdit *tm44fzNotifBeg;
  QDateEdit *tm44fzNotifEnd;
  QDateEdit *tm44fzDishonBeg;
  QDateEdit *tm44fzDishonEnd;
  QLineEdit *edt44fzInn;
  QPushButton *btn44fzNotif;
  QPushButton *btnDownloadStart;
  QLabel *regionsListNotif;
  QLabel *regionsListDish;
  QCheckBox *chk44fzContrToBase;
  QCheckBox *chk223fzContrToBase;
  QCheckBox *chk44fzDishonToBase;
  QCheckBox *chk223fzDishonToBase;
  QWidgetRegion w223fzNotifReg;
  QWidgetRegion w223fzDishonReg;
  QWidgetRegion w44fzNotifReg;
  QWidget *widget44Contr;
  QWidget *widget223Contr;
  QWidget *widget44Dish;
  QWidget *widget223Dish;

public slots:
  void createInterf(void);
  void btnStart(void);
  void set223fzRegionsNotif(QStringList);
  void set223fzRegionsDishon(QStringList);
  void set44fzRegionsContr(QStringList);
  void exec223fzNotif();
  void exec223fzDishon();
  void exec44fzContr();
  void allWasLoad(int id);

protected:
  ftpload::W223fz *w223fzNotif;
  ftpload::W223fz *w223fzDishon;
  ftpload::W223fz *w44fzNotif;
  ftpload::W223fz *w44fzDishon;
  QList<ftpload::WLoadFtp*> listDownload;
  QStringList regionsNotif;
  QStringList regionsDishon;
  QStringList regionsContract44;

};

}

#endif // INTERFACE_H
