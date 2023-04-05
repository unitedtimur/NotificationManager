import QtQuick 2.15
import QtLocation 5.12
import QtPositioning 5.12

Rectangle {
    id: bottomScreen
    anchors{
        left: parent.left
        right: parent.right
        top: controlPanel.bottom
        bottom: parent.bottom
    }
   // color: "red"
//    Plugin {
//        id:mapPlugin
//        name: "osm"
//        PluginParameter { name: "osm.useragent"; value: "My great Qt OSM application" }
//        PluginParameter { name: "osm.mapping.host"; value: "http://osm.tile.server.address/" }
//        PluginParameter { name: "osm.mapping.copyright"; value: "All mine" }
//        PluginParameter { name: "osm.routing.host"; value: "http://osrm.server.address/viaroute" }
//        PluginParameter { name: "osm.geocoding.host"; value: "http://geocoding.server.address" }

//    }

//    Map {
//        anchors.fill:parent
//        plugin: mapPlugin
//        center: QtPositioning.coordinate(59.91, 10.75) // Tomsk
//        zoomLevel: 14
//    }

}
