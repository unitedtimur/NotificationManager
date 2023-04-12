import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: mainWindow
    width: 1600
    height: 900
    visible: true

    ControlPanel {
       id: controlPanel
    }
    BottomScreen {
          id: bottomScreen

          height: parent.height/2
          width: parent.width/6

          ListView {
              id: notifyList
              spacing: 10
              model: {Notificationmodel}
              anchors{
                  top:parent.top
                  right:parent.right
                  topMargin: 25
                  rightMargin: 25
              }            
              delegate: Notification {
                  title: model.title
                  message: model.message
                  state: model.type
                }
          }
    }
}
