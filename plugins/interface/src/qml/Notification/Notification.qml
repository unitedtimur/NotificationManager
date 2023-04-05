import QtQuick 2.15
import QtQuick.Layouts 1.15


Rectangle {
    property string titleName: "BLABLABLA"
    id:notification
//    anchors {
//        top: parent.top
//        right: parent.right
//        //left: parent.left
//        bottomMargin: 10
//    }
//    height: parent.height / 4
    height: pushCL.implicitHeight
    width: pushCL.implicitWidth
    color: "#B04444"

    ColumnLayout {
        id: pushCL
        anchors.fill: parent
        spacing: 10
        Image {
            Layout.alignment: Qt.AlignRight
            id: closeNotificationIcon

            fillMode: Image.PreserveAspectFit
            source: "qrc:/ui/assets/closenoticon.png"

        }

        Text {
            id: title

            text: notification.titleName
            color: "#DDDDDD"
            font.pointSize: 14
            font.weight: "DemiBold"
            font.family: "OpenSans"
        }

        Text {
            id: importantInfo

            text: "Очень важная информация! Очень важная информация!"
            font.pointSize: 10
            font.family: "OpenSans"
        }
    }

//    Image {
//        id: closeNotificationIcon
//        anchors {
//            top: parent.top
//            right: parent.right
//            topMargin: 3
//            rightMargin: 3
//        }
//        fillMode: Image.PreserveAspectFit
//        source: "qrc:/ui/assets/closenoticon.png"

//    }

//    Text {
//        id: title
//        anchors {
//            top: parent.top
//            right: closeNotificationIcon.left
//            left: parent.left
//            topMargin: 5
//            leftMargin: 5
//        }
//        text: notification.titleName
//        color: "#DDDDDD"
//        font.pointSize: 14
//        font.weight: "DemiBold"
//        font.family: "OpenSans"
//    }

//    Text {
//        id: importantInfo
//        anchors {
//            top: title.bottom
//            right: closeNotificationIcon.left
//            left: parent.left
//            topMargin: 5
//            leftMargin: 5
//        }
//        text: "Очень важная информация! Очень важная информация!"
//        font.pointSize: 10
//        font.family: "OpenSans"
//    }

}
