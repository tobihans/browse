#include "btabpage.h"
#include "btoolbar.h"
#include <QToolBar>
#include <QLineEdit>
#include <QWebEngineView>
#include <QUrl>

BTabPage::BTabPage(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlag(Qt::Widget);
    view = new QWebEngineView;
    this->setCentralWidget(view);
    auto *tb = new BToolBar;
    this->addToolBar(tb);
    connect(tb, &BToolBar::goToUrl, [this, tb](QUrl url){
        this->view->load(url);
    });
}

