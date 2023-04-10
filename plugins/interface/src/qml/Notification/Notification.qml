import QtQuick 2.15
import QtQuick.Layouts 1.15

/*!
 * \brief Элемент, отрисовывающий сущность очередного уведомления
 */

Rectangle {
    id: rec
    property string title: ""
    property string message: ""
    property int state: 0

    height: mainWindow.height / 16
    width: mainWindow.width / 6
    visible:true

    Component.onCompleted: {
            switch (state) {
                case 0:
                    color = Qt.rgba(176/255, 68/255, 68/255, 0.9);
                    break;
                case 1:
                    color = Qt.rgba(33/255, 33/255, 49/255, 0.9);
                    break;
                case 2:
                    color = Qt.rgba(176/255, 127/255, 0, 0.9);
                    break;
                default:
                    color = Qt.rgba(176/255, 68/255, 68/255, 0.9);
            }
        }

    Image {
        id: closeNotificationIcon
        anchors {
            top:parent.top
            right:parent.right
            topMargin: 14
            rightMargin: 22
        }
        MouseArea {
            anchors.fill: parent
            onClicked: rec.visible = false

        }
        fillMode: Image.PreserveAspectFit
        source: "qrc:/ui/assets/closenoticon.png"
    }

    ColumnLayout {
        id: columnLayout
        width:parent.width
        Text {
            text: title
            Layout.leftMargin: 7
            Layout.topMargin: 10
            color: "#DDDDDD"
            font.pointSize: ((rec.height/5) + (rec.width /10))/4
            font.weight: "DemiBold"
            font.family: "OpenSans"
        }
        Text {
            text: message
            Layout.leftMargin: 7
            color: "#DDDDDD"
            font.pointSize: ((rec.height/5) + (rec.width /10))/6
            font.family: "OpenSans"
        }

    }
}
