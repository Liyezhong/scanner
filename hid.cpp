#include "hid.h"

Hid::Hid(QObject *parent) : QObject(parent)
{

}

int Hid::hid_init(void)
{
    if (!usb_context) {
        const char *locale;

        /* Init Libusb */
        if (libusb_init(&usb_context))
            return -1;

        /* Set the locale if it's not set. */
        locale = setlocale(LC_CTYPE, NULL);
        if (!locale)
            setlocale(LC_CTYPE, "");
    }

    return 0;
}
