/**
 * @mainpage qml-serialport
 *
 * qml-serialport contains QML wrappers for QSerialPort.
 */

#pragma once

#include <QQmlExtensionPlugin>
#include <qqml.h>

namespace qmlserialport{

/** @cond DO_NOT_DOCUMENT */

class QMLSerialPortPlugin : public QQmlExtensionPlugin {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char* uri);
};

/** @endcond */

}
