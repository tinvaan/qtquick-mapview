#ifndef LINEINTERPOLATOR_H
#define LINEINTERPOLATOR_H

#include <QPair>
#include <QObject>
#include <QVector>
#include <QVariant>
#include <QGeoCoordinate>


class LineInterpolator : public QObject
{
    Q_OBJECT

public:
    explicit LineInterpolator(QObject *parent=0);
    explicit LineInterpolator(QVariantList, QObject *parent=0);

    void interpolate();
    void populateSegments();
    QVariantList getLineCoordinates();

    Q_INVOKABLE void setLineCoordinates(QVariantList );
    Q_INVOKABLE QVariantList getInterpolatedCoordinates();

private:
    QVariantList m_endpoints, m_coordinates;
    QVector<QPair<QGeoCoordinate, QGeoCoordinate>> m_segments;
};

#endif // LINEINTERPOLATOR_H
