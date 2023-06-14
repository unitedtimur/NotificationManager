import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Controls 1.4

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
        anchors.topMargin: 10
        RadioButton {
          id: buttonLT
          MouseArea {
            anchors.fill: buttonLT
            onClicked: {
              GUI.setDisplayCorner(0)
              buttonLT.checked = true
              buttonRT.checked = false
              buttonLB.checked = false
              buttonRB.checked = false
            }
          }
          Text {
            anchors.left: buttonLT.right
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
          id: buttonRT
          MouseArea {
            anchors.fill: buttonRT
            onClicked: {
              GUI.setDisplayCorner(1)
              buttonLT.checked = false
              buttonRT.checked = true
              buttonLB.checked = false
              buttonRB.checked = false
            }
          }
          Text {
            anchors.left: buttonRT.right
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
          id: buttonRB
          checked: true
          MouseArea {
            anchors.fill: buttonRB
            onClicked: {
              GUI.setDisplayCorner(2)
              buttonLT.checked = false
              buttonRT.checked = false
              buttonRB.checked = true
              buttonLB.checked = false
            }
          }
          Text {
            anchors.left: buttonRB.right
            text: "Справа снизу"
            color: "#DDDDDD"
            font {
              pixelSize: 12
              family: "Arial"
              letterSpacing: 1
            }
          }
        }
        RadioButton {
          id: buttonLB
          MouseArea {
            anchors.fill: buttonLB
            onClicked: {
              GUI.setDisplayCorner(3)
              buttonLT.checked = false
              buttonRT.checked = false
              buttonRB.checked = false
              buttonLB.checked = true
            }
          }
          Text {
            anchors.left: buttonLB.right
            text: "Слева снизу"
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
