import QtQuick 2.7
import QtQuick.Window 2.2

import QtLocation 5.6
import QtPositioning 5.6


Window {
    width: 1024
    height: 768
    visible: true

    Plugin {
        id: mapPlugin
        name: "mapboxgl" // "osm", "mapboxgl", "esri", ...
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(59.91, 10.75) // Oslo
        zoomLevel: 14

        // TODO: Use a MapQuickItem instead
        MapCircle {
            id: pointCircle
            radius: 50.0
            color: 'black'
            opacity: 0.5
            border.width: 0.5
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                pointCircle.center = map.toCoordinate(Qt.point(mouse.x, mouse.y))
            }
        }
    }
}
