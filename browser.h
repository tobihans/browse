#ifndef BROWSER_H
#define BROWSER_H

#include <QMainWindow>
#include <QVector>
#include "bwindow.h"

class Browser : public QMainWindow
{
    Q_OBJECT

public:
    Browser(QWidget *parent = nullptr);
    ~Browser();
    void createWindow();
private:
    QVector<BWindow*> windows;
};
#endif // BROWSER_H
