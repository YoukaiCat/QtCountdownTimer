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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QSystemTrayIcon>
#include <QMediaPlayer>

#include "CountdownTimer.h"
#include "TimerTableModel.h"
#include "TimerDialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget * parent = 0);
    ~MainWindow();

public slots:
    void addTimer(CountdownTimer * timer);

    void on_tableViewTimer_clicked(const QModelIndex & index);
    void on_tableViewTimer_doubleClicked(const QModelIndex & index);

    void on_pushButtonAddTimer_clicked();
    void on_pushButtonEditTimer_clicked();
    void on_pushButtonRemoveTimer_clicked();
    void on_pushButtonStartTimer_clicked();
    void on_pushButtonPauseTimer_clicked();
    void on_pushButtonStopTimer_clicked();

    void on_pushButtonStartAll_clicked();
    void on_pushButtonPauseAll_clicked();
    void on_pushButtonStopAll_clicked();
    void on_pushButtonRemoveAll_clicked();

    void on_actionAddTimer_triggered();
    void on_actionStartAll_triggered();
    void on_actionPauseAll_triggered();
    void on_actionStopAll_triggered();
    void on_actionRemoveAll_triggered();

    void on_actionAboutQt_triggered();
    void on_actionAboutQtCountdownTimer_triggered();

private:
    void notifyModelAboutChangedData();
    void enableButtonsAndActions();
    void disableButtonsAndActions();
    void showNotificationAboutTimout();

    Ui::MainWindow * ui;
    TimerTableModel * model;
    QSystemTrayIcon icon;
    QTimer updateTimer;
    QMediaPlayer player;
};

#endif // MAINWINDOW_H
