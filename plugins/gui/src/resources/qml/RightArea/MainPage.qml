import QtQuick 2.15

Rectangle {
  id: mainPage
  color: "transparent"

  Text {
    id: header
    text: "Добро пожаловать"

    font {
      pixelSize: 36
      family: "Arial"
      weight: Font.Bold
      letterSpacing: 1
    }
    anchors {
      top: parent.top
      left: parent.left
      topMargin: 66
      leftMargin: 30
    }

    color: "#DDDDDD"
  }
  Item {
    width: 274
    height: 270
    anchors {
      top: parent.top
      right: parent.right

      topMargin: 50
      rightMargin: -38
    }

    Image {
      source: "qrc:/img/assets/shape1.png"
    }
  }

  PageRect {
    primaryText: "Micran"
    secondaryText: "Сайт компании"

    anchors {
      top: parent.top
      right: parent.right

      topMargin: 160
      rightMargin: 38
    }

    MouseArea {
      anchors.fill: parent
      onClicked: Qt.openUrlExternally("https://www.micran.ru")
    }
  }

  Item {
    width: 352
    height: 308
    anchors {
      top: parent.top
      left: parent.left

      topMargin: 176
      leftMargin: -58
    }

    Image {
      source: "qrc:/img/assets/shape2.png"
    }
  }

  PageRect {
    primaryText: "Версия 0.1.0"
    secondaryText: "Первая альфа"

    anchors {
      top: parent.top
      left: parent.left

      topMargin: 300
      leftMargin: 30
    }
  }

  Item {
    width: 318
    height: 298
    anchors {
      top: parent.top
      right: parent.right

      topMargin: 340
      rightMargin: -90
    }

    Image {
      source: "qrc:/img/assets/shape3.png"
    }
  }

  PageRect {
    primaryText: "Notification Manager"
    secondaryText: "О приложении"

    anchors {
      top: parent.top
      right: parent.right

      topMargin: 446
      rightMargin: 38
    }
  }
}
