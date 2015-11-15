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

#ifndef PAUSABLETIMER_H
#define PAUSABLETIMER_H

#include <QTimer>

class PausableTimer : public QTimer
{
public:
    PausableTimer(QObject * parent = 0);

    bool isActive() const;
    void setInterval(int msec);
    int remainingTime() const;

    void start(int msec);
    void start();
    void pause();
    void stop();

private slots:
    void resetOnTimeout();

private:
    bool isPaused;
    int remainingMSec;
    int originalInterval;
};

#endif // PAUSABLETIMER_H
