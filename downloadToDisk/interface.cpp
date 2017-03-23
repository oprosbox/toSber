#include "interface.h"
#include <QApplication>


namespace  wui {

void  QWidgetRegion::addCheck(bool flg)
{
    for(auto i=chkRegions.begin()+1;i!=chkRegions.end();i++)
    {(*i)->setChecked(flg);}
}
//------------------------------------------------------------------
void QWidgetRegion::clickOk()
 {
  emit emitListReg(listCurrRegions());
      accept();
 }
//--------------------------------------------------------------------
void QWidgetRegion::destr(void)
 {

 }
//--------------------------------------------------------------------------------
void QWidgetRegion::setRegionsCheck(QStringList &regions)
{ auto chk=chkRegions.begin();
  for(auto i=regions.begin();i!=regions.end();i++)
    {
      for(;chk!=chkRegions.end();chk++)
      {if((*chk)->text()==*i){(*chk)->setChecked(true);break;}}

     }
}
//---------------------------------------------------------------------------------
void QWidgetRegion::create(QStringList &regions,QString caption)
{QCheckBox *check;int posx=0;int posy=0;
 this->setGeometry(100,100,640,800);
 check=new QCheckBox(this);
this->setWindowTitle(caption);
 if(posx%600==0)posy+=30;
 check->setGeometry(20,posy,120,25);
 check->setText("Все регионы");
 check->setMaximumWidth(640);
 check->setChecked(true);
 check->show();
 chkRegions.push_back(check);

 posy+=30;
 connect(check,SIGNAL(clicked(bool)),this,SLOT(addCheck(bool)));

for(auto i=regions.begin();i!=regions.end();i++)
  {
    check=new QCheckBox(this);

    if(posx%600==0)posy+=30;
    check->setGeometry(posx%600+20,posy,120,25);
    posx+=150;
    check->setText(*i);
    check->show();
    check->setChecked(true);
    chkRegions.push_back(check);
   }

buttonOk=new QPushButton(this);
buttonOk->setText("принять");
buttonOk->setGeometry(200,30,100,25);
buttonOk->setVisible(true);
buttonOk->setDefault(true);
connect(buttonOk,SIGNAL(clicked()),this,SLOT(clickOk()));
}
//--------------------------------------------------------------------------------------------------------
QStringList QWidgetRegion::listCurrRegions()
{ QStringList list;
  for(auto i=chkRegions.begin()+1;i!=chkRegions.end();i++)
  {if((*i)->isChecked()){list.push_back((*i)->text());}}
  return list;
}
//----------------------------------------------------------------------------------------------------
void WUI::createInterf(void)
{w223fzNotif.getRegions(regionsNotif);
 w223fzNotifReg.create(regionsNotif,"223-ФЗ Тандеры");
 w223fzDishon.getRegions(regionsDishon);
 w223fzDishonReg.create(regionsDishon,"223-ФЗ Недобросовестные поставщики");
 connect(&w223fzNotifReg,SIGNAL(emitListReg(QStringList)),this,SLOT(set223fzRegionsNotif(QStringList)));
 connect(&w223fzDishonReg,SIGNAL(emitListReg(QStringList)),this,SLOT(set223fzRegionsDishon(QStringList)));
 connect(btn223fzNotif,SIGNAL(clicked()),this,SLOT(exec223fzNotif()));
 connect(btn223fzDish,SIGNAL(clicked()),this,SLOT(exec223fzDishon()));
 connect(btnDownloadStart,SIGNAL(clicked()),this,SLOT(btnStart()));
}
//----------------------------------------------------------------------------------------------------
void WUI::exec223fzNotif()
{ w223fzNotifReg.setRegionsCheck(regionsNotif);
  w223fzNotifReg.exec();
}
//------------------------------------------------------------------------------------------------------
void WUI::exec223fzDishon()
{ w223fzDishonReg.setRegionsCheck(regionsDishon);
  w223fzNotifReg.exec();
}
//------------------------------------------------------------------------------------------------------------
void WUI::btnStart(void)
{

   if(chk223fzNotif->isChecked()) {
                                    w223fzNotif.create223fzNotif(this->edt223fzNotif->text(),
                                                                 regionsNotif,
                                                                 this->tm223fzNotifBeg->dateTime(),
                                                                 this->tm223fzNotifEnd->dateTime(),
                                                                 this->edt223fzInn->text());
                                    w223fzNotif.ftp223fz->download();
                                    }
   if(chk223fzDishon->isChecked()) {
                                     w223fzDishon.create223fzDish(this->edt223fzNotif->text(),
                                                                  regionsDishon,
                                                                  this->tm223fzNotifBeg->dateTime(),
                                                                  this->tm223fzNotifEnd->dateTime());
                                    }
}
//------------------------------------------------------------------------------------------------------------
void WUI::set223fzRegionsNotif(QStringList regions)
{
 regionsNotif=regions;
}
//------------------------------------------------------------------------------------------------------------
void WUI::set223fzRegionsDishon(QStringList regions)
{
 regionsDishon=regions;
}
//------------------------------------------------------------------------------------------------------------
void WMainInterf::getPath(void)
{
  QFileDialog dialog;
  QString path;
  path=dialog.getExistingDirectory(0,"",QApplication::applicationDirPath());//0,"",QApplication::applicationDirPath(),"");
  if (path=="")return;
  emit setPath(path);
}

void WMainInterf::getDateEnd()
{

  dialogEnd=new QCalendarWidget();
  dialogEnd->setSelectedDate(QDate::currentDate());
  connect(dialogEnd,SIGNAL(activated(QDate)),this,SLOT(closeDateEnd(QDate)));
  dialogEnd->show();
}

void WMainInterf::closeDateBeg(QDate date)
{

emit setDateBeg(date);
     delete dialogBeg;

}

void WMainInterf::getDateBeg()
{

   dialogBeg=new QCalendarWidget();
   dialogBeg->setSelectedDate(QDate::currentDate());
   connect(dialogBeg,SIGNAL(activated(QDate)),this,SLOT(closeDateBeg(QDate)));
   dialogBeg->show();
}

void WMainInterf::closeDateEnd(QDate date)
{

emit setDateEnd(date);
      delete dialogEnd;
}

 WMainInterf::WMainInterf()
 {
  }
}
