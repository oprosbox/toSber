#include "wreporttable.h"
#include <QFile>
#include <QApplication>
#include <QDir>
#include <QProcess>


WReportTable::WReportTable()
{

}
//-------------------------------------------------------------------------------------------------
void WReportTable::reportTable(QDomDocument &docIn,QDomDocument &tableOut)
{
    tableOut.appendChild(tableOut.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\""));
    reportTableRecurs(docIn,tableOut,tableOut);

}
//-------------------------------------------------------------------------------------------------
void WReportTable::reportTableRecurs(QDomNode docIn,QDomNode &docOut,QDomDocument &domDocument)
{ QDomNode table,tr,docOutNext;
  QDomNode next=docIn.firstChild();
  QDomElement nodeTemp,nodeTempVal;
  QDomElement nodeAdd=domDocument.createElement("table");
              nodeAdd.setAttribute("border","1");
              nodeAdd.setAttribute("style","background-color:#ffffff");
              docOut.appendChild(nodeAdd);
              table=docOut.lastChild();

    while(!next.isNull())
   { nodeAdd=domDocument.createElement("tr");
     table.appendChild(nodeAdd);
     tr=table.lastChild();

     nodeTemp=domDocument.createElement("td");
     nodeTemp.appendChild(domDocument.createTextNode(next.nodeName()));
     tr.appendChild(nodeTemp);

     nodeTempVal=domDocument.createElement("td");
      if(next.firstChild().isText())
      {
          nodeTempVal.appendChild(domDocument.createTextNode(next.toElement().text()));
          tr.appendChild(nodeTempVal);
      }
      else{tr.appendChild(nodeTempVal);
           docOutNext=tr.lastChild();
           reportTableRecurs(next,docOutNext,domDocument);
            }

    next=next.nextSibling();
    }

}
//-------------------------------------------------------------------------------------------------------
void WReportTable::createAndWrite(QDomDocument &docIn,QString &name,bool local)
{QString nameOriginal;
   if(local){QString localName=name;
   name=QApplication::applicationDirPath()+"/tempReport";
   QDir dirTo;
   if(dirTo.exists(name)){}
                else{dirTo.mkdir(name);
                     if(dirTo.exists(name)){}else return ;}
   name+="/"+localName;name+=".html";}

   nameOriginal=name;
   nameOriginal.resize(nameOriginal.size()-4);
   nameOriginal+=".xml";
   nameOriginal.insert(nameOriginal.lastIndexOf("/")+1,"o_");

    QFile fileWR(name);
    fileWR.open(QFile::WriteOnly);

    QFile fileWROriginal(nameOriginal);
    fileWROriginal.open(QFile::WriteOnly);

    QDomDocument WR;

    reportTable(docIn,WR);

fileWR.write(WR.toByteArray());
fileWR.close();

fileWROriginal.write(docIn.toString().toLocal8Bit());
fileWROriginal.close();
}
//---------------------------------------------------------------------------------------------------
void WReportTable::createWriteAndStart(QDomDocument &docIn,QString name)
{
  createAndWrite(docIn,name);

  QStringList comm;
  comm.push_back("/C "+name);
QProcess::execute("cmd.exe",comm);
}
//---------------------------------------------------------------------------------------------------------
void WReportTable::createWriteAndStart(QTableWidget *docIn,QString name)
{
  createAndWrite(docIn,name);

  QStringList comm;
  comm.push_back("/C "+name);
QProcess::execute("cmd.exe",comm);
}
//---------------------------------------------------------------------------------------------------------
void WReportTable::createAndWrite(QTableWidget *docIn,QString &name,bool local)
{
    if(local){QString localName=name;
    name=QApplication::applicationDirPath()+"/tempReport";
    QDir dirTo;
    if(dirTo.exists(name)){}
                 else{dirTo.mkdir(name);
                      if(dirTo.exists(name)){}else return ;}

    name+="/"+localName;

    name+=".html";}

     QFile fileWR(name);
     fileWR.open(QFile::WriteOnly);

     QDomDocument WR;

     reportTable(docIn,WR);

     fileWR.write(WR.toByteArray());
     fileWR.close();

}
//---------------------------------------------------------------------------------------------------------
void WReportTable::reportTable(QTableWidget *docIn,QDomDocument &tableOut)
{
    QDomNode table,tr,td;
    QString color;
    tableOut.appendChild(tableOut.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\""));
    QDomElement nodeAdd=tableOut.createElement("table");
                  nodeAdd.setAttribute("border","1");
                  nodeAdd.setAttribute("style","background-color:#ffffff");
                  tableOut.appendChild(nodeAdd);
                  table=tableOut.lastChild();
                  tr=tableOut.createElement("tr");
                  tr.toElement().setAttribute("style","background-color:#aaff7f");
                  for(int col=0;col<docIn->columnCount();col++)
                  {
                      td=tableOut.createElement("td");

                      if(col==3){td.toElement().setAttribute("nowrap","");}
                      td.appendChild(tableOut.createTextNode(docIn->horizontalHeaderItem(col)->text()));
                      tr.appendChild(td);
                  }
                  table.appendChild(tr);
                  for(int row=0;row<docIn->rowCount();row++)
                  {tr=tableOut.createElement("tr");
                      for(int col=0;col<docIn->columnCount();col++)
                      {
                        td=tableOut.createElement("td");
                        if(docIn->item(row,col)->backgroundColor().isValid())
                        {
                        color="rgb(";
                        color+=QString::asprintf("%i",docIn->item(row,col)->backgroundColor().red());
                        color+=",";
                        color+=QString::asprintf("%i",docIn->item(row,col)->backgroundColor().green());
                        color+=",";
                        color+=QString::asprintf("%i",docIn->item(row,col)->backgroundColor().blue());
                        color+=")";
                        }
                        else
                        {
                          color="rgb(255,255,255)";
                        }

                        td.toElement().setAttribute("style","background-color:"+color);

                        if(col==3){td.toElement().setAttribute("nowrap","");}
                        td.appendChild(tableOut.createTextNode(docIn->item(row,col)->text()));
                        tr.appendChild(td);
                      }
                   table.appendChild(tr);
                  }
    QString text=tableOut.toString();

}
//---------------------------------------------------------------------------------------------------------
