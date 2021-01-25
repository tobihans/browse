#include "btabpage.h"
#include "btoolbar.h"
#include <QVBoxLayout>
#include <QProgressBar>
#include <QToolBar>
#include <QLineEdit>
#include <QWebEngineView>
#include <QTimer>
#include <QUrl>

BTabPage::BTabPage(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlag(Qt::Widget);
    view = new QWebEngineView;
    this->setCentralWidget(view);
    initHeaders();
    connectEvents();
}

void BTabPage::initHeaders()
{
    toolBar = new BToolBar;
    toolBar->setMovable(false);
    toolBar->setMinimumHeight(40);
    toolBar->setMaximumHeight(40);
    this->addToolBar(Qt::TopToolBarArea, toolBar);
    this->addToolBarBreak(Qt::TopToolBarArea);
    progressBar = new QProgressBar;
    progressBar->setTextVisible(false);
    progressBar->setMaximumHeight(5);
    progressBar->setStyleSheet("border-radius: 0px; margin: 0px;");
    auto *progressBarParent = new QToolBar;
    progressBarParent->setMovable(false);
    progressBarParent->setMaximumHeight(8);
    progressBarParent->addWidget(progressBar);
    this->addToolBar(progressBarParent);
}

void BTabPage::connectEvents()
{
    connect(toolBar, &BToolBar::goToUrl, [this](QUrl url){
        this->view->load(url);
    });
    connect(view, &QWebEngineView::urlChanged, [this](QUrl url){
        this->toolBar->setUrl(url);
    });
    connect(view, &QWebEngineView::loadStarted, [this](){
        connect(view, &QWebEngineView::loadProgress,this, &BTabPage::showProgress);
    });
    connect(view, &QWebEngineView::loadFinished, [this](){
        disconnect(view, &QWebEngineView::loadProgress,this, &BTabPage::showProgress);
        QTimer::singleShot(200, [this](){progressBar->reset(); });
    });
    connect(toolBar, &BToolBar::goToNextPage, [this](){
        this->view->forward();
    });
    connect(toolBar, &BToolBar::goToPreviousPage, [this](){
        this->view->back();
    });
    connect(toolBar, &BToolBar::reloadPage, [this](){
        this->view->reload();
    });
    connect(toolBar, &BToolBar::goToHomePage, [this](){
        this->view->load(QUrl("https://doc.qt.io"));
    });
    connect(toolBar, &BToolBar::showMenu, [this](){
        emit newWindowRequested();
    });
}

void BTabPage::showProgress(int progress)
{
    progressBar->setValue(progress);
}
