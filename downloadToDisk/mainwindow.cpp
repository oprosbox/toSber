#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "findindom.h"


//WFtpClient *ftpclnt;
//ftpload::WLoadFtp *loadFtp;

//wui::QWidgetRegion *widReg;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ndom::WFind *findObj;
//    findObj=new ndom::WFind;
//    QStringList listNameTeg;
//    listNameTeg.push_back("customer");
//    listNameTeg.push_back("mainInfo");
//    listNameTeg.push_back("inn");
//    QStringList listFrom;
//    listFrom.push_back("G:/toSber/forBase223/from");
//    listFrom.push_back("G:/toSber/forBase223/purchaseNoticeAE_Moskva_20170316_000000_20170316_235959_daily_001.xml");
//    listFrom.push_back("G:/toSber/forBase223/purchaseNoticeAE94_Moskva_20170316_000000_20170316_235959_daily_001.xml");
//    listFrom.push_back("G:/toSber/forBase223/purchaseNoticeEP_Moskva_20170316_000000_20170316_235959_daily_001.xml");
//    listFrom.push_back("G:/toSber/forBase223/purchaseNoticeOA_Moskva_20170314_000000_20170314_235959_daily_001.xml");
//    listFrom.push_back("G:/toSber/forBase223/purchaseNoticeOK_Moskva_20170315_000000_20170315_235959_daily_001.xml");
//    listFrom.push_back("G:/toSber/forBase223/purchaseNoticeZK_Moskva_20170316_000000_20170316_235959_daily_001.xml");
//    findObj->createObj(listFrom,"G:/toSber/forBase223/to",listNameTeg,"7715038478");
//    findObj->startThreads();

    w223fzTendPath=new wui::WMainInterf();
    w44fzTendPath=new wui::WMainInterf();
    w223fzPath=new wui::WMainInterf();
    w44fzPath=new wui::WMainInterf();

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
    headUi->createInterf();

//    loadFtp=new ftpload::WLoadFtp;
//    ftpload::SInputFtp input;
//    input.url="ftp.zakupki.gov.ru";
//    input.login="fz223free";
//    input.password="fz223free";
//    input.countToExitDirUrl=2;
//    input.stFilt.dateBegin=QDateTime::fromString("2017-03-15","yyyy-MM-dd");
//    input.stFilt.dateEnd=QDateTime::fromString("2017-03-17","yyyy-MM-dd");
//    input.pathTo="F:/programsQt/toSber/ftpLoad/sort";
//    input.pathTemp="F:/programsQt/toSber/ftpLoad/unpack";
//    input.tegPathFind.push_back("customer");
//    input.tegPathFind.push_back("mainInfo");
//    input.tegPathFind.push_back("inn");
//    input.val="7706061801";
//    input.urlPath="out/published/Moskva";
//    input.urlList.push_back("purchaseNoticeEP/daily");
//    input.urlList.push_back("purchaseNoticeOK/daily");
//    input.urlList.push_back("purchaseNoticeOA/daily");

    //loadFtp->createFtp(input);

    //ftpload::W223fz obj;
    //QStringList regions;
    //obj.getRegions(regions);

    //connect(ui->pushButton,SIGNAL(clicked()),loadFtp,SLOT(download()));

    //ftpclnt=new WFtpClient;
    //ftpclnt->connectServ("ftp.zakupki.gov.ru","fz223free","fz223free");
    //ftpclnt->cd("out/published");
    //ftpclnt->cd("..");
    //connect(ftpclnt,SIGNAL(endOperations(QStringList)),this,SLOT(getFunct(QStringList)));
    //ftpclnt->readDirectories();

    connect(ui->btn223fzTendPath,SIGNAL(clicked()), w223fzTendPath,SLOT(getPath()));
    connect(w223fzTendPath,SIGNAL(setPath(QString)), ui->dirTand223fz,SLOT(setText(QString)));

    connect(ui->btn44fzTendPath,SIGNAL(clicked()), w44fzTendPath,SLOT(getPath()));
    connect(w44fzTendPath,SIGNAL(setPath(QString)), ui->dirTand44fz,SLOT(setText(QString)));

    connect(ui->btn223fzPath,SIGNAL(clicked()), w223fzPath,SLOT(getPath()));
    connect(w223fzPath,SIGNAL(setPath(QString)), ui->dir223fz,SLOT(setText(QString)));

    connect(ui->btn44fzPath,SIGNAL(clicked()), w44fzPath,SLOT(getPath()));
    connect(w44fzPath,SIGNAL(setPath(QString)), ui->dir44fz,SLOT(setText(QString)));

    ui->tm223fzTendBeg->setDate(QDate::currentDate());
    connect(ui->btnTmTend223fz,SIGNAL(clicked()), w223fzTendPath,SLOT(getDateBeg()));
    connect(w223fzTendPath,SIGNAL(setDateBeg(QDate)),ui->tm223fzTendBeg,SLOT(setDate(QDate)));

    ui->tm223fzTendEnd->setDate(QDate::currentDate());
    connect(ui->btnTmTend223fz_2,SIGNAL(clicked()), w223fzTendPath,SLOT(getDateEnd()));
    connect(w223fzTendPath,SIGNAL(setDateEnd(QDate)),ui->tm223fzTendEnd,SLOT(setDate(QDate)));

    ui->tm44fzTendBeg->setDate(QDate::currentDate());
    connect(ui->btnTmTend44fz,SIGNAL(clicked()), w44fzTendPath,SLOT(getDateBeg()));
    connect(w44fzTendPath,SIGNAL(setDateBeg(QDate)),ui->tm44fzTendBeg,SLOT(setDate(QDate)));

    ui->tm44fzEnd->setDate(QDate::currentDate());
    connect(ui->btnTmTend44fz_2,SIGNAL(clicked()), w44fzTendPath,SLOT(getDateEnd()));
    connect(w44fzTendPath,SIGNAL(setDateEnd(QDate)),ui->tm44fzEnd,SLOT(setDate(QDate)));

    ui->tm223fzBeg->setDate(QDate::currentDate());
    connect(ui->btnTm223fz,SIGNAL(clicked()), w223fzPath,SLOT(getDateBeg()));
    connect(w223fzPath,SIGNAL(setDateBeg(QDate)),ui->tm223fzBeg,SLOT(setDate(QDate)));

    ui->tm223fzEnd->setDate(QDate::currentDate());
    connect(ui->btnTm223fz_2,SIGNAL(clicked()), w223fzPath,SLOT(getDateEnd()));
    connect(w223fzPath,SIGNAL(setDateEnd(QDate)),ui->tm223fzEnd,SLOT(setDate(QDate)));

    ui->tm44fzBeg->setDate(QDate::currentDate());
    connect(ui->btnTm44fz,SIGNAL(clicked()), w44fzPath,SLOT(getDateBeg()));
    connect(w44fzPath,SIGNAL(setDateBeg(QDate)),ui->tm44fzBeg,SLOT(setDate(QDate)));

    ui->tm44fzEnd->setDate(QDate::currentDate());
    connect(ui->btnTm44fz_2,SIGNAL(clicked()), w44fzPath,SLOT(getDateEnd()));
    connect(w44fzPath,SIGNAL(setDateEnd(QDate)),ui->tm44fzEnd,SLOT(setDate(QDate)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getFunct(QStringList list)
{   /*QFile *file = new QFile("F:/programsQt/toSber/downloadToDisk/debug/regions.txt");
    file->open(QIODevice::WriteOnly);
    QTextStream stream(file);
    for(auto u=list.begin();u!=list.end();u++)
      {
       stream<<*u<<"\n";
      }

      file->close();
  int i=0;*/
}


