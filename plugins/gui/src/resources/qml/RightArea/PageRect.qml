import QtQuick 2.15
import QtQuick.Layouts 1.15

Rectangle {
  property var primaryText
  property var secondaryText
  width: 304
  height: 84

  color: "#272727"
  radius: 14

  ColumnLayout {
    anchors {
      top: parent.top
      left: parent.left
      topMargin: 18
      leftMargin: 26
    }

    Text {
      text: primaryText
      color: "#FFFFFF"
      font {
        pixelSize: 20
        family: "Arial"
        weight: Font.Bold
        letterSpacing: 1
      }
    }

    Text {
      text: secondaryText
      color: "#FFFFFF"
      font {
        pixelSize: 16
        family: "Arial"
        weight: Font.ExtraLight
        letterSpacing: 0.5
      }
    }
  }
}
