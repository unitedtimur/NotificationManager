import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Rectangle {
  id: notification
  property string title: ""
  property string message: ""
  property string time: ""
  property string hexcolor: ""

  height: 60
  width: root.width - 100
  visible: true
  radius: 10

  color: hexcolor

  RowLayout {
    width: notification.width
    height: notification.height

    ColumnLayout {
      Text {
        id: titleID
        text: title
        Layout.leftMargin: 7
        Layout.alignment: Qt.AlignTop | Qt.AlignLeft
        color: "#DDDDDD"
        font.pointSize: ((notification.height / 5) + (notification.width / 10)) / 5
        font.weight: "DemiBold"
        font.family: "OpenSans"
      }
      Text {
        id: messageID
        text: message
        Layout.leftMargin: 7
        Layout.alignment: Qt.AlignTop | Qt.AlignLeft
        color: "#DDDDDD"
        font.pointSize: ((notification.height / 5) + (notification.width / 10)) / 6
        font.family: "OpenSans"
      }
    }

    ColumnLayout {
      Rectangle {
        id: recCloseIconWrapper
        Layout.preferredWidth: 25
        Layout.preferredHeight: 25
        color: "transparent"
        Layout.alignment: Qt.AlignTop | Qt.AlignRight
        Image {
          id: closeNotificationIcon
          source: "qrc:/img/assets/close.svg"
          Layout.preferredWidth: 14
          Layout.preferredHeight: 14
          anchors.centerIn: recCloseIconWrapper
          MouseArea {
            anchors.fill: closeNotificationIcon
            hoverEnabled: true
            onEntered: {
              recCloseIconWrapper.color = "#E5E5E5"
              recCloseIconWrapper.opacity = 0.3
            }
            onExited: {
              recCloseIconWrapper.color = "transparent"
              recCloseIconWrapper.opacity = 1
            }
            onPressed: {
              recCloseIconWrapper.opacity = 0.5
            }
            onClicked: notification.visible = false
          }
        }
      }
      Text {
        id: timeID
        text: time
        //        Layout.leftMargin: 7
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignBottom
        color: "#DDDDDD"
        font.pointSize: ((notification.height / 5) + (notification.width / 10)) / 6
        font.family: "OpenSans"
      }
    }
  }
}
