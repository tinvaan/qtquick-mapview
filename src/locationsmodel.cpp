#include  "locationsmodel.h"

Locations::Locations(QStringList &points, QObject *parent=0)
    : QAbstractListModel(parent), m_locations(points)
{}

Locations::~Locations()
{}

int Locations::rowCount(const QModelIndex &parent) const
{
    return m_locations.count();
}

QVariant Locations::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_locations.size() || role != Qt::DisplayRole)
        return QVariant();

    return m_locations.at(index.row());
}
