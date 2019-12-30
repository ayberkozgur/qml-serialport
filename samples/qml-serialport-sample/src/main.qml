import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.2

import QMLSerialPort 1.0

ApplicationWindow {
    id: window
    visible: true
    minimumHeight: height
    minimumWidth: width

    SerialPort{
        portName: "COM4"
        baudRate: 921600
        parity: SerialPort.NoParity

        Component.onCompleted: open()

        property var buffer: ""

        onDataReceived: {
            buffer += data;
            var end = buffer.indexOf("\r\n");
            if(end >= 0){
                console.log(buffer.substring(0,end));
                buffer = buffer.substring(end + 2);
            }
        }
    }
}
