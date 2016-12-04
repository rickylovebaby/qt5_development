#-------------------------------------------------
#
# Project created by QtCreator 2016-12-03T12:09:37
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = setting_opengl
TEMPLATE = app

LIBS += -lopengl32 -lglu32

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    +=
