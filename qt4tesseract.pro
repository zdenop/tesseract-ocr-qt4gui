TARGET = qt4tesseract
TEMPLATE = app
QT       += core gui

CONFIG += release qt plugin static

OBJECTS_DIR += temp
MOC_DIR += temp
UI_DIR += temp
RCC_DIR += temp

#INCLUDEPATH += ./

SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    src/settingsdialog.cpp

HEADERS += src/mainwindow.h \
    src/settingsdialog.h

FORMS   += ui/mainwindow.ui \
    ui/settings.ui

TRANSLATIONS += resources/translations/qt4tesseract_en.ts \
    resources/translations/qt4tesseract_et.ts \
    resources/translations/qt4tesseract_sk.ts
CODECFORTR = UTF-8

RESOURCES = resources/qt4tesseract.qrc

win32 {
  Debug:CONFIG += console
  RC_FILE = resources/qt4tesseract.rc
  Release:DEFINES += NO_CONSOLE
  updateqm.input = TRANSLATIONS
  updateqm.output = resources/translations/${QMAKE_FILE_BASE}.qm
  updateqm.commands = $$QMAKE_LRELEASE \
      -silent \
      ${QMAKE_FILE_IN} \
      -qm \
      resources/translations/${QMAKE_FILE_BASE}.qm
  updateqm.CONFIG += no_link

#  localize.depends = resources/translations/*.qm
#  localize.path = resources/translations/
#  localize.files = resources/translations/*.qm
#  localize.commands = lrelease resources/translations/*ts
}

# lrelease
isEmpty(QMAKE_LRELEASE) {
    win32:QMAKE_LRELEASE = $$[QT_INSTALL_BINS]\lrelease.exe
    else:QMAKE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease
    !exists($$QMAKE_LRELEASE):QMAKE_LRELEASE = lrelease-qt4 \
        }
    updateqm.input = TRANSLATIONS
    updateqm.output = resources/translations/${QMAKE_FILE_BASE}.qm
    updateqm.commands = $$QMAKE_LRELEASE \
        -silent \
        ${QMAKE_FILE_IN} \
        -qm \
        resources/translations/${QMAKE_FILE_BASE}.qm
    updateqm.CONFIG += no_link

    # target_predeps
    QMAKE_EXTRA_COMPILERS += updateqm
    PRE_TARGETDEPS += compiler_updateqm_make_all

#!contains(CONFIG, build_pass) system(lrelease qt4tesseract.pro)
#!contains(CONFIG, build_pass) system(lupdate qt4tesseract.pro)

