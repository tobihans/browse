#ifndef BTABPAGE_H
#define BTABPAGE_H

#include <QMainWindow>
#include <QWebEngineView>
#include "btoolbar.h"

class BTabPage : public QMainWindow
{
    Q_OBJECT
public:
    explicit BTabPage(QWidget *parent = nullptr);
    void setToolBar(BToolBar *tb);
    QWebEngineView *view;
signals:

};

#endif // BTABPAGE_H
