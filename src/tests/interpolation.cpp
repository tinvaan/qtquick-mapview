#include <QDebug>
#include <QVector>
#include <QApplication>
#include <QGeoCoordinate>

#include "lineinterpolator.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QVector<QGeoCoordinate> points;
    points.append(QGeoCoordinate(59.9483, 10.7695));
    points.append(QGeoCoordinate(59.9645, 10.6712));
    points.append(QGeoCoordinate(60.0321, 10.8553));

    LineInterpolator li(points);
    li.populateSegments();
    li.interpolate();
    li.getInterpolatedCoordinates();

    return app.exec();
}
