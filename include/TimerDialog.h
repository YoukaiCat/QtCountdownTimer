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
