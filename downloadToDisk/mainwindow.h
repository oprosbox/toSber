#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "interface.h"

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
  void getFunct(QStringList);
protected:
    wui::WMainInterf *w223fzTendPath;
    wui::WMainInterf *w44fzTendPath;
    wui::WMainInterf *w223fzPath;
    wui::WMainInterf *w44fzPath;
private:
    Ui::MainWindow *ui;
    wui::WUI *headUi;
};

#endif // MAINWINDOW_H
