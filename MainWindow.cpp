#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>

#include <QMessageBox>

//TODO: sorting, refactoring, sound choosing, tray icon, autoresizable headers, не обновлять когда скрыто, утечки

MainWindow::MainWindow(QWidget * parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    icon.show();
    connect(&icon, &QSystemTrayIcon::activated, [=](QSystemTrayIcon::ActivationReason reason) {
        this->show();
    });
    model = new TimerTableModel(this);
    ui->tableViewTimer->setModel(model);
    updateTimer.setInterval(1000);
    connect(&updateTimer, &QTimer::timeout, [=]() {
        model->dataChanged(model->index(0, 0), model->index(model->rowCount(), model->columnCount()));
    });
    updateTimer.start();
    player.setVolume(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::notifyModelAboutChangedData()
{
    model->dataChanged(model->index(ui->tableViewTimer->currentIndex().row(), 0), model->index(ui->tableViewTimer->currentIndex().row(), model->columnCount()));
}

void MainWindow::enableButtonsAndActions()
{
    ui->pushButtonEditTimer->setEnabled(true);
    ui->pushButtonRemoveTimer->setEnabled(true);
    ui->pushButtonStartTimer->setEnabled(true);
    ui->pushButtonPauseTimer->setEnabled(true);
    ui->pushButtonStopTimer->setEnabled(true);
//    ui->pushButtonStartAll->setEnabled(true);
//    ui->pushButtonPauseAll->setEnabled(true);
//    ui->pushButtonStopAll->setEnabled(true);
//    ui->pushButtonRemoveAll->setEnabled(true);
}

void MainWindow::disableButtonsAndActions()
{
    ui->pushButtonEditTimer->setEnabled(false);
    ui->pushButtonRemoveTimer->setEnabled(false);
    ui->pushButtonStartTimer->setEnabled(false);
    ui->pushButtonPauseTimer->setEnabled(false);
    ui->pushButtonStopTimer->setEnabled(false);
//    ui->pushButtonStartAll->setEnabled(false);
//    ui->pushButtonPauseAll->setEnabled(false);
//    ui->pushButtonStopAll->setEnabled(false);
//    ui->pushButtonRemoveAll->setEnabled(false);
}

void MainWindow::showNotificationAboutTimout()
{
    auto timer = static_cast<CountdownTimer *>(sender());
    icon.showMessage("Timeout", QString("Note: %1\n Time: %2").arg(timer->getNote()).arg(timer->getTime().toString("HH:mm:ss")));
    player.setMedia(QUrl("qrc:/sounds/notification.wav"));
    player.play();
}

void MainWindow::addTimer(CountdownTimer * timer)
{
    connect(timer, &CountdownTimer::timeout, this, &MainWindow::showNotificationAboutTimout);
    auto rowCount = model->rowCount();
    model->insertRow(rowCount);
    model->setData(model->index(rowCount, 0), QVariant::fromValue(timer));
}

void MainWindow::on_tableViewTimer_clicked(const QModelIndex & index)
{
    Q_UNUSED(index);
    enableButtonsAndActions();
}

void MainWindow::on_tableViewTimer_doubleClicked(const QModelIndex & index)
{
    Q_UNUSED(index);
    on_pushButtonEditTimer_clicked();
}

void MainWindow::on_pushButtonAddTimer_clicked()
{
    TimerDialog dialog(this);
    connect(&dialog, &TimerDialog::editingFinished, this, &MainWindow::addTimer);
    dialog.exec();
}

void MainWindow::on_pushButtonEditTimer_clicked()
{
    auto timer = model->data(ui->tableViewTimer->currentIndex(), Qt::UserRole).value<CountdownTimer *>();
    TimerDialog dialog(timer, this);
    dialog.exec();
}

void MainWindow::on_pushButtonRemoveTimer_clicked()
{
    model->removeRow(ui->tableViewTimer->currentIndex().row());
    if (model->rowCount() == 0) {
        disableButtonsAndActions();
    }
}

void MainWindow::on_pushButtonStartTimer_clicked()
{
    auto timer = model->data(ui->tableViewTimer->currentIndex(), Qt::UserRole).value<CountdownTimer *>();
    timer->start();
    notifyModelAboutChangedData();
}

void MainWindow::on_pushButtonPauseTimer_clicked()
{
    auto timer = model->data(ui->tableViewTimer->currentIndex(), Qt::UserRole).value<CountdownTimer *>();
    timer->pause();
    notifyModelAboutChangedData();
}

void MainWindow::on_pushButtonStopTimer_clicked()
{
    auto timer = model->data(ui->tableViewTimer->currentIndex(), Qt::UserRole).value<CountdownTimer *>();
    timer->stop();
    notifyModelAboutChangedData();
}

void MainWindow::on_pushButtonStartAll_clicked()
{
    for(auto row = 0; row < model->rowCount(); row++) {
        auto timer = model->data(model->index(row, 0), Qt::UserRole).value<CountdownTimer *>();
        timer->start();
        notifyModelAboutChangedData();
    }
}

void MainWindow::on_pushButtonPauseAll_clicked()
{
    for(auto row = 0; row < model->rowCount(); row++) {
        auto timer = model->data(model->index(row, 0), Qt::UserRole).value<CountdownTimer *>();
        timer->pause();
        notifyModelAboutChangedData();
    }
}

void MainWindow::on_pushButtonStopAll_clicked()
{
    for(auto row = 0; row < model->rowCount(); row++) {
        auto timer = model->data(model->index(row, 0), Qt::UserRole).value<CountdownTimer *>();
        timer->stop();
        notifyModelAboutChangedData();
    }
}

void MainWindow::on_pushButtonRemoveAll_clicked()
{
    model->removeRows(0, model->rowCount(), model->index(0, 0));
    disableButtonsAndActions();
}

void MainWindow::on_actionAddTimer_triggered()
{
    on_pushButtonAddTimer_clicked();
}

void MainWindow::on_actionStartAll_triggered()
{
    on_pushButtonStartAll_clicked();
}

void MainWindow::on_actionPauseAll_triggered()
{
    on_pushButtonPauseAll_clicked();
}

void MainWindow::on_actionStopAll_triggered()
{
    on_pushButtonStopAll_clicked();
}

void MainWindow::on_actionRemoveAll_triggered()
{
    on_pushButtonRemoveAll_clicked();
}

void MainWindow::on_actionAboutQt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionAboutQtCountdownTimer_triggered()
{
    QMessageBox::about(this, "About QtCountdownTimer", "The program allows you to manage list of countdown timers.");
}
