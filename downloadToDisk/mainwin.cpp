#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "findindom.h"
#include <QFile>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile fLog(QApplication::applicationDirPath()+"/logfile.txt");
    fLog.open(QFile::WriteOnly);
    fLog.close();

    w223fzTendPath=new WMainInterf();
    w44fzTendPath=new WMainInterf();
    w223fzPath=new WMainInterf();
    w44fzPath=new WMainInterf();

    headUi=new wui::WUI;
    headUi->btn223fzDish=ui->btn223fzDishonRegions;
    headUi->btn223fzNotif=ui->btn223fzNotifRegions;
    headUi->btnDownloadStart=ui->pushButton;
    headUi->chk223fzNotif=ui->chkTand223fz;
    headUi->chk223fzDishon=ui->chkDis223fz;
    headUi->edt223fzNotif=ui->dirTand223fz;
    headUi->edt223fzDishon=ui->dir223fz;
    headUi->tm223fzNotifBeg=ui->tm223fzTendBeg;
    headUi->tm223fzNotifEnd=ui->tm223fzTendEnd;
    headUi->tm223fzDishonBeg=ui->tm223fzBeg;
    headUi->tm223fzDishonEnd=ui->tm223fzEnd;
    headUi->edt223fzInn=ui->lineEdit;

    headUi->btn44fzNotif=ui->btn44fzContractRegions;
    headUi->chk44fzNotif=ui->chkTand44fz;
    headUi->chk44fzDishon=ui->chkDis44fz;
    headUi->edt44fzNotif=ui->dirTand44fz;
    headUi->edt44fzDishon=ui->dir44fz;
    headUi->tm44fzNotifBeg=ui->tm44fzTendBeg;
    headUi->tm44fzNotifEnd=ui->tm44fzTendEnd;
    headUi->tm44fzDishonBeg=ui->tm44fzBeg;
    headUi->tm44fzDishonEnd=ui->tm44fzEnd;
    headUi->edt44fzInn=ui->lineEdit_3;

    headUi->chk44fzContrToBase=ui->chkBD44fzContr;
    headUi->chk223fzContrToBase=ui->chkBD223fzContr;
    headUi->chk223fzDishonToBase=ui->chkBD223fzDishon;
    headUi->chk44fzDishonToBase=ui->chkBD44fzDishon;
    headUi->w223fzNotifReg.lblRegions=ui->lblRegions223fzContr;
    headUi->w44fzNotifReg.lblRegions=ui->lblRegions44fzContr;
    headUi->w223fzDishonReg.lblRegions=ui->lblRegions223fzDishon;

   headUi->widget223Contr=ui->widget_2;
   headUi->widget44Contr=ui->widget_3;
   headUi->widget223Dish=ui->widget_4;
   headUi->widget44Dish=ui->widget_5;

    headUi->createInterf();
    connect(ui->btn223fzTendPath,SIGNAL(clicked()), w223fzTendPath,SLOT(getPath()));
    connect(w223fzTendPath,SIGNAL(setPath(QString)), ui->dirTand223fz,SLOT(setText(QString)));
    connect(ui->btn44fzTendPath,SIGNAL(clicked()), w44fzTendPath,SLOT(getPath()));
    connect(w44fzTendPath,SIGNAL(setPath(QString)), ui->dirTand44fz,SLOT(setText(QString)));
    connect(ui->btn223fzPath,SIGNAL(clicked()), w223fzPath,SLOT(getPath()));
    connect(w223fzPath,SIGNAL(setPath(QString)), ui->dir223fz,SLOT(setText(QString)));
    connect(ui->btn44fzPath,SIGNAL(clicked()), w44fzPath,SLOT(getPath()));
    connect(w44fzPath,SIGNAL(setPath(QString)), ui->dir44fz,SLOT(setText(QString)));

    w223fzTendPath->functConnDT(ui->tm223fzTendBeg,ui->btnTmTend223fz,ui->tm223fzTendEnd,ui->btnTmTend223fz_2);
    w44fzTendPath->functConnDT(ui->tm44fzTendBeg,ui->btnTmTend44fz,ui->tm44fzTendEnd,ui->btnTmTend44fz_2);
    w223fzPath->functConnDT(ui->tm223fzBeg,ui->btnTm223fz,ui->tm223fzEnd,ui->btnTm223fz_2);
    w44fzPath->functConnDT(ui->tm44fzBeg,ui->btnTm44fz,ui->tm44fzEnd,ui->btnTm44fz_2);

    connect(ui->btnCrtBd,SIGNAL(clicked()),this,SLOT(createTables()));
}
//----------------------------------------------------------------------------------------------------------------------------------------------
MainWindow::~MainWindow()
{   delete w223fzTendPath;
    delete w44fzTendPath;
    delete w223fzPath;
    delete w44fzPath;
    delete ui;
}
//----------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::createTables(void)
{
  QString mess;
  mess=WBaseWR::createTables(true,true,true,true);
  ui->statusBar->showMessage(mess,5000);
}



