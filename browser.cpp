#include "browser.h"
#include "bwindow.h"
#include <iostream>

Browser::Browser(QWidget *parent)
    : QMainWindow(parent)
{
}

Browser::~Browser()
{
}

void Browser::createWindow()
{
    auto *window = new BWindow;
    windows.append(window);
    window->show();
    connect(window, &BWindow::newWindow, [this](){
        this->createWindow();
    });
}
