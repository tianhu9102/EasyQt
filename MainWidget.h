#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include "qcustomplot.h"
#include <QTableWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();


    void doPlt();
    void doTableWgt();
    void doThreeView(double xI[], double yI[], double zI[]);

private:
    Ui::MainWidget *ui;

    QCustomPlot* cPlot;
    QWidget* wgtRight;
    QPushButton* okBtn;

    QTableWidget* tablewgt;
    QVector<QCheckBox*> flagCurrent;

private slots:
    void ploFun();
    void ff();
    void doResponseOK();
    void doResponseReset();
};

#endif // MAINWIDGET_H
