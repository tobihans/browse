#ifndef BTABWIDGET_H
#define BTABWIDGET_H

#include <QWidget>
#include <QTabWidget>
#include <QToolBar>
#include "btoolbar.h"
#include "btabpage.h"

class BTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    BTabWidget(QWidget *parent = nullptr);

private:

signals:
    void newWindowRequested();
};

#endif // BTABWIDGET_H
