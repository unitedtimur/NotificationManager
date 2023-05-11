import QtQuick 2.15
import QtGraphicalEffects 1.15

// Main
Rectangle {
    property var qrcRightField
    property var qrcIcon
    property var sectionName
    id: section
    height: 36
    width: menu.width
    color: (rightFieldLoader.source
            == qrcRightField) ? "#32343C" : "transparent"
    radius: 5

    Image {
        id: icon
        source: qrcIcon
        height: 20
        width: 20
        visible: false
        anchors {
            left: parent.left
            verticalCenter: parent.verticalCenter
            leftMargin: 12
        }
    }

    ColorOverlay {
           anchors.fill: icon
           source: icon
           color: (rightFieldLoader.source
                   == qrcRightField) ? "#0BBCD1" : "#DDDDDD"
           antialiasing: true
    }

    Text {
        id: text
        text: sectionName
        font.pixelSize: 16
        font.family: "Arial"
        font.letterSpacing: 1
        font.weight: (rightFieldLoader.source
                      == qrcRightField) ? Font.DemiBold : Font.ExtraLight
        color: (rightFieldLoader.source
                == qrcRightField) ? "#0BBCD1" : "#DDDDDD"
        anchors {
            left: icon.right
            verticalCenter: parent.verticalCenter
            leftMargin: 14
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            rightFieldLoader.source = qrcRightField
        }
    }
}
