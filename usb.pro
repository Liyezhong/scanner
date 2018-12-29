QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    test.cpp \
    scanner.cpp \
    hid.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    test.h \
    scanner.h \
    hid.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./release/ -lusb-1.0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./debug/ -lusb-1.0
else:unix:!macx: LIBS += -L$$PWD/./ -lusb-1.0 -ludev

INCLUDEPATH += $$PWD/libusb/libusb
DEPENDPATH += $$PWD/libusb/libusb

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/./release/libusb-1.0.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/./debug/libusb-1.0.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/./release/usb-1.0.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/./debug/usb-1.0.lib
else:unix:!macx: PRE_TARGETDEPS += $$PWD/./libusb-1.0.a
