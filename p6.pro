QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculos.cpp \
    cuerpo.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    calculos.h \
    cuerpo.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${p6}/bin
else: unix:!android: target.path = /opt/$${p6}/bin
!isEmpty(target.path): INSTALLS += p6
