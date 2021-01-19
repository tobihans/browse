#ifndef BTOOLBAR_H
#define BTOOLBAR_H

#include <QWidget>
#include <QToolBar>
#include <QAction>
#include <QLineEdit>
#include <QUrl>
#include <QString>

class BToolBar : public QToolBar
{
    Q_OBJECT
public:
    BToolBar(QWidget *parent = nullptr);
private:
    QAction *previous;
    QAction *next;
    QAction *reload;
    QAction *goHome;
    QAction *menu;
    QAction *urlFieldAction;
    QLineEdit *urlField;
signals:
    void goToPreviousPage();
    void goToNextPage();
    void reloadPage();
    void goToHomePage();
    void showMenu();
    void goToUrl(QUrl url);
};

#endif // BTOOLBAR_H
