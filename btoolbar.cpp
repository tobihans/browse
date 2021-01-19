#include "btoolbar.h"
#include <QAction>
#include <QPixmap>
#include <QUrl>
#include <QMessageBox>

BToolBar::BToolBar(QWidget *parent) : QToolBar(parent)
{
    this->setMovable(false);
    previous = new QAction(QPixmap("icons/previous.png"), "Go to previous page");
    previous->setShortcut(tr("Alt+P"));
    this->addAction(previous);
    connect(previous, &QAction::triggered, [this](){
        emit goToPreviousPage();
    });

    next = new QAction(QPixmap("icons/next.png"), "Go to next page");
    next->setShortcut(tr("Alt+N"));
    this->addAction(next);
    connect(next, &QAction::triggered, [this](){
        emit goToNextPage();
    });

    reload = new QAction(QPixmap("icons/reload-3.png"), "Reload current page");
    reload->setShortcut(tr("Alt+R"));
    this->addAction(reload);
    connect(reload, &QAction::triggered, [this](){
        emit reloadPage();
    });

    goHome = new QAction(QPixmap("icons/home.png"), "Go to home page");
    goHome->setShortcut(tr("Alt+H"));
    this->addAction(goHome);
    this->addSeparator();
    connect(goHome, &QAction::triggered, [this](){
        emit goToHomePage();
    });

    urlField = new QLineEdit;
    urlFieldAction = new QAction(QPixmap("icons/goto.png"), "Go to given url");
    urlFieldAction->setShortcut(Qt::Key_Enter);
    connect(urlFieldAction, &QAction::triggered, [this](){
        if (!this->urlField->text().isEmpty())
            emit goToUrl(QUrl(this->urlField->text()));
            QMessageBox msg;
            msg.exec();
    });
    urlField->addAction(urlFieldAction, QLineEdit::TrailingPosition);
    this->addWidget(urlField);
    this->addSeparator();

    menu = new QAction(QPixmap("icons/bars.png"), "Menu");
    menu->setShortcut(tr("Alt+M"));
    this->addAction(menu);
    connect(menu, &QAction::triggered, [this](){
        emit showMenu();
    });
}
