import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import "./Notification"

ApplicationWindow {
    id: listView
    flags: Qt.Window | Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint | Qt.Tool
    width: 300
    height: 75
    visible: true
    opacity: 0.4

    ListView {
        id: notifyList
        spacing: 10
        model: Notificationmodel
        anchors{
            top:parent.top
            right:parent.right
            topMargin: 25
            rightMargin: 25
        }

        height: parent.height/2
        width: parent.width/6
        delegate: Notification {
            title: model.title
            message: model.message
            state: model.type
        }
    }

    Rectangle {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        height: parent
        MouseArea {
            anchors.fill: parent
            onPressed: {
                listView.startSystemMove();
            }
        }
    }
}
