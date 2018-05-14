#include <QDebug>

#include "lineinterpolator.h"


LineInterpolator::LineInterpolator(QObject *parent)
    : QObject(parent)
{}

LineInterpolator::LineInterpolator(QVector<QGeoCoordinate> points, QObject *parent)
    : QObject(parent), m_endpoints(points)
{}

LineInterpolator::LineInterpolator(QVector<QPair<double, double>> points, QObject *parent)
    : QObject(parent)
{
    for (QPair<double, double> point : points) {
        QGeoCoordinate coord(point.first, point.second);
        m_endpoints.append(coord);
    }
}

void LineInterpolator::interpolate()
{
    if (m_segments.isEmpty())
        populateSegments();

    QGeoCoordinate begin, end;
    double x1, x2, y1, y2, slope, constant;

    for (QPair<QGeoCoordinate, QGeoCoordinate> segment : m_segments) {
        begin = segment.first;
        end = segment.second;

        x1 = begin.latitude();  y1 = begin.longitude();
        x2 = end.latitude();    y2 = end.longitude();

        slope = (y2 - y1)/(x2 -x1);
        constant = y1 - (slope * x1);

        qDebug() << "Interpolating between (" << x1 << ", " << y1 << ") and ("
                                              << x2 << ", " << y2 << ")";
        qDebug() << "slope = " << slope << "\t constant = " << constant;
        m_coordinates.append(begin);
        for (double x = x1 + 0.005; x < x2; x += 0.005) {
            double y = (slope * x) + constant;
            qDebug() << "(" << x << ", " << y << ")";
            m_coordinates.append(QGeoCoordinate(x, y));
        }
        m_coordinates.append(end);
        qDebug() << "\n";
    }
}

void LineInterpolator::populateSegments()
{
    for(int index = 0; index < m_endpoints.size(); index++) {
        if (index + 1 < m_endpoints.size())
            m_segments.append(QPair<QGeoCoordinate, QGeoCoordinate>(m_endpoints[index], m_endpoints[index + 1]));
        else break;
    }
}

QVector<QGeoCoordinate> LineInterpolator::getLineCoordinates()
{
    return m_endpoints;
}

void LineInterpolator::setLineCoordinates(QVector<QGeoCoordinate> points)
{
    m_endpoints = points;
}

QVector<QGeoCoordinate> LineInterpolator::getInterpolatedCoordinates()
{
    if (m_coordinates.isEmpty() && !m_endpoints.isEmpty())
        interpolate();

    return m_coordinates;
}
