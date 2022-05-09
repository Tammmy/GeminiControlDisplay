QT += charts
QT       += core gui

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
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    configsonar.cpp \
    main.cpp \
    mainwindow.cpp \
    openglwidget.cpp \
    warninginfoconfigdialog.cpp

HEADERS += \
    configsonar.h \
    mainwindow.h \
    openglwidget.h \
    warninginfoconfigdialog.h

FORMS += \
    configsonar.ui \
    mainwindow.ui \
    warninginfoconfigdialog.ui

TRANSLATIONS += \
    ControlAndWarningBasedGemini_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    icons/grid.png \
    icons/grid_on.png \
    icons/online.png \
    icons/online_green.png \
    icons/open.png \
    icons/pause_green.png \
    icons/play_green.png \
    icons/record_red.png \
    icons/record_white.png \
    icons/reset.png \
    icons/stop_red.png \
    icons/text.png \
    icons/text_on.png
