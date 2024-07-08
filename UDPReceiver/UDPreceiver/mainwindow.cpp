#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    receiverudp = new QUdpSocket(this);

    ui->receiverconnectbutton->setStyleSheet( "QPushButton {"
                                             "   background-color: Green;" // Normal background color
                                             "   color: white;"              // Text color
                                             "   border: black;"
                                             "   font-size: 12px;"
                                             "}"
                                             "QPushButton:hover {"
                                             "   background-color: Blue;" // Hover background color
                                             "}"
                                             "QPushButton:pressed {"
                                             "   background-color: Red;" // Pressed background color
                                             "}");
    ui->connectionstatus->setStyleSheet("QLabel{"
                                        "background-color:Red;"
                                        "color:White;"
                                        "border:black;"
                                        "font-size:12px"
                                        "}"
                                        );
    ui->disconnectreceiver->setStyleSheet( "QPushButton {"
                                             "   background-color: Red;" // Normal background color
                                             "   color: white;"              // Text color
                                             "   border: black;"
                                             "   font-size: 12px;"
                                             "}"
                                             "QPushButton:hover {"
                                             "   background-color: Blue;" // Hover background color
                                             "}"
                                             "QPushButton:pressed {"
                                             "   background-color: Red;" // Pressed background color
                                             "}");

}

MainWindow::~MainWindow()
{
    delete ui;
}

// TO connect with the Portnumber and started receiving;
void MainWindow::on_receiverconnectbutton_clicked()
{
     // Taking input from the UI for the Port
    QString inputport = ui->receiverportno->text();
    portreceiving = inputport.toInt(); // Ensure portreceiving is set to the input port
    receiverudp->bind(QHostAddress::Any, portreceiving);//Binding with the Port number for listening;
    QMessageBox::information(this, "Connection", "The connection was established and listening to the port number " + QString::number(portreceiving));
    ui->connectionstatus->setText("  Connected  ");
    ui->connectionstatus->setStyleSheet("QLabel{"
                                        "background-color:Green;"
                                        "color:White;"
                                        "border:black;"
                                        "font-size:12px"
                                        "}"
                                        );

    connect(receiverudp, &QUdpSocket::readyRead, this, &MainWindow::processPendingDatagrams);

}
// Receiving the data continously from the server;
void MainWindow::processPendingDatagrams()
{
    while (receiverudp->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(receiverudp->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;

        receiverudp->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        qDebug() << "Received datagram from" << sender.toString() << ":" << senderPort;
        qDebug() << "Data:" << datagram.data();
        ui->datadispalyscreen->appendPlainText(datagram.data());
    }
}

void MainWindow::on_disconnectreceiver_clicked()
{
    receiverudp->close();
    QMessageBox::information(this,"Disconnect","The Connection was Disconnected");
    ui->connectionstatus->setText("Disconnected");
    ui->connectionstatus->setStyleSheet("QLabel{"
                                        "background-color:Red;"
                                        "color:White;"
                                        "border:black;"
                                        "font-size:12px"
                                        "}"
                                        );

}

