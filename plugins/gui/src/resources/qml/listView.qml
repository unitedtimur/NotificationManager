import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import Notification 1.0

ApplicationWindow {
    id: listView
    //flags: Qt.Window | Qt.FramelessWindowHint
    width: 300
    height: 75
    visible: true
    opacity: 0.3

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
}
