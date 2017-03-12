#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{//this->setWindowIcon(QIcon("icon.png"));
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
