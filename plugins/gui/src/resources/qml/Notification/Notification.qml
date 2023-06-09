import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Rectangle {
  id: rec
  property string title: ""
  property string message: ""
  //property string type: ""
  property string time: ""
  property string hexcolor: ""

  height: 60
  width: 550
  visible: true
  radius: 10

  color: hexcolor

  Image {
    id: closeNotificationIcon
    source: "qrc:/img/assets/close.svg"
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
      onClicked: rec.visible = false
    }
  }

  ColumnLayout {
    id: columnLayout
    width: parent.width

    Text {
      text: title
      Layout.leftMargin: 7
      Layout.topMargin: 10
      color: "#DDDDDD"
      font.pointSize: ((rec.height / 5) + (rec.width / 10)) / 5
      font.weight: "DemiBold"
      font.family: "OpenSans"
    }

    RowLayout {
      Text {
        text: message
        Layout.leftMargin: 7
        color: "#DDDDDD"
        font.pointSize: ((rec.height / 5) + (rec.width / 10)) / 6
        font.family: "OpenSans"
      }
      Text {
        text: time
        Layout.leftMargin: 7
        color: "#DDDDDD"
        font.pointSize: ((rec.height / 5) + (rec.width / 10)) / 6
        font.family: "OpenSans"
      }
    }
  }
}
