#include <QDebug>

#include "lineinterpolator.h"

#define SCALE_INTERVAL 0.00001


LineInterpolator::LineInterpolator(QObject *parent)
    : QObject(parent)
{}

LineInterpolator::LineInterpolator(QVariantList points, QObject *parent)
    : QObject(parent), m_endpoints(points)
{}

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

        qDebug() << "\nInterpolating between (" << x1 << ", " << y1 << ") and ("
                                              << x2 << ", " << y2 << ")";
        qDebug() << "slope = " << slope << "\t constant = " << constant;

        m_coordinates.append(QVariant::fromValue(begin));
        for (double x = x1 + SCALE_INTERVAL; x < x2; x += SCALE_INTERVAL) {
            double y = (slope * x) + constant;
            qDebug() << "(" << x << ", " << y << ")";
            m_coordinates.append(QVariant::fromValue(QGeoCoordinate(x, y)));
        }
        m_coordinates.append(QVariant::fromValue(end));
    }
}

void LineInterpolator::populateSegments()
{
    for(int index = 0; index < m_endpoints.size(); index++) {
        if (index + 1 < m_endpoints.size())
            m_segments.append(
                QPair<QGeoCoordinate, QGeoCoordinate>(m_endpoints[index].value<QGeoCoordinate>(),
                                                      m_endpoints[index + 1].value<QGeoCoordinate>()));
        else break;
    }
}

QVariantList LineInterpolator::getLineCoordinates()
{
    return m_endpoints;
}

void LineInterpolator::setLineCoordinates(QVariantList points)
{
    m_endpoints = points;
}

QVariantList LineInterpolator::getInterpolatedCoordinates()
{
    if (m_coordinates.isEmpty() && !m_endpoints.isEmpty())
        interpolate();

    return m_coordinates;
}
