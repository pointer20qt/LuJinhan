#-------------------------------------------------
#
# Project created by QtCreator 2020-02-06T16:28:46
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = xiangmu
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    pripeople.cpp \
    login.cpp \
    zhuce.cpp

HEADERS  += widget.h \
    pripeople.h \
    login.h \
    zhuce.h

FORMS    += widget.ui \
    pripeople.ui \
    login.ui \
    zhuce.ui

RESOURCES += \
    touxiang.qrc \
    jiayezi.qrc \
    zhenzi.qrc

RC_ICONS = appIcon.ico
