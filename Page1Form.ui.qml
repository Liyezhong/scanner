import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    width: 600
    height: 400
    property alias reset: reset
    property alias openLight: openLight
    property alias wakeup: wakeup
    property alias label: label

    header: Label {
        text: "Operator"
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        id: label
        width: 537
        height: 17
        text: "You are on Page 1."
        anchors.verticalCenterOffset: 144
        anchors.horizontalCenterOffset: -13
        anchors.centerIn: parent
    }

    Button {
        id: wakeup
        x: 19
        y: 6
        text: qsTr("Wake up")
    }

    Button {
        id: openLight
        x: 159
        y: 6
        text: qsTr("Open light")
    }

    Button {
        id: reset
        x: 316
        y: 6
        text: qsTr("Reset")
    }

    Image {
        id: image
        x: 19
        y: 52
        width: 480
        height: 251
        source: "qrc:/qtquickplugin/images/template_image.png"
    }
}
