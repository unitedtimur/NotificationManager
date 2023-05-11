import QtQuick.Controls 1.4
import QtQuick.Controls 2.15
import QtQuick 2.15
import "../Notification"

Rectangle {
    id: root
    color: "transparent"
    Text {
        id: header
        text: "Архив"

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
    Row {
        spacing: 10
        anchors {
                top: parent.top
                topMargin: 50
                bottomMargin:20
                horizontalCenter: parent.horizontalCenter
            }
        Row {
            Button
            {
                id: dateButton
                width:80
                height:30
                text: "Select date"
                onClicked: {
                    datePopup.open()
                }
            }
            Popup {
                id: datePopup
                modal: true
                width: 300
                height: 300
                contentItem: Calendar {
                    onSelectedDateChanged: {
                        dateInput.text = selectedDate.toISOString().slice(0, 10);
                        HistoryModel.selectByDate(selectedDate.toISOString().slice(0, 10));
                        datePopup.close();
                    }
                }
            }
        }
        Row {
            anchors{
                right:parent.right
            }

            TextField {
                id: dateInput
                width:120
                height:30
                placeholderText: "Selected date"
                readOnly: true
            }
        }

    }
    ListView {
        id: notifyList
        spacing: 20
        model: HistoryModel
        height: root.height
        width: root.width
        clip:true
        anchors {
            top: header.bottom
            left: header.left
            bottom:footer.top
            topMargin: 35
            leftMargin: 30
        }
        delegate: Notification {
            title: model.title
            message: model.message
            type: model.type
            date: model.time
        }
    }
    Rectangle {
        id:footer
        width: root.width
        height: 10
        anchors.bottom: root.bottom
        color:"transparent"
    }
}
