#include "scanner.h"
#include "libusb.h"
#include <QDebug>

Scanner::Scanner(QObject *parent) : QObject(parent)
{
    int r;
    ssize_t cnt;

    r = libusb_init(NULL);
    if (r < 0)
        return;

    cnt = libusb_get_device_list(NULL, &devs);
    if (cnt < 0) {
        libusb_exit(NULL);
        return;
    }
    int *p = nullptr;
    auto abc = p;
}

Scanner::~Scanner()
{
    libusb_free_device_list(devs, 1);
    libusb_exit(NULL);
}

void Scanner::open()
{
  qDebug() << __FUNCTION__;
  print_devs(devs);
}

void Scanner::print_devs(libusb_device **devs)
{
    libusb_device *dev;
    int i = 0, j = 0;
    uint8_t path[8];

    while ((dev = devs[i++]) != NULL) {
        struct libusb_device_descriptor desc;
        int r = libusb_get_device_descriptor(dev, &desc);
        if (r < 0) {
            qDebug() << "failed to get device descriptor";
            return;
        }

        qDebug() << QString().sprintf("%04x:%04x (bus %d, device %d)",
            desc.idVendor, desc.idProduct,
            libusb_get_bus_number(dev), libusb_get_device_address(dev));

        r = libusb_get_port_numbers(dev, path, sizeof(path));
        if (r > 0) {
            qDebug() << QString().sprintf(" path: %d", path[0]);
            for (j = 1; j < r; j++)
                qDebug() << path[j];
        }
    }
}
