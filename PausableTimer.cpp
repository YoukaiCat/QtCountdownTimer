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
