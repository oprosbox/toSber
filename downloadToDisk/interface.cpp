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
if (lblRegions!=NULL){QString add;
                      add.sprintf("%i",regions.size());
                      add.push_front("выбрано: ");
                      lblRegions->setText(add);}
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

  if (lblRegions!=NULL){QString add;
                        add.sprintf("%i",list.size());
                        add.push_front("выбрано: ");
                        lblRegions->setText(add);}
  return list;
}
//----------------------------------------------------------------------------------------------------
void WUI::createInterf(void)
{
 ftpload::W223fz::getRegions(regionsNotif,CFZ223);
 w223fzNotifReg.create(regionsNotif,"223-ФЗ Контракты");
 ftpload::W223fz::getRegions(regionsDishon,CFZ223);
 w223fzDishonReg.create(regionsDishon,"223-ФЗ Недобросовестные поставщики");
 ftpload::W223fz::getRegions(regionsContract44,CFZ44);
 w44fzNotifReg.create(regionsContract44,"44-ФЗ Контракты");
 connect(&w223fzNotifReg,SIGNAL(emitListReg(QStringList)),this,SLOT(set223fzRegionsNotif(QStringList)));
 connect(&w223fzDishonReg,SIGNAL(emitListReg(QStringList)),this,SLOT(set223fzRegionsDishon(QStringList)));
 connect(btn223fzNotif,SIGNAL(clicked()),this,SLOT(exec223fzNotif()));
 connect(btn223fzDish,SIGNAL(clicked()),this,SLOT(exec223fzDishon()));
 connect(&w44fzNotifReg,SIGNAL(emitListReg(QStringList)),this,SLOT(set44fzRegionsContr(QStringList)));
 connect(btn44fzNotif,SIGNAL(clicked()),this,SLOT(exec44fzContr()));
 connect(btnDownloadStart,SIGNAL(clicked()),this,SLOT(btnStart()));
// connect(w223fzNotif.ftp223fz,SIGNAL(allFilesProcess(int)),this,SLOT(allWasLoad(int)));
//  connect(w44fzNotif.ftp223fz,SIGNAL(allFilesProcess(int)),this,SLOT(allWasLoad(int)));
//   connect(w223fzDishon.ftp223fz,SIGNAL(allFilesProcess(int)),this,SLOT(allWasLoad(int)));
//    connect(w44fzDishon.ftp223fz,SIGNAL(allFilesProcess(int)),this,SLOT(allWasLoad(int)));
}
//-----------------------------------------------------------------------------------------------------
 void WUI::allWasLoad(int id)
 { if(listDownload.size()!=0)
     {listDownload.pop_front();}
     switch(id)
     {
     case 1:{widget223Contr->setEnabled(true);delete w223fzNotif;break;}
     case 2:{widget223Dish->setEnabled(true);delete w223fzDishon;break;}
     case 3:{widget44Contr->setEnabled(true);delete w44fzNotif;break;}
     case 4:{widget44Dish->setEnabled(true);delete w44fzDishon;}
     }
    if(listDownload.size()!=0)
    {listDownload.front()->download();}
 }

//----------------------------------------------------------------------------------------------------
void WUI::exec223fzNotif()
{ w223fzNotifReg.setRegionsCheck(regionsNotif);
  w223fzNotifReg.exec();
}
//------------------------------------------------------------------------------------------------------
void WUI::exec223fzDishon()
{ w223fzDishonReg.setRegionsCheck(regionsDishon);
  w223fzDishonReg.exec();
}
//----------------------------------------------------------------------------------------------------
void WUI::exec44fzContr()
{ w44fzNotifReg.setRegionsCheck(regionsContract44);
  w44fzNotifReg.exec();
}

//------------------------------------------------------------------------------------------------------------
void WUI::btnStart(void)
{int countAdd=0;
   if((chk223fzNotif->isChecked())&&
       widget223Contr->isEnabled()){w223fzNotif=new ftpload::W223fz;
                                      ++countAdd;
                                    w223fzNotif->ftp223fz->id=1;
                                    connect(w223fzNotif->ftp223fz,SIGNAL(allFilesProcess(int)),this,SLOT(allWasLoad(int)));
                                    w223fzNotif->create223fzNotif(this->edt223fzNotif->text(),
                                                                 regionsNotif,
                                                                 this->tm223fzNotifBeg->dateTime(),
                                                                 this->tm223fzNotifEnd->dateTime(),
                                                                 this->edt223fzInn->text());
                                    listDownload.push_back(w223fzNotif->ftp223fz);

                                    if(chk223fzContrToBase->isChecked()) w223fzNotif->baseConnect();
                                    widget223Contr->setEnabled(false);
                                    }

   if((chk223fzDishon->isChecked())&&
      (widget223Dish->isEnabled())){w223fzDishon=new ftpload::W223fz;
                                      ++countAdd;
                                      w223fzDishon->ftp223fz->id=2;
                                     connect(w223fzDishon->ftp223fz,SIGNAL(allFilesProcess(int)),this,SLOT(allWasLoad(int)));
                                     w223fzDishon->create223fzDish(this->edt223fzDishon->text(),
                                                                  regionsDishon,
                                                                  this->tm223fzDishonBeg->dateTime(),
                                                                  this->tm223fzDishonEnd->dateTime());

                                     listDownload.push_back(w223fzDishon->ftp223fz);
                                     if(chk223fzDishonToBase->isChecked()) w223fzDishon->baseConnect();
                                     widget223Dish->setEnabled(false);
                                    }

   if((chk44fzNotif->isChecked())&&
      (widget44Contr->isEnabled())){w44fzNotif = new ftpload::W223fz;
                                    ++countAdd;
                                     w44fzNotif->ftp223fz->id=3;
                                    connect(w44fzNotif->ftp223fz,SIGNAL(allFilesProcess(int)),this,SLOT(allWasLoad(int)));
                                    w44fzNotif->create44fzNotif(this->edt44fzNotif->text(),
                                                                 regionsContract44,
                                                                 this->tm44fzNotifBeg->dateTime(),
                                                                 this->tm44fzNotifEnd->dateTime(),
                                                                 this->edt44fzInn->text());

                                    listDownload.push_back(w44fzNotif->ftp223fz);

                                    if(chk44fzContrToBase->isChecked()) w44fzNotif->baseConnect();
                                    widget44Contr->setEnabled(false);
                                    }

   if((chk44fzDishon->isChecked())&&
      (widget44Dish->isEnabled())){ w44fzDishon=new ftpload::W223fz;
                                    ++countAdd;
                                      w44fzDishon->ftp223fz->id=4;
                                     connect(w44fzDishon->ftp223fz,SIGNAL(allFilesProcess(int)),this,SLOT(allWasLoad(int)));
                                     w44fzDishon->create44fzDish(this->edt44fzDishon->text(),
                                                                  this->tm44fzDishonBeg->dateTime(),
                                                                  this->tm44fzDishonEnd->dateTime());

                                     listDownload.push_back(w44fzDishon->ftp223fz);
                                     if(chk44fzDishonToBase->isChecked()) w44fzDishon->baseConnect();
                                     widget44Dish->setEnabled(false);
                                    }

   if(countAdd!=0) listDownload.front()->download();
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
void WUI::set44fzRegionsContr(QStringList regions)
{
 regionsContract44=regions;
}

}
//----------------------------------------------------------------------------------------------------------------
