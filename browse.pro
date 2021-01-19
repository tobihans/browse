QT       += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    btabpage.cpp \
    btabwidget.cpp \
    btoolbar.cpp \
    bwindow.cpp \
    main.cpp \
    browser.cpp

HEADERS += \
    browser.h \
    btabpage.h \
    btabwidget.h \
    btoolbar.h \
    bwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icons/arrow.svg \
    icons/bars.png \
    icons/goto.png \
    icons/home (1).png \
    icons/home (2).png \
    icons/home.png \
    icons/menu (1).png \
    icons/menu (2).png \
    icons/menu (3).png \
    icons/menu.png \
    icons/next.png \
    icons/previous.png \
    icons/reload-3.png \
    icons/reload.png \
    icons/reload3.png
