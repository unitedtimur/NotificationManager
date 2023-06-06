import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
  id: mainWindow
  flags: Qt.Window | Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint | Qt.Tool
  width: 300
  height: 75
  visible: true
  opacity: 0.4

  Rectangle {
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.top: parent.top
    anchors.bottom: parent.bottom

    height: parent
    MouseArea {
      anchors.fill: parent
      onPressed: {
        mainWindow.startSystemMove()
      }
    }
  }
}
