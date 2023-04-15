import QtQuick 2.15
import QtLocation 5.12
import QtPositioning 5.12

/*!
 * \brief Элемент, в котором распологаются сущности уведомлений и карта
 */
Rectangle {
    id: bottomScreen
    anchors{
        left: parent.left
        right: parent.right
        top: controlPanel.bottom
        bottom: parent.bottom
    }
}
