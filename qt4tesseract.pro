TARGET = qt4tesseract
TEMPLATE = app
QT       += core gui

CONFIG += release

OBJECTS_DIR += temp
MOC_DIR += temp
UI_DIR += temp
RCC_DIR += temp

SOURCES += src/main.cpp \
           src/mainwindow.cpp
HEADERS  += src/mainwindow.h

FORMS    += ui/mainwindow.ui

#RC_FILE = qt4tesseract.rc
