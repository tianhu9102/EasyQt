#ifndef EASYCHART_H
#define EASYCHART_H

#include <QWidget>
#include <QHBoxLayout>
#include <QChart>
#include <QChartView>

QT_CHARTS_BEGIN_NAMESPACE
QT_CHARTS_END_NAMESPACE
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class EasyChart;
}

class EasyChart : public QWidget
{
    Q_OBJECT
public:
    explicit EasyChart(QWidget *parent = 0);

    void setEasyInitParams();
    void setEasyStyleSheet();
    void setEasyDatas();

    void paintEvent(QPaintEvent*);

private:
    QChart *easyChart;
    QChartView *chartView;

signals:

public slots:
};

#endif // EasyChart_H
