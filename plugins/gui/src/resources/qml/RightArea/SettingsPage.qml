import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Rectangle {
  id: root
  color: "transparent"

  ColumnLayout {
    Layout.alignment: Qt.AlignTop
    Text {
      id: header
      text: "Настройки"
      color: "#DDDDDD"
      Layout.leftMargin: 40
      Layout.topMargin: 24
      font {
        pixelSize: 24
        family: "Arial"
        weight: Font.Bold
        letterSpacing: 1
      }
    }
    Item {
      id: fillerItem
      Layout.alignment: Qt.AlignTop
      Layout.fillWidth: true
      height: 40
    }

    ListView {
      Layout.alignment: Qt.AlignTop
      Layout.fillWidth: true
      Layout.leftMargin: 40

      Text {
        id: notificationAligmentHat
        text: "Расположение блока уведомлений"
        color: "#DDDDDD"
        font {
          pixelSize: 18
          family: "Arial"
          weight: Font.DemiBold
          letterSpacing: 1
        }
      }
      ColumnLayout {
        anchors.top: notificationAligmentHat.bottom
        RadioButton {
          id: fbutton
          MouseArea {
            anchors.fill: fbutton
            onClicked: GUI.setDisplayCorner(0)
          }
          Text {
            anchors.left: fbutton.right
            text: "Слева сверху"
            color: "#DDDDDD"
            font {
              pixelSize: 12
              family: "Arial"
              letterSpacing: 1
            }
          }
        }
        RadioButton {
          id: sbutton
          MouseArea {
            anchors.fill: sbutton
            onClicked: GUI.setDisplayCorner(1)
          }
          Text {
            anchors.left: sbutton.right
            text: "Справа сверху"
            color: "#DDDDDD"
            font {
              pixelSize: 12
              family: "Arial"
              letterSpacing: 1
            }
          }
        }
        RadioButton {
          id: tbutton
          MouseArea {
            anchors.fill: tbutton
            onClicked: GUI.setDisplayCorner(2)
          }
          Text {
            anchors.left: tbutton.right
            text: "Снизу справа"
            color: "#DDDDDD"
            font {
              pixelSize: 12
              family: "Arial"
              letterSpacing: 1
            }
          }
        }
        RadioButton {
          id: fobutton
          MouseArea {
            anchors.fill: fobutton
            onClicked: GUI.setDisplayCorner(3)
          }
          Text {
            anchors.left: fobutton.right
            text: "Снизу слева"
            color: "#DDDDDD"
            font {
              pixelSize: 12
              family: "Arial"
              letterSpacing: 1
            }
          }
        }
      }
    }
  }
}
