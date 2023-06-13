import QtQuick 2.15
import QtQuick.Layouts 1.15

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
    }
  }
}
