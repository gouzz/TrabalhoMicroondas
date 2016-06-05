#-------------------------------------------------
#
# Project created by QtCreator 2016-05-16T16:20:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetoProgramacao
TEMPLATE = app


SOURCES += main.cpp\
        formamicroondas.cpp \
    cmicroondas.cpp \
    ctemporizador.cpp \
    calimentos.cpp \
    ccozinhasaudavel.cpp

HEADERS  += \
    formamicroondas.h \
    estadomicroondas.h \
    cmicroondas.h \
    ctemporizador.h \
    estadodial.h \
    programa.h \
    calimentos.h \
    ccozinhasaudavel.h

FORMS    += formamicroondas.ui

DISTFILES += \
    Resorces/Micro_interior.jpg

RESOURCES += \
    pic.qrc
