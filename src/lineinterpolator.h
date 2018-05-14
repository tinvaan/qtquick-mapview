#ifndef LINEINTERPOLATOR_H
#define LINEINTERPOLATOR_H

#include <QPair>
#include <QVector>
#include <QObject>
#include <QGeoCoordinate>


class LineInterpolator : public QObject
{
    Q_OBJECT

public:
    explicit LineInterpolator(QObject *parent=0);
    explicit LineInterpolator(QVector<QGeoCoordinate>, QObject *parent=0);
    explicit LineInterpolator(QVector<QPair<double, double>>, QObject *parent=0);

    void interpolate();
    void populateSegments();
    QVector<QGeoCoordinate> getLineCoordinates();

    Q_INVOKABLE void setLineCoordinates(QVector<QGeoCoordinate> );
    Q_INVOKABLE QVector<QGeoCoordinate> getInterpolatedCoordinates();

private:
    QVector<QGeoCoordinate> m_endpoints, m_coordinates;
    QVector<QPair<QGeoCoordinate, QGeoCoordinate>> m_segments;
};

#endif // LINEINTERPOLATOR_H
