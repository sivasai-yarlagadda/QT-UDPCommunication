#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QUdpSocket>
#include <QMainWindow>
#include<QMessageBox>
#include<QDebug>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_connectSender_clicked();

    void on_send_clicked();

    void on_disconnectsender_clicked();

private:
    Ui::MainWindow *ui;
    QUdpSocket *udpsender;
    qint32 port = 5004;
};
#endif // MAINWINDOW_H
