#include "SerialPort.hpp"

#include <QByteArray>

namespace qmlserialport {

    SerialPort::SerialPort(QQuickItem* parent):
        QQuickItem(parent),
        portName_(""),
        baudRate_(115200),
        dataBits_(8),
        flowControl_(NoFlowControl),
        parity_(NoParity),
        stopBits_(OneStop) {
        connect(&serialPort, SIGNAL(readyRead()), this, SLOT(readyRead()));
    }

    void SerialPort::setPortName(QString portName){
        portName_ = portName;
        emit portNameChanged();
    }

    void SerialPort::setBaudRate(int baudRate){
        if(baudRate <= 0){
            qDebug() << "Baud rate must be positive, setting to 115200";
            baudRate_ = 115200;
        }
        else
            baudRate_ = baudRate;
        emit baudRateChanged();
    }

    void SerialPort::setDataBits(int dataBits){
        if(dataBits < 5 || 8 < dataBits){
            qDebug() << "Data bits must be between 5 and 8, setting to 8";
            dataBits_ = 8;
        }
        else
            dataBits_ = dataBits;
        emit dataBitsChanged();
    }

    void SerialPort::setFlowControl(FlowControl flowControl){
        flowControl_ = flowControl;
        emit flowControlChanged();
    }

    void SerialPort::setParity(Parity parity){
        parity_ = parity;
        emit parityChanged();
    }

    void SerialPort::setStopBits(StopBits stopBits){
        stopBits_ = stopBits;
        emit stopBitsChanged();
    }

    void SerialPort::open(){
        serialPort.close();
        serialPort.setPortName(portName_);
        serialPort.setBaudRate(baudRate_);
        serialPort.setDataBits(static_cast<QSerialPort::DataBits>(dataBits_));
        serialPort.setFlowControl(static_cast<QSerialPort::FlowControl>(flowControl_));
        serialPort.setParity(static_cast<QSerialPort::Parity>(parity_));
        serialPort.setStopBits(static_cast<QSerialPort::StopBits>(stopBits_));
        serialPort.open(QIODevice::ReadWrite);
    }

    void SerialPort::close(){
        serialPort.close();
    }

    void SerialPort::sendData(QString data){
        serialPort.write(data.toUtf8());
    }

    void SerialPort::readyRead(){
        emit dataReceived(serialPort.readAll());
    }

}
