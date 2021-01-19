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
    sharedToolBar = new BToolBar;
    tabs = new BTabWidget(this);
    setCentralWidget(tabs);
}
