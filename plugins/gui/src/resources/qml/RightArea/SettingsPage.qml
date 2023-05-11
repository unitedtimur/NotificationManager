import QtQuick 2.15

Rectangle {
    id: settingsPage
    color: "transparent"

    Text {
        id: header
        text: "Настройки"

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
}
