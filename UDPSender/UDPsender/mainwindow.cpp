#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udpsender = new QUdpSocket(this);
    ui->Connectionstatus->setStyleSheet("QLabel{"
                                        "background-color:Red;"
                                        "color:White;"
                                        "border:black;"
                                        "font-size:12px"
                                        "}"
                                        );
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
        ui->Connectionstatus->setStyleSheet("QLabel{"
                                            "background-color:Green;"
                                            "color:White;"
                                            "border:black;"
                                            "font-size:12px"
                                            "}"
                                            );
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

