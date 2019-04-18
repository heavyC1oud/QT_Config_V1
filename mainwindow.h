#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>
#include <QByteArray>
#include <QTimer>
#include "configcommand.h"

#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addPorts(void);
    void enableButtons(void);
    void disableButtons(void);
    void sendConfigCom(ConfCom_TypeDef com);
    void recConfigCom(void);

    void configComReadPortTCP(void);
    void configComReadPortUDP(void);
    void configComReadIPv4(void);
    void configComReadIPv6(void);
    void configComReadIPver(void);

private slots:
    void on_selCOM_CB_activated(const QString &arg1);
    void on_openCom_PB_clicked();
    void on_readPortTCP_PB_clicked();
    void readData(void);
    void endReceive(void);
    void sendConfigPing(void);
    void on_readPortUDP_PB_clicked();
    void on_readAdrIPv4_PB_clicked();
    void on_readAdrIPv6_PB_clicked();
    void on_readIPver_PB_clicked();
    void on_readAPN_PB_clicked();
    void on_readSWver_PB_clicked();

private:
    Ui::MainWindow *ui;

    QSerialPort *port;
    QSerialPortInfo *portInfo;
    ConfigCommand *configCom;
    QByteArray receiveData;
    QTimer *receiveTimer;
    QTimer *configPingTimer;
};

#endif // MAINWINDOW_H