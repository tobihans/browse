#ifndef BWINDOW_H
#define BWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include "btoolbar.h"
#include "btabwidget.h"

class BWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit BWindow(QWidget *parent = nullptr);
private:
    BToolBar *sharedToolBar;
    BTabWidget *tabs;
signals:
    void newWindow();
};

#endif // BWINDOW_H
