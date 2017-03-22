#include "interface.h"


namespace  wui {

void  QWidgetRegion::addCheck(bool flg)
{
    for(auto i=chkRegions.begin()+1;i!=chkRegions.end();i++)
    {(*i)->setChecked(flg);}
}

//------------------
void QWidgetRegion::create(QStringList &regions)
{QCheckBox *check;int posx=0;int posy=0;
 this->setGeometry(50,50,640,800);
 check=new QCheckBox(this);

 if(posx%600==0)posy+=30;
 check->setGeometry(20,posy,120,25);
 check->setText("Все регионы");
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
    chkRegions.push_back(check);
   }
}
//--------------------------------------------------------------------------------------------------------
QStringList QWidgetRegion::listCurrRegions()
{ QStringList list;
  for(auto i=chkRegions.begin()+1;i!=chkRegions.end();i++)
  {if((*i)->isChecked()){list.push_back((*i)->text());}}
  return list;
}

//------------------------------------------------------------------------------------------------------------
void WUI::btnStart(void)
{QStringList regions;
   if(chk223fzNotif->isChecked()) { getRegionsNotif(regions);
                                    w223fzNotif.create223fzNotif(this->edt223fzNotif->text(),
                                                                 regions,
                                                                 this->tm223fzNotifBeg->dateTime(),
                                                                 this->tm223fzNotifEnd->dateTime(),
                                                                 this->edt223fzInn->text());}
   if(chk223fzDishon->isChecked()) { getRegionsDishon(regions);
                                     w223fzDishon.create223fzDish(this->edt223fzNotif->text(),
                                                                  regions,
                                                                  this->tm223fzNotifBeg->dateTime(),
                                                                  this->tm223fzNotifEnd->dateTime());
                                    }
}

//-----------------------------------------------------------------------------------------------------------
void WUI::getRegionsNotif(QStringList &regions)
{

}
//------------------------------------------------------------------------------------------------------------
void WUI::getRegionsDishon(QStringList &regions)
{

}

}
