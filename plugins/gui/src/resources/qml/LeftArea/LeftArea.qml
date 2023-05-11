import QtQuick 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: leftArea
    color: "#272930"
    width: 216
    anchors {
        right: rightField.left
        left: parent.left
        top: parent.top
        bottom: parent.bottom
    }

    ColumnLayout {
        spacing: 51

        AppName {
        id: appName
        }

        // Menu
        Rectangle {
            id: menu
            color: "transparent"
            height: 160
            width: 194
            Layout.leftMargin: 10

            ColumnLayout {
                spacing: 7

                MenuSection {
                    id: mainSection
                    qrcRightField: "qrc:/qml/qml/RightArea/MainPage.qml"
                    qrcIcon: "qrc:/img/assets/home.svg"
                    sectionName: "Главная"
                }

                MenuSection {
                    id: archiveSection
                    qrcRightField: "qrc:/qml/qml/RightArea/ArchivePage.qml"
                    qrcIcon: "qrc:/img/assets/envelope.svg"
                    sectionName: "Архив"
                }

                MenuSection {
                    id: adviceSection
                    qrcRightField: "qrc:/qml/qml/RightArea/AdvicesPage.qml"
                    qrcIcon: "qrc:/img/assets/recommendations.svg"
                    sectionName: "Советы"
                }

                MenuSection {
                    id: settingSection
                    qrcRightField: "qrc:/qml/qml/RightArea/SettingsPage.qml"
                    qrcIcon: "qrc:/img/assets/settings.svg"
                    sectionName: "Настройки"
                }
            }
        }
    }
}
