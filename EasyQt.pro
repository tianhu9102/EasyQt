#-------------------------------------------------
#
# Project created by QtCreator 2017-12-26T14:45:37
#
#-------------------------------------------------

QT       += core gui websockets webchannel
QT       += charts
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EasyQt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH +=EasyElement \
              EasyExample \
              EasyFunction

SOURCES += main.cpp \
            MainGUI.cpp \
            EasyElement/ListWidget.cpp \
            EasyElement/TreeWidget.cpp \
            EasyElement/TableWidget.cpp \
            EasyElement/EasyButton.cpp \
            EasyElement/EasyTable.cpp \
            EasyElement/EasyTab.cpp \
            EasyExample/qcustomplot.cpp \
    EasyExample/TestEasyExample.cpp \
    EasyFunction/EasyPC.cpp \
    EasyElement/EasyChart.cpp \
    EasyElement/EasyQHcommunicate.cpp \
    RealTimeCurveQChartWidget.cpp

HEADERS  += \
            MainGUI.h \
            EasyElement/ListWidget.h \
            EasyElement/TreeWidget.h \
            EasyElement/TableWidget.h \
            EasyElement/EasyButton.h \
            EasyElement/EasyTable.h \
            EasyElement/EasyTab.h \
            EasyExample/qcustomplot.h \
    EasyExample/TestEasyExample.h \
    EasyFunction/EasyPC.h \
    EasyElement/EasyChart.h \
    EasyElement/EasyQHcommunicate.h \
    RealTimeCurveQChartWidget.h

FORMS    += \
        EasyExample/testcplot.ui

RESOURCES += \
    easyresource.qrc




