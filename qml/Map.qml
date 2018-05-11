import QtQuick 2.7
import QtQuick.Window 2.2

import QtLocation 5.6
import QtPositioning 5.6


Window {
    width: 1024
    height: 768
    visible: true

    property MapCircle uav
    property MapCircle point

    Map {
        id: map
        anchors.fill: parent
        plugin: Plugin {name: "mapboxgl" /*"osm", "mapboxgl", "esri", ... */}
        center: QtPositioning.coordinate(59.91, 10.75) // Oslo
        zoomLevel: 14


        // TODO: Use a RouteQuery/RouteModel
        ListModel {
            id: waypoints
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                point = Qt.createQmlObject('import QtLocation 5.3;\
                                            MapCircle {radius: 35; color: "red"; opacity: 0.5; border.width: 0.5}', map)
                point.center = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                waypoints.append(point.center)
                map.addMapItem(point)
            }
        }

        Component.onCompleted: {
            uav = Qt.createQmlObject('import QtLocation 5.3;\
                                      MapCircle {radius: 50; color: "black"; opacity: 0.8; border.width: 0.5}', map)
            uav.center = map.center
            map.addMapItem(uav)
        }
    }
}
