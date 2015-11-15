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

#include "CountdownTimer.h"

#include <QDebug>

CountdownTimer::CountdownTimer(QObject * parent) :
    QObject(parent),
    status(TimerStatus::Stopped),
    time(QTime(0, 0, 0))
{
    timer.setSingleShot(true);
    timer.setInterval(time.msecsSinceStartOfDay());
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
}

CountdownTimer::CountdownTimer(QTime time, QObject * parent) :
    QObject(parent),
    status(TimerStatus::Stopped),
    time(time)
{
    timer.setSingleShot(true);
    timer.setInterval(time.msecsSinceStartOfDay());
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
}

void CountdownTimer::timerTimeout()
{
    status = TimerStatus::Stopped;
    emit timeout();
}

TimerStatus CountdownTimer::getStatus()
{
    return status;
}

QTime CountdownTimer::getRemainingTime()
{
    auto remainingTime = timer.remainingTime();
    if (remainingTime != -1) {
        return QTime::fromMSecsSinceStartOfDay(remainingTime);
    } else {
        return QTime(0, 0, 0);
    }
}

QTime CountdownTimer::getTime()
{
    return time;
}

QString CountdownTimer::getNote()
{
    return note;
}

void CountdownTimer::setTime(QTime time)
{
    this->time = time;
    timer.setInterval(time.msecsSinceStartOfDay());
}

void CountdownTimer::setNote(QString note)
{
    this->note = note;
}

void CountdownTimer::start()
{
    status = TimerStatus::Running;
    timer.start();
}

void CountdownTimer::pause()
{
    status = TimerStatus::Paused;
    timer.pause();
}

void CountdownTimer::stop()
{
    status = TimerStatus::Stopped;
    timer.stop();
}
