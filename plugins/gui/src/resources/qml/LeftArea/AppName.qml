import QtQuick 2.15
import QtQuick.Layouts 1.15

RowLayout {
  spacing: 7
  Layout.leftMargin: 20
  Layout.topMargin: 25
  Image {
    id: micranLogo
    source: "qrc:/img/assets/micran-logo.png"
    Layout.preferredWidth: 24
    Layout.preferredHeight: 36
  }

  Text {
    text: "Micran\nNotification Manager"
    font.pixelSize: 14
    font.family: "Arial"
    color: "#DDDDDD"
  }
}
