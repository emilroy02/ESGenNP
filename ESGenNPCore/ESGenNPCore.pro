#-------------------------------------------------
#
# Project created by QtCreator 2019-11-05T09:52:42
#
#-------------------------------------------------

QT       -= core gui

TEMPLATE = lib
CONFIG += staticlib
CONFIG += skip_target_version_ext
CONFIG += c++11

TARGET = ESGenNPCore

VERSION_MAJOR    = 1
VERSION_MINOR    = 0
VERSION_REVISION = 0

VERSION  = $${VERSION_MAJOR}.$${VERSION_MINOR}.$${VERSION_REVISION}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

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

#common
copyToDestDir("$${PWD}/es_gennp.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_common.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_handle.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_branding.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_library.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_wrap.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_core_init.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_service.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_util_os.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_config_init.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_socket.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_socket_controller.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_socket_controller_win.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_event.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_event_source.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_module.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_module_client.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_module_server.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_runnable.h", "$${PWD}/../DEV/Include")
copyToDestDir("$${PWD}/es_gennp_runnable_looped.h", "$${PWD}/../DEV/Include")

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

SOURCES += \
    es_gennp_branding_default.cpp \
    es_gennp_core_init.cpp \
    es_gennp_service_direct.cpp \
    es_gennp_socket_controller_win.cpp \
    es_gennp_thread.cpp \
    es_gennp_module.cpp \
    es_gennp_event.cpp \
    es_gennp_event_client.cpp \
    es_gennp_library.cpp \
    es_gennp_handle.cpp \
    es_gennp_event_source.cpp \
    es_gennp_module_server.cpp \
    es_gennp_module_client.cpp \
    es_gennp_socket.cpp \
    es_gennp_runnable.cpp \
    es_gennp_runnable_looped.cpp

HEADERS += \
    es_gennp_common.h \
    es_gennp_wrap.h \
    es_gennp_branding.h \
    es_gennp_branding_default.h \
    es_gennp_config_init.h \
    es_gennp_config_init_branding.h \
    es_gennp_core_init.h \
    es_gennp_service.h \
    es_gennp_util_os.h \
    es_gennp.h \
    es_gennp_service_direct.h \
    es_gennp_socket.h \
    es_gennp_socket_controller.h \
    es_gennp_socket_controller_win.h \
    es_gennp_thread.h \
    es_gennp_module.h \
    es_gennp_event.h \
    es_gennp_event_client.h \
    es_gennp_library.h \
    es_gennp_handle.h \
    es_gennp_event_source.h \
    es_gennp_module_server.h \
    es_gennp_module_client.h \
    es_gennp_tag_client.h \
    es_gennp_tag_server.h \
    es_gennp_runnable.h \
    es_gennp_runnable_looped.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
