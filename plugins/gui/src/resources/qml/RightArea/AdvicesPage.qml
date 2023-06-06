import QtQuick 2.15
import QtQuick.Layouts 1.15

Rectangle {
  id: advicePage
  color: "transparent"

  Text {
    id: header
    text: "Советы"

    font {
      pixelSize: 24
      family: "Arial"
      weight: Font.DemiBold
      letterSpacing: 1
    }

    anchors {
      top: parent.top
      left: parent.left
      topMargin: 24
      leftMargin: 40
    }
    color: "#DDDDDD"
  }

  ColumnLayout {
    spacing: 20

    anchors {
      top: header.bottom
      right: parent.right
      left: parent.left
      topMargin: 36
      rightMargin: 30
      leftMargin: 30
    }

    RowLayout {
      spacing: 20
      PageRect {
        primaryText: "Как подключить систему"
        secondaryText: "Полное руководство"
      }

      PageRect {
        primaryText: "Настройка уведомлений"
        secondaryText: "Цвет, задержка"
      }
    }
  }
}
