import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    width: 600
    height: 400
    property alias label: label
    property alias button: button

    header: Label {
        text: qsTr("Debug Page")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        id: label
        text: qsTr("test...")
        anchors.centerIn: parent
    }

    Button {
        id: button
        x: 93
        y: 46
        text: qsTr("debug")
    }
}
