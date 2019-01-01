#ifndef SCANNER_H
#define SCANNER_H

#include <QObject>
#include <QQuickItem>
#include "libusb.h"

#define VENDOR_ID 0x0483
#define PRODUCT_ID 0x5750

class Scanner : public QObject
{
    Q_OBJECT
public:
    explicit Scanner(QObject *parent = nullptr);
    ~Scanner();
public:
    Q_INVOKABLE void openLight();
    Q_INVOKABLE void wakeup();
    Q_INVOKABLE void reset();
    void print_devs(libusb_device **devs);

private:

signals:

public slots:
private:
    libusb_device **devs;
    struct libusb_device_handle *handle;
    qint32 timeout;
};

#endif // SCANNER_H
