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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QPushButton *pushButton;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QLabel *label;
    QLabel *label_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QLabel *label_6;
    QSpinBox *spinBox_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QWidget *widget_3;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QTableView *tableView;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 640);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        MainWindow->setPalette(palette);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(690, 160));
        widget->setMaximumSize(QSize(690, 160));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush5(QColor(170, 255, 127, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush6(QColor(212, 255, 191, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        QBrush brush7(QColor(85, 127, 63, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush7);
        QBrush brush8(QColor(113, 170, 84, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        widget->setPalette(palette1);
        widget->setAutoFillBackground(true);
        widget->setStyleSheet(QStringLiteral(""));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 20, 111, 23));
        pushButton->setAutoFillBackground(false);
        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(61, 90, 101, 22));
        dateEdit->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
        dateEdit_2 = new QDateEdit(widget);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(61, 120, 101, 22));
        dateEdit_2->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(41, 90, 20, 20));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(41, 120, 21, 20));
        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(161, 90, 25, 19));
        toolButton_2 = new QToolButton(widget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(161, 120, 25, 19));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 60, 101, 20));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(210, 60, 71, 16));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(370, 60, 121, 16));
        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(210, 90, 131, 22));
        spinBox->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
        spinBox_2 = new QSpinBox(widget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(370, 90, 141, 22));
        spinBox_2->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(540, 60, 101, 16));
        spinBox_3 = new QSpinBox(widget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(540, 90, 121, 22));
        spinBox_3->setAutoFillBackground(false);
        spinBox_3->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(140, 60, 21, 20));
        checkBox->setChecked(true);
        checkBox_2 = new QCheckBox(widget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(280, 60, 21, 17));
        checkBox_2->setChecked(true);
        checkBox_3 = new QCheckBox(widget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(490, 60, 21, 17));
        checkBox_3->setChecked(true);
        checkBox_4 = new QCheckBox(widget);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(640, 60, 21, 17));
        checkBox_4->setChecked(true);

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));

        gridLayout->addWidget(widget_3, 0, 1, 1, 1);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush8);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        widget_2->setPalette(palette2);
        widget_2->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(75, 23));
        pushButton_2->setMaximumSize(QSize(75, 23));

        gridLayout_2->addWidget(pushButton_2, 0, 0, 1, 1);

        tableView = new QTableView(widget_2);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout_2->addWidget(tableView, 1, 0, 1, 1);


        gridLayout->addWidget(widget_2, 1, 0, 1, 2);

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
        pushButton->setText(QApplication::translate("MainWindow", "\320\276\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\321\200\320\276\321\201", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\321\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\277\320\276", Q_NULLPTR));
        toolButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\342\204\226 \320\267\320\260\320\272\321\203\320\277\320\272\320\270", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\342\204\226 \320\277\321\200\320\276\320\264\321\203\320\272\321\206\320\270\320\270/\321\203\321\201\320\273\321\203\320\263\320\270", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\342\204\226 \320\277\320\276\320\264\321\200\320\260\320\267\320\264\320\265\320\273\320\265\320\275\320\270\321\217", Q_NULLPTR));
        checkBox->setText(QString());
        checkBox_2->setText(QString());
        checkBox_3->setText(QString());
        checkBox_4->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "\321\201\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
