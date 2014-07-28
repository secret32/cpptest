TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    shelton_net.c \
    shelton.c \
    list.c \
    clipboard.cpp \
    main.cpp \
    thread.cpp

HEADERS += \
    shelton.h \
    shelton_net.h \
    list.h \
    clipboard.h \
    thread.h

