#ifndef SCANNER_H
#define SCANNER_H

#include <QObject>
#include <QQuickItem>
#include "libusb.h"

class Scanner : public QObject
{
    Q_OBJECT
public:
    explicit Scanner(QObject *parent = nullptr);
    ~Scanner();
public:
    Q_INVOKABLE void open();
    void print_devs(libusb_device **devs);
signals:

public slots:
private:
    libusb_device **devs;
};

#endif // SCANNER_H
