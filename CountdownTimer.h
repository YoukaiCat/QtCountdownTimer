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
