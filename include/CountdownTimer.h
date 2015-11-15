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

#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include <QObject>
#include <QTime>

#include "PausableTimer.h"
#include "TimerStatus.h"

class CountdownTimer : public QObject
{
    Q_OBJECT
public:
    explicit CountdownTimer(QObject * parent = 0);
    explicit CountdownTimer(QTime time, QObject * parent = 0);

    TimerStatus getStatus();
    QTime getRemainingTime();

    QTime getTime();
    QString getNote();

    void setTime(QTime time);
    void setNote(QString note);

    void start();
    void pause();
    void stop();

signals:
    void timeout();

public slots:
    void timerTimeout();

private:
    PausableTimer timer;

    TimerStatus status;

    QTime time;
    QString note;
};

#endif // COUNTDOWNTIMER_H
