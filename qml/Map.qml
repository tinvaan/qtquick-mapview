import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

import QtLocation 5.6
import QtPositioning 5.6


Window {
    id: appWindow
    width: 1024
    height: 768
    visible: true

    property MapCircle uav
    property MapCircle point
    property MapPolyline waypointLine


    RowLayout {
        id: mainLayout
        anchors.fill: parent
        spacing: 2

        Map {
            id: map
            anchors.fill: parent
            zoomLevel: 14
            center: QtPositioning.coordinate(59.91, 10.75) // Oslo
            plugin: Plugin {
                id: mapPlugin
                name: "mapboxgl" /*"osm", "mapboxgl", "esri", ... */
            }

            RouteQuery {
                id: pointsQuery
            }

            Flight {
                id: uavFlight
                pointsModel.plugin: mapPlugin
                pointsModel.query: pointsQuery
            }

            MouseArea {
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                anchors.fill: parent

                onClicked: {
                    if (mouse.button == Qt.LeftButton) {
                        point = Qt.createQmlObject('import QtLocation 5.3;\
                                                    MapCircle {radius: 35; color: "red"; opacity: 0.5; border.width: 0.5}', map)

                        point.center = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                        pointsQuery.addWaypoint(point.center)
                        map.addMapItem(point)

                        uavFlight.waypointAdded(point.center)
                    } else {
                        if (!uav) {
                            uav = Qt.createQmlObject('import QtLocation 5.3;\
                                                      MapCircle {radius: 50; color: "black"; opacity: 0.8; border.width: 0.5}', map)
                            uav.center = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                            map.addMapItem(uav)
                        }
                    }
                }
            }
        }
    }

    Button {
        id: flyButton
        anchors {
            bottom: parent.bottom
            right: parent.right
            bottomMargin: 5
            rightMargin: 5
        }
        text: qsTr("Fly")
        opacity: 1
        onClicked: uavFlight.flightRequested()
    }
}
