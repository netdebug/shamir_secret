QT += core
QT -= gui

CONFIG += c++11

TARGET = shamir_secret
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    create_secret.cpp \
    recovery_secret.cpp

HEADERS += \
    create_secret.h \
    recovery_secret.h
