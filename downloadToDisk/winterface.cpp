#include "winterface.h"
#include <QDomDocument>
#include "wreporttable.h"
#include <QApplication>
#include <QFileDialog>
#include "findindom.h"
#include <algorithm>
#include <list>
#include <QHeaderView>


void WInterface::createInterface()
{   base=new WBaseRD;

    QFile fConn(QApplication::applicationDirPath()+"/initFile.txt");
       fConn.open(QFile::ReadOnly);
       QString connStr=fConn.readAll();
       fConn.close();
    base->connectToBase(connStr,"PAO_SB","lenV","oprosboxopros19");
    baseLine=QList<STypeItem>({{"ИНН подрядчика",C_TYPEITEMSTRING,NULL},
                                {"компания поставщика услуг",C_TYPEITEMSTRING,NULL},
                                {"подрядчик",C_TYPEITEMBUTTONS,NULL},
                                {"дата сделки",C_TYPEITEMSTRING,NULL},
                                {"    рег. № контракта    ",C_TYPEITEMBUTTONS,NULL},
                                {"             описание сделки         ",C_TYPEITEMSTRING,NULL},
                                {"ИНН заказчика",C_TYPEITEMSTRING,NULL},
                                {"компания заказчика",C_TYPEITEMSTRING,NULL}});
    createTable(baseLine);
    connect(tableBase,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(createDataReport(QTableWidgetItem*)));
    connect(tableBase,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(createDishonReport(QTableWidgetItem*)));
    connect(tableBase,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(addInn(QTableWidgetItem*)));
    connect(tableBase->horizontalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(sortTable(int)));
}
//--------------------------------------------------------------------------------------------------
void WInterface::getDishonContrTable()
{
  refreshTableComm("getDishon");
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
    for(auto it=infoTable.begin();it!=infoTable.end();it++)
    {
      it->clear();
    }
    infoTable.clear();
    base->getFromBase(select);
    //заполнение таблицы
    QList<STypeItem> line;
    for(auto it=select.lstNotif.begin();it!=select.lstNotif.end();it++)
    {
     line=baseLine;
     addObjectToTable(*it,line);
     infoTable.push_back(line);
    }
    sortTable(3);
}
//-------------------------------------------------------------------------------------------------
void WInterface::refreshTableComm(QString comm)
{
    SSelect select;
    select.tmBegin=tmBegin->dateTime();
    select.tmEnd=tmEnd->dateTime();
    select.inn=comm;
    lastSelect=select;
    //очистка памяти
    tableBase->setRowCount(0);
    for(auto it=infoTable.begin();it!=infoTable.end();it++)
    {
      it->clear();
    }
    infoTable.clear();
    base->getFromBase(select);
    //заполнение таблицы
    QList<STypeItem> line;
    for(auto it=select.lstNotif.begin();it!=select.lstNotif.end();it++)
    {
     line=baseLine;
     addObjectToTable(*it,line);
     infoTable.push_back(line);
    }
    sortTable(3);
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
   it->data=select.dataDishonSuplier;
   ++it;
   it->param=select.date.toString("yyyy-MM-dd");
   ++it;

   QString regNumber;
   ndom::WFindInDom::findInText(select.data,QStringList({"contractRegNumber"}),regNumber);
   it->param=regNumber;
   it->data=select.data;
   ++it;
   it->param=select.subjectContract;
   ++it;
   it->param=select.inn;
   ++it;
   it->param=select.name;

   addStringToTable(paramTable);

   it=paramTable.begin();
   ++it;++it;

   if(it->data!=""){QTableWidgetItem* item=(QTableWidgetItem*)it->widget;
                                   item->setBackground(QBrush(QImage(QApplication::applicationDirPath()+"/images/button2.png")));
                                    }
    ++it;
       QTableWidgetItem* item=(QTableWidgetItem*)it->widget;
        item->setTextAlignment(Qt::AlignCenter);


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
    QList<STypeItem>::iterator itCol;
    QString guid,inn,regNumber;
    QDomDocument dom;
    name=namePath+"aReportTable.html";
    WReportTable::createAndWrite(tableBase,name,false);
    flgByRet=true;
    for(auto it=infoTable.begin();it!=infoTable.end();it++)
    {
         itCol=it->begin();inn=itCol->param;
         ++itCol;
         ++itCol;
         if(itCol->data==""){}
                         else{ndom::WFindInDom::findInText(itCol->data,QStringList({"header","guid"}),guid);
                              name="dishones_inn_"+inn+"_"+guid+".html";
                              dom.setContent(itCol->data);
                              name=namePath+name;
                              WReportTable::createAndWrite(dom,name,false);
                                 }
         ++itCol;
         ++itCol;
         dom.setContent(itCol->data);
         ndom::WFindInDom::findInText(itCol->data,QStringList({"contractRegNumber"}),regNumber);
          name="data_inn_"+inn+"_"+regNumber+".html";
          name=namePath+name;
         WReportTable::createAndWrite(dom,name,false);
    }
    //infoTable.clear();
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
  doc.setContent(itColumn->data);
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

    name="недобр_ИНН_"+itColumn->param;
    ++itColumn;++itColumn;
    QDomDocument doc;
    doc.setContent(itColumn->data);
    WReportTable::createWriteAndStart(doc,name);

}

//---------------------------------------------------------------------------------------------------------
void WInterface::addInn(QTableWidgetItem* item)
{
    if(item->column()!=0) return;
    innLine->setText(item->text());

}
//---------------------------------------------------------------------------------------------------------
void WInterface::createTableReport()
{

    WReportTable::createWriteAndStart(tableBase,"table");
}
//---------------------------------------------------------------------------------------------------------
void WInterface::refreshTableByList(void)
{
tableBase->setRowCount(0);
 for(auto it=infoTable.begin();it!=infoTable.end();it++)
 {
     addStringToTable(*it);
     auto itColumn=it->begin();++itColumn;++itColumn;
     if(itColumn->data!=""){QTableWidgetItem* item=(QTableWidgetItem*)itColumn->widget;
                                     item->setBackground(QBrush(QImage(QApplication::applicationDirPath()+"/images/button2.png")));
                                      }
     ++itColumn;
        QTableWidgetItem* item=(QTableWidgetItem*)itColumn->widget;
         item->setTextAlignment(Qt::AlignCenter);
 }

}
//----------------------------------------------------------------------------------------------------------
void WInterface::sortTable(int ind)
{ flgByRet=!flgByRet;
  if(ind==3)
  {
   std::sort(infoTable.begin(),infoTable.end(),PSortLinesByDate(flgByRet));
   refreshTableByList();
  }

}
