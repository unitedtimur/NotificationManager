import QtQuick.Controls 1.4
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
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
      TextField {
        id: dateInput
        width: 120
        height: 30
        placeholderText: "Selected date"
        readOnly: true
      }
      Button {
        id: dateButton
        width: 80
        height: 30
        text: "Select date"
        onClicked: {
          datePopup.open()
        }
      }
    }

    ListView {
      id: notifyList
      spacing: 20
      model: HistoryModel
      height: root.height
      width: root.width
      clip: true
      Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
      Layout.fillWidth: true
      Layout.leftMargin: 40
      Layout.topMargin: 10

      //      anchors {
      //        top: header.bottom
      //        left: header.left
      //        bottom: footer.top
      //        topMargin: 35
      //        leftMargin: 30
      //      }
      delegate: Notification {
        title: model.title
        message: model.message
        time: model.time
        hexcolor: model.hexcolor
      }
    }
  }
  Rectangle {
    id: footer
    width: root.width
    anchors.bottom: root.bottom
    height: 10
    color: "#1E1E1E"
  }
}
