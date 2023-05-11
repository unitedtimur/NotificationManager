import QtQuick 2.15

Rectangle {
    id: rightField
    anchors.left: leftField.right
    anchors.top: parent.top
    anchors.bottom: parent.bottom
    anchors.right:parent.right
    color: "#1E1E1E"
    width: mainWindow.width - leftField.width
}
