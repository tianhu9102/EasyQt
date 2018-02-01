#include "EasyChart.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>


EasyChart::EasyChart(QWidget *parent) : QWidget(parent)
{

    easyChart = new QChart();
}

void EasyChart::setEasyInitParams(){
    //![1]

    easyChart->legend()->hide();
    easyChart->setTitle("Multiaxis chart example");  // yourself title
    //![1]

    //![2]
    QValueAxis *axisX = new QValueAxis;
    axisX->setTickCount(10);
    easyChart->addAxis(axisX, Qt::AlignBottom);
    //![2]

    //![3]
    QSplineSeries *series = new QSplineSeries;
    *series << QPointF(1, 5) << QPointF(3.5, 18) << QPointF(4.8, 7.5) << QPointF(10, 2.5);
    easyChart->addSeries(series);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLinePenColor(series->pen().color());

    easyChart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    //![3]

    //![4]
    /*
    series = new QSplineSeries;
    *series << QPointF(1, 0.5) << QPointF(1.5, 4.5) << QPointF(2.4, 2.5) << QPointF(4.3, 12.5)
            << QPointF(5.2, 3.5) << QPointF(7.4, 16.5) << QPointF(8.3, 7.5) << QPointF(10, 17);
    easyChart->addSeries(series);


    QCategoryAxis *axisY3 = new QCategoryAxis;
    axisY3->append("Low", 5);
    axisY3->append("Medium", 12);
    axisY3->append("High", 17);
    axisY3->setLinePenColor(series->pen().color());
    axisY3->setGridLinePen((series->pen()));

    easyChart->addAxis(axisY3, Qt::AlignRight);
    series->attachAxis(axisX);
    series->attachAxis(axisY3);*/
    //![4]

    //![5]
    QChartView *chartView = new QChartView(easyChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    //![5]

    //![6]
    QWidget *widget = new QWidget();
    //widget->setWindowFlags(Qt::CustomizeWindowHint);//
    widget->setWindowFlags(Qt::WindowCloseButtonHint); //only close button


    QHBoxLayout* layout = new QHBoxLayout(widget);
    //widget.setCentralWidget(chartView);
    layout->addWidget(chartView);
    widget->resize(600, 350);
    widget->show();
    //![6]
}

void EasyChart::setEasyStyleSheet(){

}

void EasyChart::setEasyDatas(){

}
