/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QPushButton *pushButton;
    QWidget *widget_2;
    QLabel *label_2;
    QLabel *label_3;
    QDateEdit *tm223fzTendBeg;
    QCheckBox *chkTand223fz;
    QDateEdit *tm223fzTendEnd;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *dirTand223fz;
    QLabel *label_4;
    QToolButton *btn223fzTendPath;
    QLabel *label_16;
    QPushButton *btnTmTend223fz;
    QPushButton *btnTmTend223fz_2;
    QWidget *widget_3;
    QLabel *label_5;
    QLabel *label_6;
    QDateEdit *tm44fzTendBeg;
    QCheckBox *chkTand44fz;
    QDateEdit *tm44fzTendEnd;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QLineEdit *dirTand44fz;
    QLabel *label_8;
    QToolButton *btn44fzTendPath;
    QLabel *label_18;
    QPushButton *btnTmTend44fz_2;
    QPushButton *btnTmTend44fz;
    QWidget *widget_4;
    QLabel *label_9;
    QLabel *label_10;
    QDateEdit *tm223fzBeg;
    QCheckBox *chkDis223fz;
    QDateEdit *tm223fzEnd;
    QLineEdit *dir223fz;
    QLabel *label_12;
    QToolButton *btn223fzPath;
    QLabel *label_19;
    QPushButton *btnTm223fz;
    QPushButton *btnTm223fz_2;
    QLabel *label_13;
    QWidget *widget_5;
    QLabel *label_14;
    QLabel *label_15;
    QDateEdit *tm44fzBeg;
    QCheckBox *chkDis44fz;
    QDateEdit *tm44fzEnd;
    QLineEdit *dir44fz;
    QLabel *label_17;
    QToolButton *btn44fzPath;
    QLabel *label_20;
    QPushButton *btnTm44fz;
    QPushButton *btnTm44fz_2;
    QLabel *label_11;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(950, 458);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 901, 411));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 75, 23));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(120, 30, 751, 71));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(74, 9, 30, 16));
        label_2->setMinimumSize(QSize(30, 0));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(221, 9, 27, 16));
        tm223fzTendBeg = new QDateEdit(widget_2);
        tm223fzTendBeg->setObjectName(QStringLiteral("tm223fzTendBeg"));
        tm223fzTendBeg->setGeometry(QRect(114, 9, 81, 20));
        tm223fzTendBeg->setMinimumSize(QSize(80, 0));
        chkTand223fz = new QCheckBox(widget_2);
        chkTand223fz->setObjectName(QStringLiteral("chkTand223fz"));
        chkTand223fz->setGeometry(QRect(9, 10, 59, 17));
        tm223fzTendEnd = new QDateEdit(widget_2);
        tm223fzTendEnd->setObjectName(QStringLiteral("tm223fzTendEnd"));
        tm223fzTendEnd->setGeometry(QRect(262, 9, 80, 20));
        tm223fzTendEnd->setMinimumSize(QSize(80, 0));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(390, 10, 31, 21));
        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(420, 10, 111, 20));
        dirTand223fz = new QLineEdit(widget_2);
        dirTand223fz->setObjectName(QStringLiteral("dirTand223fz"));
        dirTand223fz->setGeometry(QRect(60, 40, 471, 20));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 40, 31, 21));
        btn223fzTendPath = new QToolButton(widget_2);
        btn223fzTendPath->setObjectName(QStringLiteral("btn223fzTendPath"));
        btn223fzTendPath->setGeometry(QRect(540, 40, 25, 19));
        label_16 = new QLabel(widget_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(620, 40, 91, 16));
        btnTmTend223fz = new QPushButton(widget_2);
        btnTmTend223fz->setObjectName(QStringLiteral("btnTmTend223fz"));
        btnTmTend223fz->setGeometry(QRect(190, 7, 21, 23));
        btnTmTend223fz_2 = new QPushButton(widget_2);
        btnTmTend223fz_2->setObjectName(QStringLiteral("btnTmTend223fz_2"));
        btnTmTend223fz_2->setGeometry(QRect(340, 7, 21, 23));
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(120, 110, 751, 71));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(74, 9, 30, 16));
        label_5->setMinimumSize(QSize(30, 0));
        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(221, 9, 27, 16));
        tm44fzTendBeg = new QDateEdit(widget_3);
        tm44fzTendBeg->setObjectName(QStringLiteral("tm44fzTendBeg"));
        tm44fzTendBeg->setGeometry(QRect(115, 9, 80, 20));
        tm44fzTendBeg->setMinimumSize(QSize(80, 0));
        chkTand44fz = new QCheckBox(widget_3);
        chkTand44fz->setObjectName(QStringLiteral("chkTand44fz"));
        chkTand44fz->setGeometry(QRect(9, 10, 59, 17));
        tm44fzTendEnd = new QDateEdit(widget_3);
        tm44fzTendEnd->setObjectName(QStringLiteral("tm44fzTendEnd"));
        tm44fzTendEnd->setGeometry(QRect(262, 9, 80, 20));
        tm44fzTendEnd->setMinimumSize(QSize(80, 0));
        label_7 = new QLabel(widget_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(390, 10, 31, 21));
        lineEdit_3 = new QLineEdit(widget_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(420, 10, 111, 20));
        dirTand44fz = new QLineEdit(widget_3);
        dirTand44fz->setObjectName(QStringLiteral("dirTand44fz"));
        dirTand44fz->setGeometry(QRect(60, 40, 471, 20));
        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 40, 31, 21));
        btn44fzTendPath = new QToolButton(widget_3);
        btn44fzTendPath->setObjectName(QStringLiteral("btn44fzTendPath"));
        btn44fzTendPath->setGeometry(QRect(540, 40, 25, 19));
        label_18 = new QLabel(widget_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(620, 40, 91, 16));
        btnTmTend44fz_2 = new QPushButton(widget_3);
        btnTmTend44fz_2->setObjectName(QStringLiteral("btnTmTend44fz_2"));
        btnTmTend44fz_2->setGeometry(QRect(340, 7, 21, 23));
        btnTmTend44fz = new QPushButton(widget_3);
        btnTmTend44fz->setObjectName(QStringLiteral("btnTmTend44fz"));
        btnTmTend44fz->setGeometry(QRect(190, 7, 21, 23));
        label_5->raise();
        label_6->raise();
        tm44fzTendBeg->raise();
        chkTand44fz->raise();
        tm44fzTendEnd->raise();
        label_7->raise();
        lineEdit_3->raise();
        dirTand44fz->raise();
        label_8->raise();
        btn44fzTendPath->raise();
        label_18->raise();
        btnTmTend44fz_2->raise();
        btnTmTend44fz->raise();
        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(120, 230, 741, 71));
        label_9 = new QLabel(widget_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(74, 9, 30, 16));
        label_9->setMinimumSize(QSize(30, 0));
        label_10 = new QLabel(widget_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(221, 9, 27, 16));
        tm223fzBeg = new QDateEdit(widget_4);
        tm223fzBeg->setObjectName(QStringLiteral("tm223fzBeg"));
        tm223fzBeg->setGeometry(QRect(115, 9, 80, 20));
        tm223fzBeg->setMinimumSize(QSize(80, 0));
        chkDis223fz = new QCheckBox(widget_4);
        chkDis223fz->setObjectName(QStringLiteral("chkDis223fz"));
        chkDis223fz->setGeometry(QRect(9, 10, 59, 17));
        tm223fzEnd = new QDateEdit(widget_4);
        tm223fzEnd->setObjectName(QStringLiteral("tm223fzEnd"));
        tm223fzEnd->setGeometry(QRect(262, 9, 80, 20));
        tm223fzEnd->setMinimumSize(QSize(80, 0));
        dir223fz = new QLineEdit(widget_4);
        dir223fz->setObjectName(QStringLiteral("dir223fz"));
        dir223fz->setGeometry(QRect(60, 40, 471, 20));
        label_12 = new QLabel(widget_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 40, 31, 21));
        btn223fzPath = new QToolButton(widget_4);
        btn223fzPath->setObjectName(QStringLiteral("btn223fzPath"));
        btn223fzPath->setGeometry(QRect(540, 40, 25, 19));
        label_19 = new QLabel(widget_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(620, 40, 91, 16));
        btnTm223fz = new QPushButton(widget_4);
        btnTm223fz->setObjectName(QStringLiteral("btnTm223fz"));
        btnTm223fz->setGeometry(QRect(190, 7, 21, 23));
        btnTm223fz_2 = new QPushButton(widget_4);
        btnTm223fz_2->setObjectName(QStringLiteral("btnTm223fz_2"));
        btnTm223fz_2->setGeometry(QRect(340, 7, 21, 23));
        label_13 = new QLabel(widget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(120, 200, 171, 16));
        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(120, 310, 751, 71));
        label_14 = new QLabel(widget_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(74, 9, 30, 16));
        label_14->setMinimumSize(QSize(30, 0));
        label_15 = new QLabel(widget_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(221, 9, 27, 16));
        tm44fzBeg = new QDateEdit(widget_5);
        tm44fzBeg->setObjectName(QStringLiteral("tm44fzBeg"));
        tm44fzBeg->setGeometry(QRect(115, 9, 80, 20));
        tm44fzBeg->setMinimumSize(QSize(80, 0));
        chkDis44fz = new QCheckBox(widget_5);
        chkDis44fz->setObjectName(QStringLiteral("chkDis44fz"));
        chkDis44fz->setGeometry(QRect(9, 10, 59, 17));
        tm44fzEnd = new QDateEdit(widget_5);
        tm44fzEnd->setObjectName(QStringLiteral("tm44fzEnd"));
        tm44fzEnd->setGeometry(QRect(262, 9, 80, 20));
        tm44fzEnd->setMinimumSize(QSize(80, 0));
        dir44fz = new QLineEdit(widget_5);
        dir44fz->setObjectName(QStringLiteral("dir44fz"));
        dir44fz->setGeometry(QRect(60, 40, 471, 20));
        label_17 = new QLabel(widget_5);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(20, 40, 31, 21));
        btn44fzPath = new QToolButton(widget_5);
        btn44fzPath->setObjectName(QStringLiteral("btn44fzPath"));
        btn44fzPath->setGeometry(QRect(540, 40, 25, 19));
        label_20 = new QLabel(widget_5);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(620, 40, 91, 16));
        btnTm44fz = new QPushButton(widget_5);
        btnTm44fz->setObjectName(QStringLiteral("btnTm44fz"));
        btnTm44fz->setGeometry(QRect(190, 7, 21, 23));
        btnTm44fz_2 = new QPushButton(widget_5);
        btnTm44fz_2->setObjectName(QStringLiteral("btnTm44fz_2"));
        btnTm44fz_2->setGeometry(QRect(340, 7, 21, 23));
        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(120, 10, 51, 16));
        pushButton->raise();
        widget_2->raise();
        widget_3->raise();
        widget_4->raise();
        label_13->raise();
        widget_5->raise();
        label_11->raise();
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "download", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "       \321\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "     \320\277\320\276", Q_NULLPTR));
        chkTand223fz->setText(QApplication::translate("MainWindow", "223-\320\244\320\227", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\270\320\275\320\275", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("MainWindow", "7707083893", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\320\272\321\203\320\264\320\260", Q_NULLPTR));
        btn223fzTendPath->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "\320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\276:", Q_NULLPTR));
        btnTmTend223fz->setText(QString());
        btnTmTend223fz_2->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "       \321\201", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "     \320\277\320\276", Q_NULLPTR));
        chkTand44fz->setText(QApplication::translate("MainWindow", "44-\320\244\320\227", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\320\270\320\275\320\275", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("MainWindow", "7707083893", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\320\272\321\203\320\264\320\260", Q_NULLPTR));
        btn44fzTendPath->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "\320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\276:", Q_NULLPTR));
        btnTmTend44fz_2->setText(QString());
        btnTmTend44fz->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "       \321\201", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "     \320\277\320\276", Q_NULLPTR));
        chkDis223fz->setText(QApplication::translate("MainWindow", "223-\320\244\320\227", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\320\272\321\203\320\264\320\260", Q_NULLPTR));
        btn223fzPath->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "\320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\276:", Q_NULLPTR));
        btnTm223fz->setText(QString());
        btnTm223fz_2->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "\320\275\320\265\320\264\320\276\320\261\321\200\320\276\321\201\320\276\320\262\320\265\321\201\321\202\320\275\321\213\320\265 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\270", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "       \321\201", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "     \320\277\320\276", Q_NULLPTR));
        chkDis44fz->setText(QApplication::translate("MainWindow", "44-\320\244\320\227", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "\320\272\321\203\320\264\320\260", Q_NULLPTR));
        btn44fzPath->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "\320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\276:", Q_NULLPTR));
        btnTm44fz->setText(QString());
        btnTm44fz_2->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "\321\202\320\265\320\275\320\264\320\265\321\200\321\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
