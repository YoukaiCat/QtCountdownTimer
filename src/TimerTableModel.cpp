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

#include "TimerTableModel.h"

#include <QDebug>

#include "TimerStatus.h"

TimerTableModel::TimerTableModel(QObject * parent) : QAbstractTableModel(parent) {}

int TimerTableModel::rowCount(const QModelIndex & index) const
{
    Q_UNUSED(index);
    return timers.count();
}

int TimerTableModel::columnCount(const QModelIndex & index) const
{
    Q_UNUSED(index);
    return 4;
}

QVariant TimerTableModel::data(const QModelIndex & index, int role) const
{
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0:
            return QVariant(inspectTimerStatus(timers.at(index.row())->getStatus()));
        case 1:
            return QVariant(timers.at(index.row())->getTime().toString("HH:mm:ss"));
        case 2:
            return QVariant(timers.at(index.row())->getRemainingTime().toString("HH:mm:ss"));
        case 3:
            return QVariant(timers.at(index.row())->getNote());
        default:
            return QVariant();
        }
    } else if (role == Qt::UserRole) {
        return QVariant::fromValue(timers.at(index.row()));
    } else {
        return QVariant();
    }
}

QVariant TimerTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            return QString("Status, Time, Remaining time, Note").split(",")[section];
        } else {
            return QVariant(section + 1);
        }
    } else {
        return QVariant();
    }
}

Qt::ItemFlags TimerTableModel::flags(const QModelIndex & index) const
{
    if (!index.isValid()) {
        return Qt::ItemIsEnabled;
    } else {
        return QAbstractTableModel::flags(index);
    }
}

bool TimerTableModel::insertRows(int row, int count, const QModelIndex & index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), row, row + count - 1);
    for(auto i = row; i < (row + count); i++) {
        timers.insert(i, new CountdownTimer());
    }
    endInsertRows();
    return true;
}

bool TimerTableModel::removeRows(int row, int count, const QModelIndex & index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    for(auto n = count; n > 0; n--) {
        delete timers.at(row);
        timers.removeAt(row);
    }
    endRemoveRows();
    return true;
}

bool TimerTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        delete timers.at(index.row());
        timers.replace(index.row(), value.value<CountdownTimer *>());
        emit dataChanged(index, createIndex(index.row(), columnCount()));
        return true;
    } else {
        return false;
    }
}
