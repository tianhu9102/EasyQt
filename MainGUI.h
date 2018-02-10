#ifndef MAINGUI_H
#define MAINGUI_H

#include <QObject>
#include <QWidget>


#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QIcon>
#include <QDebug>


#include "EasyChart.h"
#include "EasyTab.h"

class MainGUI : public QWidget
{
    Q_OBJECT

private:
    QPushButton* pBtn[5];


public:
    explicit MainGUI(QWidget *parent = 0);



signals:

public slots:
    void easyTabWgtExample();
    void easyChartExample();
    void easyNetwork();

};

#endif // MAINGUI_H
