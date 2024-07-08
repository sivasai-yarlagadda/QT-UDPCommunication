#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include<QUdpSocket>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_receiverconnectbutton_clicked();
    void processPendingDatagrams();

private:
    Ui::MainWindow *ui;
    QUdpSocket *receiverudp;
    qint32 portreceiving = 5004;

};
#endif // MAINWINDOW_H
