#include <QVector>
#include <QVariant>
#include <QGeoCoordinate>
#include <QCoreApplication>

#include "lineinterpolator.h"


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QVariantList points;
    points.append(QVariant::fromValue(QGeoCoordinate(59.9483, 10.7695)));
    points.append(QVariant::fromValue(QGeoCoordinate(59.9645, 10.6712)));
    points.append(QVariant::fromValue(QGeoCoordinate(60.0321, 10.8553)));

    LineInterpolator li(points);
    li.populateSegments();
    li.interpolate();
    li.getInterpolatedCoordinates();

    return app.exec();
}
