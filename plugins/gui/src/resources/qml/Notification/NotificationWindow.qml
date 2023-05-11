import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15

Window {
    id: notification_window

    property string title: ""
    property string message: ""
    property string type: ""

    flags: Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint | Qt.Tool

    height: 80
    width: 360
    maximumHeight: height
    maximumWidth: width

    x: Screen.width - width - 10
    y: Screen.height - height

    visible: true

    onTypeChanged: {
        switch (type) {
        case "NOTIFY":
            color = Qt.rgba(176 / 255, 68 / 255, 68 / 255, 0.9)
            break
        case "WARNING":
            color = Qt.rgba(33 / 255, 33 / 255, 49 / 255, 0.9)
            break
        case "ALARM":
            color = Qt.rgba(176 / 255, 127 / 255, 0, 0.9)
            break
        case "DEFAULT":
            color = Qt.rgba(176 / 255, 68 / 255, 68 / 255, 0.5)
            break
        }
    }
    Timer {
        interval: 15000
        running: true
        repeat: false
        onTriggered: notification_window.close
    }

    Image {
        id: closeNotificationIcon
        source: "qrc:/ui/assets/close.svg"
        width: 14
        height: 14
        anchors {
            top: parent.top
            right: parent.right
            topMargin: 14
            rightMargin: 14
        }

        MouseArea {
            anchors.fill: parent
            onClicked: notification_window.close()
        }
    }

    ColumnLayout {
        id: columnLayout
        spacing: 6
        anchors {
            top: parent.top
            left: parent.left
            topMargin: 8
            leftMargin: 14
        }

        Text {
            text: title
            color: "#DDDDDD"
            font {
                pixelSize: 18
                weight: Font.DemiBold
                family: "Arial"
            }
        }

        Item {
            width: 300
            Text {
                text: message
                width: parent.width
                color: "#DDDDDD"
                font {
                    pixelSize: 16
                    family: "Arial"
                }

                wrapMode: Text.WordWrap
            }
        }
    }
}
