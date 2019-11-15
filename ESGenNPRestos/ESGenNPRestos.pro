#-------------------------------------------------
#
# Project created by QtCreator 2019-11-05T09:56:45
#
#-------------------------------------------------
QT       -= core gui

TEMPLATE = lib
CONFIG += staticlib
CONFIG += skip_target_version_ext
CONFIG += c++11

TARGET = ESGenNPRestos

VERSION_MAJOR    = 1
VERSION_MINOR    = 0
VERSION_REVISION = 0

VERSION  = $${VERSION_MAJOR}.$${VERSION_MINOR}.$${VERSION_REVISION}

DEFINES += ESGENNP_EXPORTS

//INCLUDEPATH += "$$PWD/../DEV/Include"

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += es_gennp_restos.cpp \
    es_gennp_branding_restos.cpp \
    es_gennp_library_restos.cpp

HEADERS += \
    es_gennp_branding_restos.h \
    es_gennp_library_restos.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

unix|win32: LIBS += -L$$PWD/../DEV/Lib/ -lESGenNPCore

INCLUDEPATH += $$PWD/../DEV/Include
DEPENDPATH += $$PWD/../DEV/Include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../DEV/Lib/ESGenNPCore.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../DEV/Lib/libESGenNPCore.a

## Post Build events
# copies the given files to the destination directory
defineTest(copyToDestDir) {
    files = $$1
    dir = $$2
    # replace slashes in destination path for Windows
    win32:dir ~= s,/,\\,g

    for(file, files) {
        # replace slashes in source path for Windows
        win32:file ~= s,/,\\,g

        QMAKE_POST_LINK += $$QMAKE_COPY_DIR $$shell_quote($$file) $$shell_quote($$dir) $$escape_expand(\\n\\t)
    }

    export(QMAKE_POST_LINK)
}

TARGET_SRC  = $${OUT_PWD}

win32{
    CONFIG(debug, debug|release) {
        TARGET_SRC = $${TARGET_SRC}/debug
    } else {
        TARGET_SRC = $${TARGET_SRC}/release
    }

    message("Post Build Events Windows")
    FILES_TO_COPY0 = $${TARGET_SRC}/$${TARGET}.lib
    TARGET_DEST0 = "$${PWD}/../DEV/Lib"

    copyToDestDir($$FILES_TO_COPY0, $$TARGET_DEST0)
}
