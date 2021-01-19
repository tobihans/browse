#include "browser.h"
#include "bwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Browser browser;
    browser.createWindow();
    return a.exec();
}
