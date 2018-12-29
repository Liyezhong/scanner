import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    width: 600
    height: 400
    property alias label: label
    property alias button: button

    header: Label {
        text: qsTr("Page 1")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        id: label
        text: "You are on Page 1."
        anchors.centerIn: parent
    }

    Button {
        id: button
        x: 69
        y: 25
        text: qsTr("Button")
    }
}
