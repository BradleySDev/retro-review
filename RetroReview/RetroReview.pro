#-------------------------------------------------
#
# Project created by QtCreator 2014-03-11T19:26:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RetroReview
TEMPLATE = app


SOURCES += main.cpp\
        retroreview.cpp \
    settingsdialog.cpp \
    configurationhandler.cpp \
    loghandler.cpp

HEADERS  += retroreview.h \
    settingsdialog.h \
    configurationhandler.h \
    loghandler.h

FORMS    += retroreview.ui \
    settingsdialog.ui
