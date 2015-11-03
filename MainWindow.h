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
