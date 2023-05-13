#-------------------------------------------------
#
# Project created by QtCreator 2023-04-05T00:42:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Zadaca
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        dialog.cpp \
    stanje.cpp \
    tranzicija.cpp

HEADERS  += dialog.h \
    stanje.h \
    tranzicija.h

FORMS    += dialog.ui
