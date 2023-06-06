import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtGraphicalEffects 1.15
import QtQml.Models 2.15

import "ControlPanel"
import "Notification"
import "LeftArea"
import "RightArea"

ApplicationWindow {
  id: mainWindow
  flags: Qt.FramelessWindowHint | Qt.Window
  width: 900
  height: 600

  minimumWidth: width
  minimumHeight: height
  maximumWidth: width
  maximumHeight: height

  visible: true
  color: "transparent"

  Rectangle {
    width: mainWindow.width
    height: mainWindow.height
    color: "transparent"

    LeftArea {
      id: leftField
    }

    PagesHandler {
      id: rightField

      ToolBar {
        id: toolBar
      }
      Loader {
        id: rightFieldLoader
        source: "qrc:/qml/qml/RightArea/MainPage.qml"
        anchors.fill: parent
      }
    }
  }
}
