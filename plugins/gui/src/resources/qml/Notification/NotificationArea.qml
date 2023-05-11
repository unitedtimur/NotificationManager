import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    id: notificationArea
    visible: true
    height: mainWindow.height / 4 + 15
    width: mainWindow.width / 5
    x: Screen.width - width
    y: Screen.height - height
    opacity: 1
}
