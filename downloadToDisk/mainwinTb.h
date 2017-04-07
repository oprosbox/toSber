#ifndef MAINWINTB_H
#define MAINWINTB_H

#include <QMainWindow>
#include "winterface.h"
#include "wdateline.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    WInterface interf;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    WMainInterf *tmButtons;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
