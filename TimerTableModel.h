#ifndef TIMERTABLEMODEL_H
#define TIMERTABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QTime>
#include "CountdownTimer.h"

class TimerTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TimerTableModel(QObject * parent);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    int columnCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool insertRows(int row, int count, const QModelIndex & parent = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex & index);
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);

signals:

public slots:

private:
    QList<CountdownTimer *> timers;
};

#endif // TIMERTABLEMODEL_H
