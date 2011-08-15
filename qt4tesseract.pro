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


TRANSLATIONS += resources/translations/qt4tesseract_en.ts \
    resources/translations/qt4tesseract_sk.ts
CODECFORTR = UTF-8

RESOURCES = resources/qt4tesseract.qrc

win32 {
  Debug:CONFIG += console

  Release:DEFINES += NO_CONSOLE
  updateqm.input = TRANSLATIONS
  updateqm.output = resources/translations/${QMAKE_FILE_BASE}.qm
  updateqm.commands = $$QMAKE_LRELEASE \
      -silent \
      ${QMAKE_FILE_IN} \
      -qm \
      resources/translations/${QMAKE_FILE_BASE}.qm
  updateqm.CONFIG += no_link

  localize.depends = resources/translations/*.qm
  localize.path = resources/translations/
  localize.files = resources/translations/*.qm
  localize.commands = lrelease resources/translations/*ts
  #RC_FILE = resources/qt4tesseract.rc
}
