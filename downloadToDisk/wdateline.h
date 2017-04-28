#ifndef WDATELINE_H
#define WDATELINE_H

#include <QCalendarWidget>
#include <QDateEdit>
#include <QPushButton>

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
  void functConnDT(QDateEdit *dateEditBg,QPushButton *buttonBg,QDateEdit *dateEditEnd,QPushButton *buttonEnd);
signals:
  void setPath(QString path);
  void setDateBeg(QDate);
  void setDateEnd(QDate);
protected:
  QCalendarWidget *dialogBeg;
  QCalendarWidget *dialogEnd;
};

#endif // WDATELINE_H
