#ifndef HID_H
#define HID_H

#include <QObject>
#include "libusb.h"

class Hid : public QObject
{
    Q_OBJECT
public:
    explicit Hid(QObject *parent = nullptr);


private:
    int hid_init(void);
signals:

public slots:
private:
    libusb_context *usb_context;
};

#endif // HID_H
