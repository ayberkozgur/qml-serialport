#include "QMLSerialPort.hpp"

#include "SerialPort.hpp"

namespace qmlserialport {

    void QMLSerialPortPlugin::registerTypes(const char* uri){
        qmlRegisterType<SerialPort>(uri, 1, 0, "SerialPort");
    }

}
