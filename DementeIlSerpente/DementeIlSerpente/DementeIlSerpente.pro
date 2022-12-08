QMAKE_CXXFLAGS+= -std=c++11
#-------------------------------------------------
#
# Project created by QtCreator 2022-12-06T17:17:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DementeIlSerpente
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dementeilserpente.cpp

HEADERS  += mainwindow.h \
    dementeilserpente.h

FORMS    += mainwindow.ui
