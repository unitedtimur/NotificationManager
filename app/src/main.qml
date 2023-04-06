import QtQuick 2.15
import QtQuick.Window 2.15
import "G:/Qt/repos/NotificationManager/plugins/interface/src/qml/ControlPanel"
import "G:/Qt/repos/NotificationManager/plugins/interface/src/qml/BottomScreen"
import "G:/Qt/repos/NotificationManager/plugins/interface/src/qml/Notification"

Window {
    width: 1600
    height: 900
    visible: true
    title: qsTr("Micran")

    ControlPanel {
       id: controlPanel
    }

    ListModel {
           id: fruitModel
//           property string language: "en"
           ListElement {
               title: "some text1"
               color: "orange"
               body: "warning1"
           }
           ListElement {
               title: "some text2"
               color: "red"
               body: "warning2"
           }
           ListElement {
               title: "some text3"
               color: "blue"
               body: "warning3"
           }
       }

    BottomScreen {
       id: bottomScreen
       ListView {
           model: fruitModel
           anchors.margins: 10
           spacing: 10
           anchors.fill: parent

           delegate: Notification {

              titleName: modelData.summaryProp
//              modelData.summaryProp = "some string"
           }

       }
//       NotificationArea {
//           id:notificationArea
//           Notification {
//               id:notification
//               titleName: "CHTOTO"
//           }
//       }
    }
}
