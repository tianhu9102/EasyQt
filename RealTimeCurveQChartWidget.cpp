
#include "RealTimeCurveQChartWidget.h"
#include <QDateTime>
#include <QHBoxLayout>
RealTimeCurveQChartWidget::RealTimeCurveQChartWidget(QWidget *parent) : QWidget(parent) {
    maxSize = 31; // 只存储最新的 31 个数据
    maxX = 300;
    maxY = 100;
    splineSeries = new QSplineSeries();
    scatterSeries = new QScatterSeries();
    scatterSeries->setMarkerSize(8);
    chart = new QChart();
    chart->addSeries(splineSeries);
    chart->addSeries(scatterSeries);
    chart->legend()->hide();
    chart->setTitle("实时动态曲线");
    chart->createDefaultAxes();
    chart->axisX()->setRange(0, 300);
    chart->axisY()->setRange(0, maxY);
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QPushButton* pBtnAdd = new QPushButton("addLine");
    pBtnAdd->setStyleSheet("background:black");
    pBtnAdd->setMaximumSize(QSize(100,40));
    QPushButton* pBtnDele = new QPushButton("deleLine");
    pBtnDele->setStyleSheet("background:black");
    pBtnDele->setMaximumSize(QSize(100,40));

    QPushButton* pBtnStop = new QPushButton("stop");
    pBtnStop->setStyleSheet("background:black");
    pBtnStop->setMaximumSize(QSize(100,40));

    QPushButton* pBtnStart = new QPushButton("start");
    pBtnStart->setStyleSheet("background:black");
    pBtnStart->setMaximumSize(QSize(100,40));

    connect(pBtnAdd,SIGNAL(clicked(bool)),this,SLOT(addLevel()));
    connect(pBtnDele,SIGNAL(clicked(bool)),this,SLOT(deleLevel()));

    connect(pBtnStop,SIGNAL(clicked(bool)),this,SLOT(dopBtnStop()));
    connect(pBtnStart,SIGNAL(clicked(bool)),this,SLOT(dopBtnStart()));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(pBtnAdd);
    layout->addWidget(pBtnDele);
    layout->addWidget(chartView);
    this->setLayout(layout);

    //...添加等级层  dy...
    axisY3 = new QCategoryAxis();

    timerId = startTimer(200);
    qsrand(QDateTime::currentDateTime().toTime_t());
}

RealTimeCurveQChartWidget::~RealTimeCurveQChartWidget() {
}
void RealTimeCurveQChartWidget::timerEvent(QTimerEvent *event) {
    // 产生一个数据，模拟不停的接收到新数据
    if (event->timerId() == timerId) {
        int newData = qrand() % (maxY + 1);
        dataReceived(newData);
    }
}
void RealTimeCurveQChartWidget::dataReceived(int value) {
    data << value;
    // 数据个数超过了最大数量，则删除最先接收到的数据，实现曲线向前移动
    while (data.size() > maxSize) {
        data.removeFirst();
    }
    // 界面被隐藏后就没有必要绘制数据的曲线了
    if (isVisible()) {
        splineSeries->clear();
        scatterSeries->clear();
        int dx = maxX / (maxSize-1);
        int less = maxSize - data.size();
        for (int i = 0; i < data.size(); ++i) {
            splineSeries->append(less*dx+i*dx, data.at(i));
            scatterSeries->append(less*dx+i*dx, data.at(i));
            if(data.at(i)>5){
                //scatterSeries->setColor(QColor(Qt::red));
            }

        }
    }
}

void RealTimeCurveQChartWidget::addLevel(){
    qDebug()<<"addLevel...";

    //axisY3->append("Low", 25);
    axisY3->append("Normal", 75);
    axisY3->append("High", 100);
    axisY3->setLinePenColor(splineSeries->color());
    axisY3->setGridLinePen(QPen(Qt::darkGray,2,Qt::SolidLine));
    //axisY3->setPen(QPen(Qt::red,2,Qt::SolidLine));

    chart->addAxis(axisY3, Qt::AlignRight);
    //splineSeries->attachAxis(axisX);
    splineSeries->attachAxis(axisY3);


}

void RealTimeCurveQChartWidget::deleLevel(){
    qDebug()<<"deleLevel...";
    chart->removeAxis(axisY3);
}

void RealTimeCurveQChartWidget::dopBtnStop(){

}
void RealTimeCurveQChartWidget::dopBtnStart(){

}
