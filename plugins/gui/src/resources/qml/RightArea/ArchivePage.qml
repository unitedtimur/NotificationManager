import QtQuick.Controls 1.4
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick 2.15
import "../Notification"

Rectangle {
  id: archivePage
  color: "transparent"
  Text {
    id: header
    text: "Архив"

    font {
      pixelSize: 24
      family: "Arial"
      weight: Font.Bold
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

  ColumnLayout {
    anchors.top: header.bottom
    RowLayout {
      spacing: 10
      Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

      TextField {
        id: dateInput
        Layout.preferredHeight: 30
        Layout.preferredWidth: 120
        placeholderText: "Selected date"
        readOnly: true
      }
      Button {
        id: dateButton
        Layout.preferredHeight: 30
        Layout.preferredWidth: 80
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
            dateInput.text = selectedDate.toISOString().slice(0, 10)
            HistoryModel.selectByDate(selectedDate.toISOString().slice(0, 10))
            datePopup.close()
          }
        }
      }
    }
    ListView {
      id: notifyList
      Layout.preferredHeight: archivePage.height - 110
      Layout.preferredWidth: archivePage.width - 50
      //      Component.onCompleted: {
      //        console.log(archivePage.width)
      //        console.log(archivePage.height)
      //      }
      Layout.leftMargin: 40
      Layout.topMargin: 10
      spacing: 20
      model: HistoryModel
      delegate: Notification {
        title: model.title
        message: model.message
        time: model.time
        hexcolor: model.hexcolor
      }
      clip: true
      ScrollBar.vertical: ScrollBar {
        id: verticalScrollBar
        active: true
        orientation: Qt.Vertical
        contentItem: Rectangle {
          implicitWidth: 6
          color: "#dddddd"
          radius: 10
        }
        background: Item {
          Rectangle {
            anchors {
              top: parent.top
              bottom: parent.bottom
              bottomMargin: 0
              left: parent.left
              right: parent.right
            }
            radius: 10
            color: "#dddddd"
            opacity: 0.5
          }
        }
      }
    }
  }
  Rectangle {
    id: footer
    width: archivePage.width
    anchors.bottom: archivePage.bottom
    height: 10
    color: "#1E1E1E"
  }
}
