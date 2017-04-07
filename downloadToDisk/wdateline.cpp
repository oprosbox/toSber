#include "wdateline.h"
#include <QFileDialog>
#include <QApplication>
//------------------------------------------------------------------------------------------------------------
void WMainInterf::getPath(void)
{
  QFileDialog dialog;
  QString path;
  path=dialog.getExistingDirectory(0,"",QApplication::applicationDirPath());//0,"",QApplication::applicationDirPath(),"");
  if (path=="")return;
  emit setPath(path);
}
//----------------------------------------------------------------------------------------------------------------
void WMainInterf::getDateEnd()
{

  dialogEnd=new QCalendarWidget();
  dialogEnd->setSelectedDate(QDate::currentDate());
  connect(dialogEnd,SIGNAL(activated(QDate)),this,SLOT(closeDateEnd(QDate)));
  dialogEnd->show();
}
//----------------------------------------------------------------------------------------------------------------
void WMainInterf::closeDateBeg(QDate date)
{

emit setDateBeg(date);
     delete dialogBeg;

}
//----------------------------------------------------------------------------------------------------------------
void WMainInterf::getDateBeg()
{

   dialogBeg=new QCalendarWidget();
   dialogBeg->setSelectedDate(QDate::currentDate());
   connect(dialogBeg,SIGNAL(activated(QDate)),this,SLOT(closeDateBeg(QDate)));
   dialogBeg->show();
}
//----------------------------------------------------------------------------------------------------------------
void WMainInterf::closeDateEnd(QDate date)
{

emit setDateEnd(date);
      delete dialogEnd;
}
//----------------------------------------------------------------------------------------------------------------
 WMainInterf::WMainInterf()
 {
  }

 void WMainInterf::functConnDT(QDateEdit *dateEditBg,QPushButton *buttonBg,QDateEdit *dateEditEnd,QPushButton *buttonEnd)
 {
     dateEditBg->setDate(QDate::currentDate());
     QObject::connect(buttonBg,SIGNAL(clicked()), this,SLOT(getDateBeg()));
     QObject::connect(this,SIGNAL(setDateBeg(QDate)),dateEditBg,SLOT(setDate(QDate)));

     dateEditEnd->setDate(QDate::currentDate());
     QObject::connect(buttonEnd,SIGNAL(clicked()), this,SLOT(getDateEnd()));
     QObject::connect(this,SIGNAL(setDateEnd(QDate)),dateEditEnd,SLOT(setDate(QDate)));
 }
