#include "MainWidget.h"
#include "ui_mainwidget.h"

#include "qcustomplot.h"



MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::doPlt(){

    QHBoxLayout* layout = new QHBoxLayout();

    cPlot = new QCustomPlot;
    //QWidget* wgtLeft = new QWidget();
    wgtRight = new QWidget();
    okBtn = new QPushButton("OK");
    wgtRight->setStyleSheet("background:skyblue");

    layout->addWidget(okBtn);
    layout->addWidget(cPlot);
    this->setLayout(layout);

    connect(okBtn,SIGNAL(clicked()),this,SLOT(ploFun()));
}

void MainWidget::ploFun(){
    qDebug()<<"ok";



}

void MainWidget::doTableWgt(){
    QWidget*  responseWgt = new QWidget();
    responseWgt->setFixedHeight(20);
    QSpacerItem* spacerItem = new QSpacerItem(500,20);
    QPushButton* btn_ok = new QPushButton();
    btn_ok->setText("OK");
    QPushButton* btn_reset = new QPushButton();
    btn_reset->setText("Reset");
    QHBoxLayout* pLayout = new QHBoxLayout(responseWgt);
    pLayout->addSpacerItem(spacerItem);
    pLayout->addWidget(btn_ok);
    pLayout->addWidget(btn_reset);
    pLayout->setAlignment(Qt::AlignCenter);
    pLayout->setContentsMargins(0, 0, 0, 0);
    responseWgt->setLayout(pLayout);

    tablewgt = new QTableWidget();
    tablewgt->setColumnCount(3);
    QStringList header;
    header<<"A"<<"B"<<"C";
    tablewgt->setHorizontalHeaderLabels(header);
    tablewgt->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //tablewgt->setSelectionBehavior(QAbstractItemView::SelectRows);// 整行选中

    tablewgt->setRowCount(36);
    for(int i=0;i<tablewgt->rowCount();i++){
       for(int j=0;j<tablewgt->columnCount();j++){

            if(j==tablewgt->columnCount()-1){

                //添加按钮
/*
                QWidget* pWidget = new QWidget();
                QPushButton* btn_edit = new QPushButton();
                btn_edit->setObjectName(QString::number(i,10));
                btn_edit->setText("Edit");
                QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
                pLayout->addWidget(btn_edit);
                pLayout->setAlignment(Qt::AlignCenter);
                pLayout->setContentsMargins(0, 0, 0, 0);
                pWidget->setLayout(pLayout);
                tablewgt->setCellWidget(i, 2, pWidget);
                connect(btn_edit,SIGNAL(clicked()),this,SLOT(ff())); */


                const char* info = "取消航班";
                //QString strInfo = QStringLiteral(info);
                QString strInfo = QString::fromLocal8Bit(info);
                //添加checkBox
                QWidget* pWgt = new QWidget();
                QLabel *labelll = new QLabel( strInfo );
                QCheckBox* pcheckBox = new QCheckBox(); pcheckBox->setObjectName(QString::number(i,10));
                QHBoxLayout* pLayout = new QHBoxLayout(pWgt);
                pLayout->addWidget(pcheckBox);
                pLayout->addWidget(labelll);
                pLayout->setAlignment(Qt::AlignCenter);
                pLayout->setContentsMargins(0, 0, 0, 0);
                pWgt->setLayout(pLayout);
                tablewgt->setCellWidget(i, 2, pWgt);
                flagCurrent.append(pcheckBox);

            }else{
                QTableWidgetItem *item = new QTableWidgetItem (QString::number(rand()%10+5,10));
                item->setTextAlignment(Qt::AlignCenter);
                item->setTextAlignment(1);
                item->setFlags(item->flags()&(~Qt::ItemIsEditable));//不可编辑
                tablewgt->setItem(i, j, item);
            }

         }
     }

    QVBoxLayout* hLayout = new QVBoxLayout(this);
    hLayout->addWidget(responseWgt);
    hLayout->addWidget(tablewgt);

    connect(btn_ok,SIGNAL(clicked()),this,SLOT(doResponseOK()));
    connect(btn_reset,SIGNAL(clicked()),this,SLOT(doResponseReset()));
}

void MainWidget::doResponseOK(){
     int n=  tablewgt->rowCount();

     if(n>0){
         for(int i=0;i<n;i++){
             if(flagCurrent.at(i)->isChecked()){
                 qDebug()<<flagCurrent.at(i)->objectName();
                 tablewgt->item(flagCurrent.at(i)->objectName().toInt(),0)->setBackgroundColor(QColor(250,250,0));
                 tablewgt->item(flagCurrent.at(i)->objectName().toInt(),1)->setBackgroundColor(QColor(250,250,0));
             }else{
                 tablewgt->item(flagCurrent.at(i)->objectName().toInt(),0)->setBackgroundColor(QColor(255,255,255));
                 tablewgt->item(flagCurrent.at(i)->objectName().toInt(),1)->setBackgroundColor(QColor(255,255,255));
             }
         }

     }else{
        qDebug()<<"无数据......";
     }
}

void MainWidget::doResponseReset(){
    int n=  tablewgt->rowCount();

     if(n>0){
         for(int i=0;i<n;i++){
             if(flagCurrent.at(i)->isChecked()){
                 qDebug()<<flagCurrent.at(i)->objectName();
                 flagCurrent.at(i)->setChecked(false);
                 tablewgt->item(flagCurrent.at(i)->objectName().toInt(),0)->setBackgroundColor(QColor(250,250,255));
                 tablewgt->item(flagCurrent.at(i)->objectName().toInt(),1)->setBackgroundColor(QColor(250,250,255));
             }
         }

     }
}


//按钮槽事件
void MainWidget::ff(){
    QPushButton *button = dynamic_cast<QPushButton *>(QObject::sender());
    //QModelIndex index = tablewgt->indexAt(button->pos());
    //QTableWidgetItem *item = tablewgt->item(index.row(), 0);
    //qDebug()<<item->column()<<""<<item->row()<<index.row()<<" ;"<<tablewgt->currentColumn();
    button->setStyleSheet("background:red");
    button->setText("yes");

    qDebug()<<this->sender()->objectName().toInt();

    QTableWidgetItem *item = tablewgt->item(this->sender()->objectName().toInt(), 0);
    QTableWidgetItem *item1 = tablewgt->item(this->sender()->objectName().toInt(), 1);

    item ->setBackgroundColor(QColor(255,255,0));
    item1 ->setBackgroundColor(QColor(255,255,0));


}


#include <QSplitter>
void MainWidget::doThreeView(double xI[],double yI[],double zI[]){

    QCustomPlot* plot1 = new QCustomPlot();
    plot1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |    //设置交互方式
                                         QCP::iSelectLegend | QCP::iSelectPlottables);
   //plot1->axisRect()->setupFullAxesBox();
   QBrush qBrush(QColor(220,220,220));//设置背景色
   plot1->setBackground(qBrush);
   // add Title
   QCPPlotTitle*title = new QCPPlotTitle(plot1);
   title->setText("Plot Title Example");
   title->setFont(QFont("sans",12,QFont::Bold));
   plot1->plotLayout()->insertRow(0);
   plot1->plotLayout()->addElement(0,0,title);

    //输入数值
    QVector<double> datay1(4),datay2(4),datay3(4);
    for(int i=0;i<4;i++){
        datay1[i] = xI[i];
        datay2[i] = yI[i];
        datay3[i] = zI[i];
    }

    QVector<double> datax = QVector<double>() << 1 << 2 << 3 << 4;
    QCPBarsGroup *group1 = new QCPBarsGroup(plot1);

    //添加第一类直方柱
    QCPBars *bars = new QCPBars(plot1->xAxis, plot1->yAxis);
    plot1->addPlottable(bars);
    bars->setData(datax, datay1);
    bars->setBrush(QColor(0, 0, 255, 200));//rgb,phara;
    bars->setPen(QColor(0, 0, 255));
    bars->setWidth(0.15);
    bars->setBarsGroup(group1);



    //添加第二类直方柱
   /* bars = new QCPBars(plot1->xAxis, plot1->yAxis);
    plot1->addPlottable(bars);
    bars->setData(datax, datay2);
    bars->setBrush(QColor(180, 00, 120, 50));
    bars->setPen(QColor(180, 00, 120));
    bars->setWidth(0.15);
    bars->setBarsGroup(group1);

    //添加第三类直方柱
    bars = new QCPBars(plot1->xAxis, plot1->yAxis);
    plot1->addPlottable(bars);
    bars->setData(datax, datay3);
    bars->setBrush(QColor(255, 154, 0, 50));
    bars->setPen(QColor(255, 154, 0));
    bars->setWidth(0.15);
    bars->setBarsGroup(group1);*/

    //设置x轴文字说明及对应的位置
    //四大航名称
    QVector<QString> labels(4);
    labels[0] = "BEIJING";
    labels[1] = "hainan";
    labels[2] = "nanjing";
    labels[3] = "hunan";
    plot1->xAxis->setAutoTicks(false);
    plot1->xAxis->setAutoTickLabels(false);
    plot1->xAxis->setAutoTickStep(false);
    plot1->xAxis->setTickVectorLabels(labels);

    plot1->addPlottable(bars);
    plot1->rescaleAxes();
    double wid= plot1->xAxis->range().upper - plot1->xAxis->range().lower;
    double cl= bars->width()+(1.0*wid-bars->width()*4)/3;
    QVector<double> coor;
    for(int i=0;i<4;++i)
        coor.append(plot1->xAxis->range().lower + i*cl+bars->width()/2);
    plot1->xAxis->setTickVector(coor);
    plot1->xAxis->setTickVectorLabels(labels);

    //x轴、y轴可见范围
    plot1->xAxis->setRange(0, 5);
    plot1->yAxis->setRange(0, 10);
    plot1->xAxis->setAutoTickStep(false);
    plot1->yAxis->setAutoTickStep(false);
    plot1->xAxis->setTickStep(1);
    plot1->yAxis->setTickStep(4);
    plot1->xAxis->setLabel("Company");
    plot1->yAxis->setLabel("Number");


    //右上标签显示
    plot1->legend->setVisible(true);
    plot1->legend->setFont(QFont("Helvetica",9));
    plot1->legend->setBrush(QBrush(QColor(255,255,255,210)));//210透明度
    plot1->legend->setSelectableParts(QCPLegend::spItems);
    plot1->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);//标签位置




    QWidget* wgt = new QWidget();
    wgt->resize(600,400);
    QVBoxLayout* layout = new QVBoxLayout(wgt);
    layout->addWidget(plot1);
    layout->setMargin(0);
    wgt->show();
}
