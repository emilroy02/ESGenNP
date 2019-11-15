TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

unix|win32: LIBS += -L$$PWD/../DEV/Lib/ -lESGenNPRestos

INCLUDEPATH += $$PWD/../DEV/Include
DEPENDPATH += $$PWD/../DEV/Lib

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../DEV/Lib/ESGenNPRestos.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../DEV/Lib/libESGenNPRestos.a

unix|win32: LIBS += -L$$PWD/../DEV/Lib/ -lESGenNPCore

INCLUDEPATH += $$PWD/../DEV/Include
DEPENDPATH += $$PWD/../DEV/Include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../DEV/Lib/ESGenNPCore.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../DEV/Lib/libESGenNPCore.a
