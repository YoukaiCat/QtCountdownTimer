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

#include "PausableTimer.h"

#include <QDebug>

PausableTimer::PausableTimer(QObject * parent) :
    QTimer(parent),
    isPaused(false),
    remainingMSec(0),
    originalInterval(0)
{
    connect(this, &PausableTimer::timeout, this, &PausableTimer::resetOnTimeout);
}

bool PausableTimer::isActive() const
{
    return (!isPaused) && QTimer::isActive();
}

void PausableTimer::setInterval(int msec)
{
    if (isPaused) {
        isPaused = false;
        remainingMSec = 0;
    }
    originalInterval = msec;
    QTimer::setInterval(originalInterval);
}

int PausableTimer::remainingTime() const
{
    if (isPaused) {
        return remainingMSec;
    } else {
        return QTimer::remainingTime();
    }
}

void PausableTimer::start(int msec)
{
    isPaused = false;
    remainingMSec = 0;
    originalInterval = msec;
    QTimer::start(originalInterval);
}

void PausableTimer::start()
{
    if (isPaused) {
        QTimer::start(remainingMSec);
        isPaused = false;
        remainingMSec = 0;
    } else {
        QTimer::start(originalInterval);
    }
}

void PausableTimer::pause()
{
    if (isActive()) {
        remainingMSec = QTimer::remainingTime();
        QTimer::stop();
        isPaused = true;
    }
}

void PausableTimer::stop()
{
    isPaused = false;
    remainingMSec = 0;
    QTimer::stop();
}

void PausableTimer::resetOnTimeout()
{
    isPaused = false;
    remainingMSec = 0;
}
