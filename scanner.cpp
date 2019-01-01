#include "scanner.h"
#include "libusb.h"
#include <QDebug>

Scanner::Scanner(QObject *parent) : QObject(parent), handle(nullptr), timeout(1000)
{
    int ret;

    ret = libusb_init(NULL);
    if (ret < 0)
        return;

    handle = libusb_open_device_with_vid_pid(NULL, VENDOR_ID, PRODUCT_ID);
    if (handle == nullptr) {
        qDebug() << "Could not find/open Scanner HID device.";
        return;
    }

    qDebug() << "Successfully find the Scanner HID device.";

    libusb_detach_kernel_driver(handle, 0);

    ret = libusb_set_configuration(handle, 1);
    if (ret < 0) {
        qDebug() << "libusb_set_configuration error " << ret;
        return;
    }
    qDebug() << "Successfully set usb configuration 1";
    ret = libusb_claim_interface(handle, 0);
    if (ret < 0) {
        qDebug() << "libusb_claim_interface error %d\n";
        return;
    }
    qDebug() << "Successfully claimed interface";
}

Scanner::~Scanner()
{
    libusb_release_interface(handle, 0);
    libusb_close(handle);
    libusb_exit(NULL);
}

void Scanner::openLight()
{
  qDebug() << __FUNCTION__;
  uchar data[0x100] = {0xcc, 0x55, 0x02, 0xff};
  if (libusb_control_transfer(handle, 0x21, 0x09, 0x301, 0, data,  0x100, timeout) < 0) {
    qDebug() << "hid write: open light failed.";
    return;
  }
  if (libusb_control_transfer(handle, 0xA1, 0x01, 0x302, 0, data,  0x100, timeout) < 0) {
      qDebug() << "hid read: open light failed.";
      return;
  }

  if (data[0] == 0xbb && data[1] == 0xdd
          && data[2] == 0x03 && data[3] == 0xff) {
      qDebug() << "hid read: open light failed. Need reset scanner.";
      return;
  }
  qDebug() << "open light ok.";
}

void Scanner::wakeup()
{
    qDebug() << __FUNCTION__;
    uchar data[0x100] = {0xcc, 0x55, 0x01, 0xff};
    if (libusb_control_transfer(handle, 0x21, 0x09, 0x301, 0, data,  0x100, timeout) < 0) {
      qDebug() << "hid write: open light failed.";
      return;
    }
    if (libusb_control_transfer(handle, 0xA1, 0x01, 0x302, 0, data,  0x100, timeout) < 0) {
        qDebug() << "hid read: wake up failed.";
        return;
    }

    if (data[0] == 0xbb && data[1] == 0xdd
            && data[2] == 0x03 && data[3] == 0xff) {
        qDebug() << "hid read: wake up failed. Need reset scanner.";
        return;
    }
    qDebug() << "wake up ok.";
}

void Scanner::reset()
{
    qDebug() << __FUNCTION__;
    uchar data[0x100] = {0xcc, 0x55, 0x03, 0xff};
    if (libusb_control_transfer(handle, 0x21, 0x09, 0x301, 0, data,  0x100, timeout) < 0) {
      qDebug() << "hid write: reset failed.";
      return;
    }
    if (libusb_control_transfer(handle, 0xa1, 0x01, 0x302, 0, data,  0x100, timeout) < 0) {
        qDebug() << "hid read: reset failed.";
        return;
    }

    if (data[0] == 0xbb && data[1] == 0xdd
            && data[2] == 0x03 && data[3] == 0xff) {
        qDebug() << "hid read: wake up failed. Need reset scanner.";
        return;
    }
    qDebug() << "reset ok.";
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
