TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    shelton_net.c \
    shelton.c \
    list.c

HEADERS += \
    shelton.h \
    shelton_net.h \
    list.h

