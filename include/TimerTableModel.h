/**
 * Copyright (C) 2015  Vladislav Mileshkin
 * This file is part of QtCountdownTimer.
 * QtCountdownTimer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QtCountdownTimer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QtCountdownTimer.  If not, see <http://www.gnu.org/licenses/>.
 */

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
