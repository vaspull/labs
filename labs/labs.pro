QT += core
QT -= gui

CONFIG += c++11

QMAKE_CXXFLAGS += -Wall -O2

TARGET = labs
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp
