#include "mainwinTb.h"
#include "ui_mainwinTb.h"
#include "tobase.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{  //this->setWindowIcon(QIcon("icon.png"));
    ui->setupUi(this);
   //WToBASE toBASE;
   // bool ok;

   // ok=toBASE.openMySQL();
   //int i=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
