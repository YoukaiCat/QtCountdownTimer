#include "TimerStatus.h"

QString inspectTimerStatus(const TimerStatus & status)
{
    switch (status) {
    case TimerStatus::Running:
        return QString("Running");
    case TimerStatus::Paused:
        return QString("Paused");
    case TimerStatus::Stopped:
        return QString("Stopped");
    default:
        return QString("Unknown status: ") + (int)status;
    }
}
