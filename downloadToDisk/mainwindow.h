#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "interface.h"

#include "wdateline.h"

namespace Ui {
class MainWindow;

}



class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void createTables(void);
protected:
    WMainInterf *w223fzTendPath;
    WMainInterf *w44fzTendPath;
    WMainInterf *w223fzPath;
    WMainInterf *w44fzPath;
private:
    Ui::MainWindow *ui;
    wui::WUI *headUi;
};

#endif // MAINWINDOW_H
