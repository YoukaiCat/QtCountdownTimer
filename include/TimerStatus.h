#ifndef TIMERSTATUS_H
#define TIMERSTATUS_H

#include <QString>

enum class TimerStatus {
    Running,
    Paused,
    Stopped
};

QString inspectTimerStatus(const TimerStatus & status);

#endif // TIMERSTATUS_H
