import QtQuick 2.7
import QtQuick.Window 2.2

import QtLocation 5.6
import QtPositioning 5.6


Window {
    width: 1024
    height: 768
    visible: true

    property MapCircle circle

    Map {
        id: map
        anchors.fill: parent
        plugin: Plugin {name: "mapboxgl" /*"osm", "mapboxgl", "esri", ... */}
        center: QtPositioning.coordinate(59.91, 10.75) // Oslo
        zoomLevel: 14

        MouseArea {
            anchors.fill: parent
            onClicked: {
                // TODO: Use a MapQuickItem instead
                circle = Qt.createQmlObject('import QtLocation 5.3;\
                                             MapCircle {radius: 50; color: "black"; opacity: 0.5; border.width: 0.5}', map)
                circle.center = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                map.addMapItem(circle)
            }
        }
    }
}
