#-------------------------------------------------
#
# Project created by QtCreator 2016-11-21T14:31:13
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Client
TEMPLATE = app
#DEFINES +=_UNIX

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    formhome.cpp \
    formwarning.cpp \
    formgraph.cpp \
    formpoly.cpp \
    formchart.cpp \
    formselectdata.cpp \
    networker.cpp \
    config.cpp \
    recvmsgobject.cpp \
    str.c \
    utils.cpp \
    mybutton.cpp \
    formleftview.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    formhome.h \
    formwarning.h \
    formgraph.h \
    formpoly.h \
    formchart.h \
    formselectdata.h \
    networker.h \
    config.h \
    recvmsgobject.h \
    str.h \
    utils.h \
    mybutton.h \
    formleftview.h

FORMS    += mainwindow.ui \
    formhome.ui \
    formwarning.ui \
    formgraph.ui \
    formpoly.ui \
    formchart.ui \
    formselectdata.ui \
    formleftview.ui

DISTFILES +=

RESOURCES += \
    resource.qrc
