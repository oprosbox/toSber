#include "mainwinTb.h"
#include "ui_winTable.h"
#include "wreporttable.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    

    QFile fLog(QApplication::applicationDirPath()+"/logfile.txt");
       fLog.open(QFile::WriteOnly);
       fLog.close();

    interf.tableBase=ui->tableWidget;
    interf.tmBegin=ui->tmBegin;
    interf.tmEnd=ui->tmEnd;
    interf.innLine=ui->lineEdit;
    interf.createInterface();
    connect(ui->btnGet,SIGNAL(clicked()),&interf,SLOT(refreshTable()));
    connect(ui->btnReportTable,SIGNAL(clicked()),&interf,SLOT(createTableReport()));
    connect(ui->btnSave,SIGNAL(clicked()),&interf,SLOT(createBigReport()));
    connect(ui->btnDishContr,SIGNAL(clicked()),&interf,SLOT(getDishonContrTable()));
    this->showMaximized();

    tmButtons=new WMainInterf();
    tmButtons->functConnDT(ui->tmBegin,ui->btnBegin,ui->tmEnd,ui->btnEnd);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
   // QFile file("G:/toSber/forBase223/from/purchaseNoticeAE_Moskva_20170316_000000_20170316_235959_daily_003.xml");
  //  file.open(QFile::ReadOnly);
  //  QDomDocument RD;
  //  RD.setContent(&file);

 //WReportTable::createWriteAndStart(RD,"ИНН");
}

MainWindow::~MainWindow()
{    delete tmButtons;
    delete ui;
}
