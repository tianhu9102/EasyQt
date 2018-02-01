#ifndef FMGMENT_H
#define FMGMENT_H

#include <QWidget>

#include <QDateTime>
#include <QDebug>
#include <QHeaderView>
#include <QTableWidget>

#include<QTextCodec>
#include "qcustomplot.h"

namespace Ui {
class fmgment;
}

class fmgment : public QWidget
{
    Q_OBJECT

public:
    explicit fmgment(QWidget *parent = 0);
    ~fmgment();

    void setIhm();
    void createAAR_data();

    void doPlot();
    void doComputer();

private:
    Ui::fmgment *ui;

    QDateTime currentDateTime;
    QString currentDateTime_str;

   QTabWidget* tabWgt;
   QCustomPlot* plot1;

   QTableWidget* outComingW;

private slots:
    void displayOutcoming();
    void doResetFun();

    void dohmjc();

};

#endif // FMGMENT_H
