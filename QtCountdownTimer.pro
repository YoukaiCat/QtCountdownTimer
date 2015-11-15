QT += core gui widgets multimedia

TARGET = QtCountdownTimer
TEMPLATE = app

CONFIG += warn_on

QMAKE_CXXFLAGS += -std=c++1y -pedantic -Wall -Wextra

CONFIG(debug, debug|release) {
    QMAKE_CXXFLAGS += -O0 -ggdb -g3
}

INCLUDEPATH += include/

SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/TimerTableModel.cpp \
    src/CountdownTimer.cpp \
    src/TimerDialog.cpp \
    src/TimerStatus.cpp \
    src/PausableTimer.cpp

HEADERS += \
    include/MainWindow.h \
    include/TimerTableModel.h \
    include/CountdownTimer.h \
    include/TimerDialog.h \
    include/TimerStatus.h \
    include/PausableTimer.h

FORMS += \
    ui/MainWindow.ui \
    ui/TimerDialog.ui

RESOURCES += QtCountdownTimer.qrc

DISTFILES += media/hykenfreak_notification-chime_CC-BY.wav
