#ifndef LOCATIONS_MODEL_H
#define LOCATIONS_MODEL_H

#include <QVariant>
#include <QStringList>
#include <QModelIndex>
#include <QAbstractListModel>


class Locations : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit Locations(QStringList&, QObject *parent=0);
    ~Locations();

    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex&, int) const;

private:
    QStringList m_locations;
};

#endif // LOCATIONS_MODEL_H
