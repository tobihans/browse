#include "bwindow.h"
#include "btabpage.h"
#include "btoolbar.h"
#include <QTabWidget>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QAction>
#include <QWebEngineView>

BWindow::BWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlag(Qt::CustomizeWindowHint);
    this->setMinimumSize(450, 550);
    sharedToolBar = new BToolBar;
    tabs = new BTabWidget(this);
    connect(tabs, &QTabWidget::tabCloseRequested, [this](int i){
        if (this->tabs->count() == 1)
            this->close();
        this->tabs->removeTab(i);
    });
    connect(tabs, &BTabWidget::newWindowRequested, [this](){
        emit newWindow();
    });
    setCentralWidget(tabs);
}
