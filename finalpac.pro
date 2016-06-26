#-------------------------------------------------
#
# Project created by QtCreator 2016-06-24T15:49:23
#
#-------------------------------------------------

QT       += core gui  \
            multimedia
QT       +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = finalpac
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    brick.cpp \
    verticaldestroyer.cpp \
    horizontaldestroyer.cpp \
    player.cpp \
    destroyer.cpp \
    key.cpp \
    health.cpp \
    score.cpp \
    treasure.cpp \
    destroyerthread.cpp \
    button.cpp \
    fire.cpp \
    inhabitantdestroyer.cpp \
    inhabthread.cpp

HEADERS  += \
    game.h \
    brick.h \
    verticaldestroyer.h \
    horizontaldestroyer.h \
    player.h \
    destroyer.h \
    key.h \
    health.h \
    score.h \
    treasure.h \
    destroyerthread.h \
    button.h \
    fire.h \
    inhabitantdestroyer.h \
    inhabthread.h

RESOURCES += \
    res.qrc

DISTFILES +=
