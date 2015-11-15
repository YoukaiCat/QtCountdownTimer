#include "TimerDialog.h"
#include "ui_TimerDialog.h"

#include <QDebug>

TimerDialog::TimerDialog(QWidget * parent) :
    QDialog(parent),
    ui(new Ui::TimerDialog),
    timer(new CountdownTimer())
{
    ui->setupUi(this);
    setup();
}

TimerDialog::TimerDialog(CountdownTimer * timer, QWidget * parent) :
    QDialog(parent),
    ui(new Ui::TimerDialog),
    timer(timer)
{
    ui->setupUi(this);
    setup();
}

void TimerDialog::setup()
{
    ui->timeEdit->setTime(timer->getTime());
    ui->lineEditNote->setText(timer->getNote());
}

void TimerDialog::on_horizontalSliderHours_valueChanged(int hour)
{
    auto time = ui->timeEdit->time();
    time.setHMS(hour, time.minute(), time.second());
    ui->timeEdit->setTime(time);
}

void TimerDialog::on_horizontalSliderMinutes_valueChanged(int minute)
{
    auto time = ui->timeEdit->time();
    time.setHMS(time.hour(), minute, time.second());
    ui->timeEdit->setTime(time);
}

void TimerDialog::on_horizontalSliderSeconds_valueChanged(int second)
{
    auto time = ui->timeEdit->time();
    time.setHMS(time.hour(), time.minute(), second);
    ui->timeEdit->setTime(time);
}

void TimerDialog::on_timeEdit_timeChanged()
{
    auto time = ui->timeEdit->time();
    ui->horizontalSliderHours->setValue(time.hour());
    ui->horizontalSliderMinutes->setValue(time.minute());
    ui->horizontalSliderSeconds->setValue(time.second());
}

void TimerDialog::on_buttonBox_accepted()
{
    timer->setTime(ui->timeEdit->time());
    timer->setNote(ui->lineEditNote->text());
    emit editingFinished(timer);
    this->close();
}

void TimerDialog::on_buttonBox_rejected()
{
    this->close();
}

TimerDialog::~TimerDialog()
{
    delete ui;
}
