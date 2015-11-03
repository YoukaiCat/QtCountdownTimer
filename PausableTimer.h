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
