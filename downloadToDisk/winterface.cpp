#include "winterface.h"
#include <QDomDocument>
#include "wreporttable.h"
#include <QApplication>
#include <QFileDialog>
#include "findindom.h"

void WInterface::createInterface()
{   base=new WBaseRD;
    base->connectToBase("LVVPC\\SQLEXPRESS","PAO_SB","lenV","oprosboxopros19");
    baseLine=QList<STypeItem>({{"ИНН подрядчика",C_TYPEITEMSTRING,NULL},
                                {"компания поставщика услуг",C_TYPEITEMSTRING,NULL},
                                {"подрядчик",C_TYPEITEMBUTTONS,NULL},
                                {"дата сделки",C_TYPEITEMSTRING,NULL},
                                {"    рег. № контракта    ",C_TYPEITEMBUTTONS,NULL},
                                {"             описание сделки         ",C_TYPEITEMSTRING,NULL},
                                {"ИНН заказчика",C_TYPEITEMSTRING,NULL},
                                {"компания заказчика",C_TYPEITEMSTRING,NULL}});
    createTable(baseLine);
    connect(tableBase,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(createDataReport(QTableWidgetItem*)));
    connect(tableBase,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(createDishonReport(QTableWidgetItem*)));
}
//-------------------------------------------------------------------------------------------------
void WInterface::refreshTable()
{
    SSelect select;
    select.tmBegin=tmBegin->dateTime();
    select.tmEnd=tmEnd->dateTime();
    QString textINN=innLine->text();
    textINN.replace(" ","");
    select.inn=textINN;
    lastSelect=select;
    //очистка памяти
    tableBase->setRowCount(0);
    for(auto it=infoTable.begin();it<infoTable.end();it++)
    {
      it->clear();
    }
    infoTable.clear();
    base->getFromBase(select);
    //заполнение таблицы
    QList<STypeItem> line;
    for(auto it=select.lstNotif.begin();it<select.lstNotif.end();it++)
    {
     line=baseLine;
     addObjectToTable(*it,line);
     infoTable.push_back(line);
    }
}
//--------------------------------------------------------------------------------------------------
void WInterface::createTable(QList<STypeItem> heads)
{tableBase->setColumnCount(heads.size());
    for(int i=0;i<heads.size();i++)
    {
        QTableWidgetItem *head_0 = new QTableWidgetItem();
        head_0->setText(heads.at(i).param);

        tableBase->setHorizontalHeaderItem(i,head_0);
        tableBase->setColumnWidth(i,heads.at(i).param.size()*10);
    }
 tableBase->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
}
//-----------------------------------------------------------------------------------------------
void WInterface::addStringToTable(QList<STypeItem> &columns)
{
    int currIndex=tableBase->rowCount();
tableBase->setRowCount(tableBase->rowCount()+1);
QTableWidgetItem *item;
int ind=0;
for(auto i=columns.begin();i<columns.end();i++)
{  item = new QTableWidgetItem();
    switch ((*i).C_TYPEITEM)
    {
    case C_TYPEITEMSTRING:
                          {item->setText((*i).param);
                         //  item->setBackground(QBrush(QImage(QApplication::applicationDirPath()+"/images/serebro1.png")));
                          tableBase->setItem(currIndex,ind,item);
                          i->widget=item;
                          break;}
   case C_TYPEITEMBUTTONS:{item->setText((*i).param);
                           item->setTextAlignment(Qt::AlignCenter);
                           item->setBackground(QBrush(QImage(QApplication::applicationDirPath()+"/images/button1.png")));
                           tableBase->setItem(currIndex,ind,item);
                           i->widget=item;}
    }
++ind;
}

}
//------------------------------------------------------------------------------------------------------
void WInterface::addObjectToTable(SNotifDishon &select,QList<STypeItem> &paramTable)
{
   auto it=paramTable.begin();

   it->param=select.inn_supp;
   ++it;
   it->param=select.name_supp;
   ++it;
   it->param="подрядчик";
   ++it;
   it->param=select.date.toString("yyyy-MM-dd");
   ++it;

   QString regNumber;
   ndom::WFindInDom::findInText(select.data,QStringList({"contractRegNumber"}),regNumber);
   it->param=regNumber;
   ++it;
   it->param=select.subjectContract;
   ++it;
   it->param=select.inn;
   ++it;
   it->param=select.name;

   addStringToTable(paramTable);

   it=paramTable.begin();
   ++it;++it;
   it->param=select.dataDishonSuplier;
   if(it->param!=""){QTableWidgetItem* item=(QTableWidgetItem*)it->widget;
                                   item->setBackground(QBrush(QImage(QApplication::applicationDirPath()+"/images/button2.png")));
                                    }
//                                  else{QPushButton* button=(QPushButton*)it->widget;
//                                         button->setStyleSheet("background-color: #ffaaff");}
   ++it;++it;
   it->param=select.data;

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
void WInterface::createBigReport()
{ QString namePath,nameDir,name;
  QDir dir;
   namePath=QFileDialog::getExistingDirectory(0,"сохранить",QApplication::applicationDirPath());
   dir.cd(namePath);
   nameDir="report_"+lastSelect.tmBegin.toString("yyyy-MM-dd")+"_"+lastSelect.tmEnd.toString("yyyy-MM-dd");
   if(lastSelect.inn!=""){nameDir+="_inn_"+lastSelect.inn;}
    dir.mkdir(nameDir);
    namePath+="/"+nameDir+"/";
    QList<WLines>::iterator it;
    QList<STypeItem>::iterator itCol;
    QString guid,inn,regNumber;
    QDomDocument dom;
    name=namePath+"aReportTable.html";
    WReportTable::createAndWrite(tableBase,name,false);

    for(it=infoTable.begin();it<infoTable.end();it++)
    {
         itCol=it->begin();inn=itCol->param;
         ++itCol;
         ++itCol;
         if(itCol->param==""){}
                         else{ndom::WFindInDom::findInText(itCol->param,QStringList({"header","guid"}),guid);
                              name="dishones_inn_"+inn+"_"+guid+".html";
                              dom.setContent(itCol->param);
                              name=namePath+name;
                              WReportTable::createAndWrite(dom,name,false);
                                 }
         ++itCol;
         ++itCol;

         dom.setContent(itCol->param);
         ndom::WFindInDom::findInText(itCol->param,QStringList({"contractRegNumber"}),regNumber);
          name="data_inn_"+inn+"_"+regNumber+".html";
          name=namePath+name;
         WReportTable::createAndWrite(dom,name,false);
    }
    infoTable.clear();
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
void WInterface::createDataReport(QTableWidgetItem* item)
{
  if(item->column()!=4) return;
QString name;
  int i=0;auto it=infoTable.begin();
  while(i!=item->row()){++i;++it;}

  auto itColumn=it->begin();

  name="сделка_ИНН_"+itColumn->param;
  ++itColumn;++itColumn;++itColumn;++itColumn;
  QDomDocument doc;
  doc.setContent(itColumn->param);
  WReportTable::createWriteAndStart(doc,name);

}
//---------------------------------------------------------------------------------------------------------
void WInterface::createDishonReport(QTableWidgetItem* item)
{
    if(item->column()!=2) return;

    int i=0;auto it=infoTable.begin();
    while(i!=item->row()){++i;++it;}
    QString name;
    auto itColumn=it->begin();
    ++itColumn;
    name="недобр_ИНН_"+itColumn->param;
    ++itColumn;
    QDomDocument doc;
    doc.setContent(itColumn->param);
    WReportTable::createWriteAndStart(doc,name);

}
//---------------------------------------------------------------------------------------------------------
void WInterface::createTableReport()
{

    WReportTable::createWriteAndStart(tableBase,"table");
}
