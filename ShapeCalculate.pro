#-------------------------------------------------
#
# Project created by QtCreator 2014-04-23T18:20:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShapeCalculate
TEMPLATE = app


SOURCES += main.cpp\
        calculate.cpp \
    circle.cpp \
    rectangle.cpp \
    sphere.cpp

HEADERS  += calculate.h \
    circle.h \
    rectangle.h \
    sphere.h

FORMS    += calculate.ui \
    circle.ui \
    rectangle.ui \
    sphere.ui
