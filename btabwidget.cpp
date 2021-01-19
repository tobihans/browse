#include "btabwidget.h"
#include "btabpage.h"

BTabWidget::BTabWidget(QWidget *parent) :
    QTabWidget(parent)
{
    this->setDocumentMode(true);
    this->setTabsClosable(true);
    this->setTabShape(QTabWidget::Triangular);
    // First Tab
    auto *tabPage = new BTabPage;
    this->addTab(tabPage, "Home");
    auto *tabPage1 = new BTabPage;
    this->addTab(tabPage1, "Hom22e");
}

