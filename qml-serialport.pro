TEMPLATE = lib
TARGET = qmlserialportplugin

CONFIG += qt plugin c++11

QT += qml quick serialport

unix{
    QMAKE_CXXFLAGS -= -O2
    QMAKE_CXXFLAGS_RELEASE -= -O2

    QMAKE_CXXFLAGS += -O3
    QMAKE_CXXFLAGS_RELEASE += -O3
}

win32 {
    QMAKE_CXXFLAGS += /std:c++14
    QMAKE_CXXFLAGS_RELEASE += /std:c++14
}

TARGET = $$qtLibraryTarget($$TARGET)
uri = QMLSerialPort

HEADERS += \
    src/QMLSerialPort.hpp \
    src/SerialPort.hpp

SOURCES += \
    src/QMLSerialPort.cpp \
    src/SerialPort.cpp

OTHER_FILES += qmldir

#Install plugin library, qmldir
qmldir.files = qmldir
installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
qmldir.path = $$installPath
target.path = $$installPath
INSTALLS += target qmldir
