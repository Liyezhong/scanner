import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.VirtualKeyboard 2.2
import ali.test 1.0
import leica.scanner 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Scanner")

    Test {
        id: test
    }

    Scaner {
        id: scanner
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
//        currentIndex: tabBar.currentIndex

        Page1Form {
            wakeup.onClicked: {
                scanner.wakeup()
                console.debug("__ali__")
                ////                label.text = qsTr("debug test..")
            }
            openLight.onClicked: {
                scanner.openLight()
                console.debug("__ali__222222222222")
                ////                label.text = qsTr("debug test..")
            }
            reset.onClicked: {
                scanner.reset()
                console.debug("__ali__333333333333")
                ////                label.text = qsTr("debug test..")
            }
        }

        Page2Form {
            label.onTextChanged: {
}
            button.onClicked: {
                label.text = qsTr("__ali__ ...")
}
        }
    }

//    footer: TabBar {
//        id: tabBar
//        currentIndex: swipeView.currentIndex

////        TabButton {
////            text: qsTr("Page 1")
////        }
////        TabButton {
////            text: qsTr("Page 2")
////        }
//    }

    InputPanel {
        id: inputPanel
        z: 99
        x: 0
        y: window.height
        width: window.width

        states: State {
            name: "visible"
            when: inputPanel.active
            PropertyChanges {
                target: inputPanel
                y: window.height - inputPanel.height
            }
        }
        transitions: Transition {
            from: ""
            to: "visible"
            reversible: true
            ParallelAnimation {
                NumberAnimation {
                    properties: "y"
                    duration: 250
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }
}
