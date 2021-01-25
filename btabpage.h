#ifndef BTABPAGE_H
#define BTABPAGE_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QProgressBar>
#include "btoolbar.h"

class BTabPage : public QMainWindow
{
    Q_OBJECT
public:
    explicit BTabPage(QWidget *parent = nullptr);

private slots:
    void showProgress(int);

private:
    void initHeaders();
    void connectEvents();
    QWebEngineView *view;
    QProgressBar *progressBar;
    BToolBar *toolBar;
signals:
    void newWindowRequested();
};

#endif // BTABPAGE_H
