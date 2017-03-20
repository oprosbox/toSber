#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QCalendarWidget>
#include "loadsave.h"

namespace Ui {
class MainWindow;
}
class WMainInterf : public QObject
{
    Q_OBJECT
public:
    WMainInterf();

public slots:
 void getPath(void);
 void getDateBeg();
 void getDateEnd();
 void closeDateBeg(QDate);
 void closeDateEnd(QDate);
signals:
  void setPath(QString path);
  void setDateBeg(QDate);
  void setDateEnd(QDate);
protected:
  QCalendarWidget *dialogBeg;
  QCalendarWidget *dialogEnd;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
  void getFunct(QStringList);
protected:
    WMainInterf *w223fzTendPath;
    WMainInterf *w44fzTendPath;
    WMainInterf *w223fzPath;
    WMainInterf *w44fzPath;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
