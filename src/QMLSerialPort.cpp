#include "QMLSerialPort.hpp"

#include "SerialPort.hpp"

namespace qmlserialport {

void QMLSerialPortPlugin::registerTypes(const char* uri){
    qmlRegisterType<SerialPort>(uri, 1, 0, "SerialPort");
    /*qmlRegisterType<TcpServer>(uri, 1, 0, "TcpServer");
    qmlRegisterType<TcpSocket>(uri, 1, 0, "TcpSocket");
    qmlRegisterType<QIntPtr>(uri, 1, 0, "QIntPtr");
    qmlRegisterSingletonType<TcpSocketFactory>(uri, 1, 0, "TcpSocketFactory",
                                               [] (QQmlEngine* qmlEngine, QJSEngine* jsEngine)->QObject* {
                                                   Q_UNUSED(qmlEngine)
                                                   Q_UNUSED(jsEngine)
                                                   return new TcpSocketFactory();
                                               });
    qmlRegisterType<TcpSocketEnums>(uri, 1, 0, "TcpSocketEnums");*/
}

}
