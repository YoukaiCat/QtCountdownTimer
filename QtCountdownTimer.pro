QT += core gui widgets multimedia

TARGET = QtCountdownTimer
TEMPLATE = app

CONFIG += staticlib qt warn_on debug

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra -O0 -ggdb -g3

SOURCES += main.cpp\
        MainWindow.cpp \
        TimerTableModel.cpp \
        CountdownTimer.cpp \
        TimerDialog.cpp \
        TimerStatus.cpp \
        PausableTimer.cpp

HEADERS += MainWindow.h \
        TimerTableModel.h \
        CountdownTimer.h \
        TimerDialog.h \
        TimerStatus.h \
        PausableTimer.h

FORMS += MainWindow.ui \
      TimerDialog.ui

DISTFILES += hykenfreak_notification-chime_CC-BY.wav

RESOURCES += QtCountdownTimer.qrc
