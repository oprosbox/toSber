#-------------------------------------------------
#
# Project created by QtCreator 2017-03-18T20:50:58
#
#-------------------------------------------------

QT       += core gui
QT       += xml
QT       += network
QT       += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = downloadToDisk
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES +=\
    findindom.cpp \
    ftpclient.cpp \
    fzunpack.cpp \
    loadsave.cpp \
    qftp/qftp.cpp \
    qftp/qurlinfo.cpp \
    interface.cpp \
    tobase.cpp \
    mainwin.cpp \
    mainw.cpp \
    wdateline.cpp \
    errorsLog.cpp

HEADERS  += mainwindow.h \
    findindom.h \
    ftpclient.h \
    fzunpack.h \
    loadsave.h \
    qftp/qftp.h \
    qftp/qurlinfo.h \
    interface.h \
    tobase.h \
    wdateline.h \
    errorsLog.h

FORMS    += mainwindow.ui

RC_FILE  += sbiconDownl.rc
