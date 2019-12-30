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

        /** @brief Name of the serial port, under windows it could be e.g "COM4", under linux it could be e.g "/dev/ttyUSB0" */
        Q_PROPERTY(QString portName READ portName WRITE setPortName NOTIFY portNameChanged)

        /** @brief Communication speed in number of bits per second, default is 115200 */
        Q_PROPERTY(int baudRate READ baudRate WRITE setBaudRate NOTIFY baudRateChanged)

        /** @brief Number of bits per word, must be between 5 and 8, default is 8 */
        Q_PROPERTY(int dataBits READ dataBits WRITE setDataBits NOTIFY dataBitsChanged)

        /** @brief Flow control, default is no flow control */
        Q_PROPERTY(FlowControl flowControl READ flowControl WRITE setFlowControl NOTIFY flowControlChanged)

        /** @brief Number of parity bits, default is zero */
        Q_PROPERTY(Parity parity READ parity WRITE setParity NOTIFY parityChanged)

        /** @brief Number of stop bits, default is one */
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

        /**
         * @brief Emitted when any amount of data is received
         *
         * @param data Received data
         */
        void dataReceived(QString data);

    public slots:

        /**
         * @brief Opens the port, all config must be done beforehand
         */
        void open();

        /**
         * @brief Closes the port
         */
        void close();

        /**
         * @brief Sends the data over the port
         *
         * @param data Data to send
         */
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
