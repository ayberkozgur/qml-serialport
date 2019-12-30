#pragma once

#include <QQuickItem>
#include <QSerialPort>
#include <QString>

namespace qmlserialport {

    /**
     * @brief QML wrapper for QSerialPort
     */
    class SerialPort : public QQuickItem {
        /* *INDENT-OFF* */
        Q_OBJECT
        /* *INDENT-ON* */

        Q_PROPERTY(QString portName READ portName WRITE setPortName NOTIFY portNameChanged)
        Q_PROPERTY(int baudRate READ baudRate WRITE setBaudRate NOTIFY baudRateChanged)
        Q_PROPERTY(int dataBits READ dataBits WRITE setDataBits NOTIFY dataBitsChanged)
        Q_PROPERTY(FlowControl flowControl READ flowControl WRITE setFlowControl NOTIFY flowControlChanged)
        Q_PROPERTY(Parity parity READ parity WRITE setParity NOTIFY parityChanged)
        Q_PROPERTY(StopBits stopBits READ stopBits WRITE setStopBits NOTIFY stopBitsChanged)

    public:
        enum FlowControl {
            NoFlowControl = QSerialPort::NoFlowControl,
            HardwareControl = QSerialPort::HardwareControl,
            SoftwareControl = QSerialPort::SoftwareControl
        };
        Q_ENUM(FlowControl)

        enum Parity {
            NoParity = QSerialPort::NoParity,
            EvenParity = QSerialPort::EvenParity,
            OddParity  = QSerialPort::OddParity,
            SpaceParity = QSerialPort::SpaceParity,
            MarkParity = QSerialPort::MarkParity
        };
        Q_ENUM(Parity)

        enum StopBits {
            OneStop = QSerialPort::OneStop,
            OneAndHalfStop = QSerialPort::OneAndHalfStop,
            TwoStop = QSerialPort::TwoStop
        };
        Q_ENUM(StopBits)

        /** @cond DO_NOT_DOCUMENT */
        SerialPort(QQuickItem* parent = 0);
        virtual ~SerialPort() = default;

        QString portName(){
            return portName_;
        }

        int baudRate(){
            return baudRate_;
        }

        int dataBits(){
            return dataBits_;
        }

        FlowControl flowControl(){
            return flowControl_;
        }

        Parity parity(){
            return parity_;
        }

        StopBits stopBits(){
            return stopBits_;
        }

        void setPortName(QString portName);
        void setBaudRate(int baudRate);
        void setDataBits(int dataBits);
        void setFlowControl(FlowControl flowControl);
        void setParity(Parity parity);
        void setStopBits(StopBits stopBits);
        /** @endcond */

    signals:
        /** @cond DO_NOT_DOCUMENT */
        void portNameChanged();
        void baudRateChanged();
        void dataBitsChanged();
        void flowControlChanged();
        void parityChanged();
        void stopBitsChanged();
        /** @endcond */

        void dataReceived(QString data);

    public slots:
        void open();
        void sendData(QString data);

    private slots:
        void readyRead();

    private:
        QString portName_;
        int baudRate_;
        int dataBits_;
        FlowControl flowControl_;
        Parity parity_;
        StopBits stopBits_;
        QSerialPort serialPort;

    };

}
