#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->send->hide();
    udpsender = new QUdpSocket(this);
    ui->connectSender->setStyleSheet( "QPushButton {"
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
    ui->Connectionstatus->setStyleSheet("QLabel{"
                                        "background-color:Red;"
                                        "color:White;"
                                        "border:black;"
                                        "font-size:12px"
                                        "}"
                                        );
    ui->disconnectsender->setStyleSheet( "QPushButton {"
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

void MainWindow::on_connectSender_clicked()
{
    QString ipAddress = ui->ipaddress->text();
    QString portsend = ui->portsender->text();

    if(portsend.toInt()==port)
    {

        QMessageBox::information(this, "Connection", "The connection was established " + QString::number(port));
        ui->Connectionstatus->setText(" Connected ");
        //Changing the Staus
        ui->Connectionstatus->setStyleSheet("QLabel{"
                                            "background-color:Green;"
                                            "color:White;"
                                            "border:black;"
                                            "font-size:12px"
                                            "}"
                                            );
        ui->send->show();

    }
}


void MainWindow::on_send_clicked()
{
    QString ipAddress = ui->ipaddress->text();
    QString portsend = ui->portsender->text();
    QByteArray datagram = ui->datasend->toPlainText().toUtf8();// Taking the data from Ui and converting it to ByteArray
    //Sending the data from sender to receiver;
    qDebug()<<"Sending the data from Sender to receiver";
    udpsender->writeDatagram(datagram,QHostAddress(ipAddress),port);
    qDebug()<<"Data send Successfully"<<datagram;
    QMessageBox::information(this,"Done","Data send Successfully");
}


void MainWindow::on_disconnectsender_clicked()
{
    udpsender->close();
    ui->send->hide();
    ui->Connectionstatus->setText("Disconnected");
    QMessageBox::information(this,"Disconnect","The Connection was Disconnected");
    ui->Connectionstatus->setStyleSheet("QLabel{"
                                        "background-color:Red;"
                                        "color:White;"
                                        "border:black;"
                                        "font-size:12px"
                                        "}"
                                        );

}

