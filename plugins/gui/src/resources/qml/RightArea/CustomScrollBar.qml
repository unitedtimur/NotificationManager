import QtQuick 2.15
import QtQuick.Controls 2.15

ScrollBar {
  id: verticalScrollBar
  active: true
  orientation: Qt.Vertical
  contentItem: Rectangle {
    implicitWidth: 6
    color: "#dddddd"
    radius: 10
  }
  background: Item {
    Rectangle {
      anchors {
        top: parent.top
        bottom: parent.bottom
        bottomMargin: 0
        left: parent.left
        right: parent.right
      }
      radius: 10
      color: "#dddddd"
      opacity: 0.5
    }
  }
}
