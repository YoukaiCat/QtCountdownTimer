#ifndef TIMERDIALOG_H
#define TIMERDIALOG_H

#include <QtWidgets/QDialog>
#include "CountdownTimer.h"

namespace Ui {
class TimerDialog;
}

class TimerDialog : public QDialog
{
    Q_OBJECT
public:
    explicit TimerDialog(QWidget * parent = 0);
    explicit TimerDialog(CountdownTimer * timer, QWidget * parent = 0);
    ~TimerDialog();

signals:
    void editingFinished(CountdownTimer * timer);

public slots:
    void on_horizontalSliderHours_valueChanged(int hour);
    void on_horizontalSliderMinutes_valueChanged(int minute);
    void on_horizontalSliderSeconds_valueChanged(int second);

    void on_timeEdit_timeChanged();

    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    void setup();

    Ui::TimerDialog * ui;
    CountdownTimer * timer;
};

#endif // TIMERDIALOG_H
