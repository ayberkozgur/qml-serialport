import QtQuick 2.2
import QtQuick.Window 2.3
import QtQuick.Controls 1.2

import QMLSerialPort 1.0

ApplicationWindow {
    id: window
    visible: true
    minimumHeight: height
    minimumWidth: width
    width: Screen.width/4
    height: col.height


    SerialPort{
        id: serialPort
        portName: portName.text
        baudRate: parseInt(baudRate.text)
        parity: parity.model.get(parity.currentIndex).choice
        flowControl: flowControl.model.get(flowControl.currentIndex).choice
        stopBits: stopBits.model.get(stopBits.currentIndex).choice

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

    Column{
        id: col
        spacing: 5

        TextField{
            id: portName
            width: window.width
            text: "COM4"
            placeholderText: "Port name (e.g COM4 or /dev/ttyUSB0)"
        }
        TextField{
            id: baudRate
            width: window.width
            text: "921600"
            placeholderText: "Baud rate (e.g 115200)"
        }
        ComboBox {
            id: parity
            currentIndex: 0
            model: ListModel {
                ListElement { text: "No parity"; choice: SerialPort.NoParity }
                ListElement { text: "Even parity"; choice: SerialPort.EvenParity }
                ListElement { text: "Odd parity"; choice: SerialPort.OddParity }
                ListElement { text: "Space parity"; choice: SerialPort.SpaceParity }
                ListElement { text: "Mark parity"; choice: SerialPort.MarkParity }
            }
            width: window.width
        }
        ComboBox {
            id: flowControl
            currentIndex: 0
            model: ListModel {
                ListElement { text: "No flow control"; choice: SerialPort.NoFlowControl }
                ListElement { text: "Hardware control"; choice: SerialPort.HardwareControl }
                ListElement { text: "Software control"; choice: SerialPort.SoftwareControl }
            }
            width: window.width
        }
        ComboBox {
            id: stopBits
            currentIndex: 0
            model: ListModel {
                ListElement { text: "One stop bit"; choice: SerialPort.OneStop }
                ListElement { text: "One half stop bit"; choice: SerialPort.OneAndHalfStop }
                ListElement { text: "Two stop bits"; choice: SerialPort.TwoStop }
            }
            width: window.width
        }
        Button {
            text: "Open"
            onClicked: serialPort.open()
        }
    }
}
