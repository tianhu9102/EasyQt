#include "TestCPlot.h"
#include "ui_testcplot.h"

TestCPlot::TestCPlot(QWidget *parent) : QWidget(parent), ui(new Ui::TestCPlot)
{
    ui->setupUi(this);

    leftWgt = new QWidget();
    rightWgt = new QWidget();

    QHBoxLayout* plotLayout = new QHBoxLayout(ui->groupBox);
    plotLayout->addWidget(leftWgt);
    plotLayout->addWidget(rightWgt);
    plotLayout->setSpacing(3);
    plotLayout->setMargin(2);
    plotLayout->update();

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(doResponseOK()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(doResponseOK1()));
}

TestCPlot::~TestCPlot()
{
    delete ui;
}

void TestCPlot::setDatasLeft(double xI[],QString xLabel[],QWidget* wgt){

    //输入数值
    QVector<double> yRnge;
    QVector<double> datayYvalue(4);
    for(int i=0;i<4;i++){
        datayYvalue[i] = xI[i]; //第一组数据
        yRnge.append(datayYvalue[i]);
    }
    qSort(yRnge);

    // ------------  Left   -----------------
    QCustomPlot* plot1 = new QCustomPlot();
   // plot1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes | QCP::iSelectLegend | QCP::iSelectPlottables);
   // QBrush qBrush(QColor(220,220,220));//设置背景色
   // plot1->setBackground(qBrush);

   QCPPlotTitle* titlePlot = new QCPPlotTitle(plot1);
   titlePlot->setText("Plot Title Example 1 ");
   titlePlot->setFont(QFont("sans",12,QFont::Bold));
   plot1->plotLayout()->insertRow(0);
   plot1->plotLayout()->addElement(0,0,titlePlot);

    QVector<double> datax1 = QVector<double>() << 1 << 2 << 3 << 4;
    QCPBarsGroup *group1 = new QCPBarsGroup(plot1);

    //添加第一类直方柱
    QCPBars *bars1 = new QCPBars(plot1->xAxis, plot1->yAxis);
    plot1->addPlottable(bars1);
    bars1->setData(datax1, datayYvalue);
    bars1->setBrush(QColor(180, 00, 120, 50));
    bars1->setPen(QColor(180, 00, 120));
    bars1->setWidth(0.15);
    bars1->setBarsGroup(group1);

    //设置x轴文字说明及对应的位置
    //四大航名称
    QVector<QString> labels(4);
    labels[0] = xLabel[0];
    labels[1] = xLabel[1];
    labels[2] = xLabel[2];
    labels[3] = xLabel[3];

    plot1->xAxis->setAutoTicks(false);
    plot1->xAxis->setAutoTickLabels(false);
    plot1->xAxis->setAutoTickStep(false);
    plot1->xAxis->setTickVectorLabels(labels);

    plot1->addPlottable(bars1);
    plot1->rescaleAxes();
    double wid= plot1->xAxis->range().upper - plot1->xAxis->range().lower;
    double cl= bars1->width()+(1.0*wid-bars1->width()*4)/3;
    QVector<double> coor;
    for(int i=0;i<4;++i)
        coor.append(plot1->xAxis->range().lower + i*cl+bars1->width()/2);
    plot1->xAxis->setTickVector(coor);
    plot1->xAxis->setTickVectorLabels(labels);

    //x轴、y轴可见范围
    plot1->xAxis->setAutoTickStep(false);
    plot1->xAxis->setRange(0, 5);
    plot1->xAxis->setTickStep(1);

    plot1->yAxis->setAutoTickStep(false);
    plot1->yAxis->setRange(0, yRnge.at(yRnge.size()-1)+2);

    int min =yRnge.at(0)+1;
    int max = yRnge.at(yRnge.size()-1);
    plot1->yAxis->setTickStep( int( max/min) );

    plot1->xAxis->setLabel("Company");
    plot1->yAxis->setLabel("Number");

    QHBoxLayout* lauoLeft = new QHBoxLayout(wgt);
    lauoLeft->addWidget(plot1);
    lauoLeft->deleteLater();
    wgt->show();
}

void TestCPlot::setDatasRight(double yData[], QString xLabel[], QWidget *wgt){
    //输入数值
    QVector<double> yRnge;
    QVector<double> datayYvalue(4);
    for(int i=0;i<4;i++){
        datayYvalue[i] = yData[i]; //第一组数据

        yRnge.append(datayYvalue[i]);
    }
    qSort(yRnge);

    // ------------  Right   -----------------
    QCustomPlot* plot1 = new QCustomPlot();
   // plot1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes | QCP::iSelectLegend | QCP::iSelectPlottables);
   // QBrush qBrush(QColor(220,220,220));//设置背景色
   // plot1->setBackground(qBrush);

   QCPPlotTitle* titlePlot = new QCPPlotTitle(plot1);
   titlePlot->setText("Plot Title Example 2");
   titlePlot->setFont(QFont("sans",12,QFont::Bold));
   plot1->plotLayout()->insertRow(0);
   plot1->plotLayout()->addElement(0,0,titlePlot);

    QVector<double> datax1 = QVector<double>() << 1 << 2 << 3 << 4;
    QCPBarsGroup *group1 = new QCPBarsGroup(plot1);

    //添加第一类直方柱
    QCPBars *bars1 = new QCPBars(plot1->xAxis, plot1->yAxis);
    plot1->addPlottable(bars1);
    bars1->setData(datax1, datayYvalue);
    bars1->setBrush(QColor(180, 00, 120, 50));
    bars1->setPen(QColor(180, 00, 120));
    bars1->setWidth(0.15);
    bars1->setBarsGroup(group1);

    //设置x轴文字说明及对应的位置
    //四大航名称
    QVector<QString> labels(4);
    labels[0] = xLabel[0];
    labels[1] = xLabel[1];
    labels[2] = xLabel[2];
    labels[3] = xLabel[3];

    plot1->xAxis->setAutoTicks(false);
    plot1->xAxis->setAutoTickLabels(false);
    plot1->xAxis->setAutoTickStep(false);
    plot1->xAxis->setTickVectorLabels(labels);

    plot1->addPlottable(bars1);
    plot1->rescaleAxes();
    double wid= plot1->xAxis->range().upper - plot1->xAxis->range().lower;
    double cl= bars1->width()+(1.0*wid-bars1->width()*4)/3;
    QVector<double> coor;
    for(int i=0;i<4;++i)
        coor.append(plot1->xAxis->range().lower + i*cl+bars1->width()/2);
    plot1->xAxis->setTickVector(coor);
    plot1->xAxis->setTickVectorLabels(labels);

    //x轴、y轴可见范围
    plot1->xAxis->setAutoTickStep(false);
    plot1->xAxis->setRange(0, 5);
    plot1->xAxis->setTickStep(1);

    plot1->yAxis->setAutoTickStep(false);
    plot1->yAxis->setRange(0, yRnge.at(yRnge.size()-1)+2);

    int min =yRnge.at(0)+1;
    int max = yRnge.at(yRnge.size()-1);
    plot1->yAxis->setTickStep( int( max/min) );

    plot1->xAxis->setLabel("Company");
    plot1->yAxis->setLabel("Number");

    QHBoxLayout* lauoLeft = new QHBoxLayout(wgt);
    lauoLeft->addWidget(plot1);
    lauoLeft->deleteLater();
    wgt->show();
}

void TestCPlot::doResponseOK(){
    double xI[4];   xI[0] = 18; xI[1] = 25.5; xI[2] = 66.3; xI[3] = 37.15;
    double yI[4];   yI[0] = 72.3; yI[1] = 14.28; yI[2] = 39.3; yI[3] = 53.15;
    double zI[4];   zI[0] = 72.33; zI[1] = 54.3; zI[2] = 36.2; zI[3] = 58.15;

    QString xLabel[4]; xLabel[0] ="BJ";xLabel[1] ="BJ1";xLabel[2] ="BJ2";xLabel[3] ="BJ3";

    this->setDatasLeft(xI,xLabel,this->leftWgt);
    this->setDatasRight(yI,xLabel,this->rightWgt);
}

void TestCPlot::doResponseOK1(){
    double xI[4];   xI[0] = 8; xI[1] = 4.5; xI[2] = 6.3; xI[3] = 7.15;
    double yI[4];   yI[0] = 7.3; yI[1] = 4.28; yI[2] = 9.3; yI[3] = 3.15;
    double zI[4];   zI[0] = 7.33; zI[1] = 4.3; zI[2] = 6.2; zI[3] = 8.15;

    QString xLabel[4]; xLabel[0] ="SH";xLabel[1] ="SH1";xLabel[2] ="SH2";xLabel[3] ="SH3";

    this->setDatasLeft(xI,xLabel,this->leftWgt);
    this->setDatasRight(yI,xLabel,this->rightWgt);
}

void TestCPlot::doResponseOK2(){
    double xI[4];   xI[0] = 48; xI[1] = 64.5; xI[2] =36.3; xI[3] = 78.15;
    double yI[4];   yI[0] = 37.3; yI[1] = 24.28; yI[2] = 59.3; yI[3] = 3.15;
    double zI[4];   zI[0] = 87.33; zI[1] = 44.3; zI[2] = 26.2; zI[3] = 58.15;

    QString xLabel[4]; xLabel[0] ="GD";xLabel[1] ="GD1";xLabel[2] ="ZJ";xLabel[3] ="HK";

    this->setDatasLeft(xI,xLabel,this->leftWgt);
    this->setDatasRight(yI,xLabel,this->rightWgt);
}
void TestCPlot::doResponseOK3(){


}
