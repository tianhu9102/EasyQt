#include "fmgment.h"
#include "ui_fmgment.h"

#pragma execution_character_set("utf-8")

fmgment::fmgment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fmgment)
{
    ui->setupUi(this);
    this->setIhm();

    connect(ui->pushButton_OK,SIGNAL(clicked(bool)),this,SLOT(displayOutcoming()) );
    connect(ui->pushButton_Reset,SIGNAL(clicked(bool)),this,SLOT(doResetFun()) );

    connect(ui->lineEdit_hmjc,SIGNAL(editingFinished()),this,SLOT(dohmjc() ));
}

fmgment::~fmgment()
{
    delete ui;
}

void fmgment::dohmjc(){
   qDebug()<< ui->lineEdit_hmjc->text().toUpper();
   if( ui->lineEdit_hmjc->text().length()==4|ui->lineEdit_hmjc->text().length()==0){
       ui->label_hmjcts->setText("");
       ui->label_hmjcts->setVisible(true);
   }else{
       ui->label_hmjcts->setText("not 4 length");
       ui->label_hmjcts->setVisible(true);
   }

}

void fmgment::setIhm(){
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));

    this->setWindowTitle(tr("全国流量管理系统"));

    //设置样式
     QString groupBoxStyleSheet("  QGroupBox::title {subcontrol-origin: margin;subcontrol-position: top center; padding: 0 3px; font:blod 16px;font-family:仿宋;}; {border:3px solid} ");
     ui->groupBox_1->setStyleSheet(groupBoxStyleSheet);
     //ui->groupBox_2->setStyleSheet(groupBoxStyleSheet);
     ui->groupBox_3->setStyleSheet(groupBoxStyleSheet);
     ui->groupBox_4->setStyleSheet(groupBoxStyleSheet);

     QFont fontTitle;
     fontTitle.setBold(true);
     fontTitle.setPixelSize(16);
     ui->groupBox_1->setFont(fontTitle);
     //ui->groupBox_2->setFont(fontTitle);
     ui->groupBox_3->setFont(fontTitle);
     ui->groupBox_4->setFont(fontTitle);

     ui->groupBox_1->setTitle(QStringLiteral("输入参数"));
     //ui->groupBox_2->setTitle("AAR");
     ui->groupBox_3->setTitle("统计结果");
     ui->groupBox_4->setTitle("输出结果");

     //获取当前系统时间
     this->currentDateTime_str = currentDateTime.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
     ui->dateTimeEdit_start->setMaximumDate(QDate::currentDate().addDays(1));
     ui->dateTimeEdit_end->setMaximumDate(QDate::currentDate().addDays(1));

     ui->dateTimeEdit_start->setDate(QDate::currentDate());
     ui->dateTimeEdit_end->setDate(QDate::currentDate());
     ui->dateTimeEdit_start->setTime(QTime::currentTime());
     ui->dateTimeEdit_end->setTime( QTime::currentTime().addSecs(60*60*3) );  //3*60*60
     qDebug()<<QTime::currentTime().addSecs(180) ;

     ui->dateTimeEdit_start->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
     ui->dateTimeEdit_end->setDisplayFormat("yyyy-MM-dd HH:mm:ss");


     ui->lineEdit_hmjc->setPlaceholderText("多个豁免机场用逗号隔开");
     ui->lineEdit_hmjx->setPlaceholderText("多个豁免机型用逗号隔开");
     ui->lineEdit_hmgs->setPlaceholderText("多个豁免公司用逗号隔开");
     ui->lineEdit_hmhb->setPlaceholderText("多个豁免航班用逗号隔开");
     ui->lineEdit_hmzlk->setPlaceholderText("多个豁免走廊口用逗号隔开");

     //豁免时间默认值
     ui->lineEdit_settime->setText(this->currentDateTime_str.split(" ")[0].split("-")[2] + this->currentDateTime_str.split(" ")[1].split(":")[0] + this->currentDateTime_str.split(" ")[1].split(":")[1]);
     ui->spinBox_endtime_2->setMinimum(0);
     ui->spinBox_endtime_2->setMaximum(60);
     ui->spinBox_endtime_2->setValue(20);//默认为20分钟


     //========  AAR   ========
     //ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);//自动均匀充满
     ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     ui->tableWidget->setColumnCount(3);
     QStringList header;
     header<<"时间"<<"AAR"<<"预留时隙数量";
     ui->tableWidget->setHorizontalHeaderLabels(header);

     QTableWidgetItem *columnHeaderItem = ui->tableWidget->horizontalHeaderItem(1);
     columnHeaderItem->setFont(QFont("Helvetica"));  //设置字体
     columnHeaderItem->setBackgroundColor(QColor(0,60,10));  //设置单元格背景颜色
     //columnHeaderItem->setTextColor(QColor(200,111,30));     //设置文字颜色

     //设置表格样式
     ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue; padding-left:4px; border:3px  ; }");

     //生成模拟的AAR数据
     this->createAAR_data();

     //画出结果界面
     tabWgt = new QTabWidget();
     plot1 = new QCustomPlot();
     //总体延误统计
     tabWgt->addTab(plot1,"平均延误统计");

     ui->layout_plot->addWidget(tabWgt);

     //输出结果界面
     outComingW = new QTableWidget();
     //outComingW->horizontalHeader()->setResizeMode(QHeaderView::Stretch);//自动均匀充满  4v
     outComingW->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 5v
     outComingW->setColumnCount(3);
     QStringList headerOut;
     headerOut<<"时间"<<"航班号"<<"起降厂";
     outComingW->setHorizontalHeaderLabels(headerOut);

     QTableWidgetItem *columnHeaderItemOut = outComingW->horizontalHeaderItem(1);
     columnHeaderItemOut->setFont(QFont("Helvetica"));  //设置字体
     columnHeaderItemOut->setBackgroundColor(QColor(0,60,10));  //设置单元格背景颜色

     //设置表格样式
     outComingW->horizontalHeader()->setStyleSheet( "QHeaderView::section{background:skyblue; padding-left:4px; border:3px; }" );
     ui->layout_outComing->addWidget(outComingW);

}



void fmgment::displayOutcoming(){

    qDebug();
    qDebug()<<"===================================  ";
    qDebug()<<"客户端输入参数如下：";

    qDebug()<<"开始时间：  "<<ui->dateTimeEdit_start->dateTime();
    qDebug()<<"结束时间：  "<<ui->dateTimeEdit_end->dateTime().toString();

    qDebug()<<"华北：  "<<ui->checkBox_huabei->isChecked();//华北
    qDebug()<<"华东： "<<ui->checkBox_huadong->isChecked();//华东
    qDebug()<<"东北：  "<<ui->checkBox_dongbei->isChecked();//东北
    qDebug()<<"西北：  "<<ui->checkBox_xibei->isChecked();//西北
    qDebug()<<"西南：  "<<ui->checkBox_xinan->isChecked();//西南
    qDebug()<<"中南：  "<<ui->checkBox_zhongnan->isChecked();//中南
    qDebug()<<"新疆：  "<<ui->checkBox_xinjiang->isChecked();//新疆

    qDebug()<<"豁免机场： "<<ui->lineEdit_hmjc->text();
    qDebug()<<"豁免机型： "<<ui->lineEdit_hmjx->text();
    qDebug()<<"豁免公司： "<<ui->lineEdit_hmgs->text();
    qDebug()<<"豁免航班： "<<ui->lineEdit_hmhb->text();
    qDebug()<<"豁免走廊口： "<<ui->lineEdit_hmzlk->text();

    for(int i=0;i<ui->tableWidget->rowCount();i++){
        for(int j=0;j<ui->tableWidget->columnCount();j++){
               //qDebug()<< ui->tableWidget->item(i,j)->text();
        }
    }

    qDebug()<<"客户端连接服务器，后台正在计算........";

    //Sleep(3000);

    qDebug()<<"服务器成功返回计算结果至客户端........";

    //结果可视化展示
    this->doPlot();
    this->doComputer();
}

void fmgment::doPlot(){

    //平均延误统计
    QVector<double> datax = QVector<double>() << 1 << 2 << 3 << 4;
    QVector<double> datay1 = QVector<double>() << 0.6 << 0.5 << 0.3 << 0.15;
    QVector<double> datay2 = QVector<double>() << 0.3 << 0.28 << 0.2 << 0.1;
    QVector<double> datay3 = QVector<double>() << 0.33 << 0.31 << 0.27 << 0.13;
    QCPBarsGroup *group1 = new QCPBarsGroup(plot1);
    QCPBars *bars = new QCPBars(plot1->xAxis, plot1->yAxis);
    plot1->addPlottable(bars);
    bars->setData(datax, datay1);
    bars->setBrush(QColor(0, 0, 255, 200));//rgb,phara;
    bars->setPen(QColor(0, 0, 255));
    bars->setWidth(0.15);
    bars->setBarsGroup(group1);

    QVector<QString> labels(5);
    labels[1] = "北京";
    labels[2] = "上海";
    labels[3] = "广州";
    labels[4] = "深圳";
    plot1->xAxis->setAutoTicks(false);
    plot1->xAxis->setAutoTickLabels(false);
    plot1->xAxis->setAutoTickStep(false);
    plot1->xAxis->setTickVectorLabels(labels);

    bars = new QCPBars(plot1->xAxis, plot1->yAxis);
    plot1->addPlottable(bars);
    bars->setData(datax, datay2);
    bars->setBrush(QColor(180, 00, 120, 50));
    bars->setPen(QColor(180, 00, 120));
    bars->setWidth(0.15);
    bars->setBarsGroup(group1);

    bars = new QCPBars(plot1->xAxis, plot1->yAxis);
    plot1->addPlottable(bars);
    bars->setData(datax, datay3);
    bars->setBrush(QColor(255, 154, 0, 50));
    bars->setPen(QColor(255, 154, 0));
    bars->setWidth(0.15);
    bars->setBarsGroup(group1);


    plot1->xAxis->setRange(0.1, 4.9);
    plot1->yAxis->setRange(0, 0.7);
    plot1->xAxis->setAutoTickStep(false);
    plot1->xAxis->setTickStep(1);


    plot1->update();
    tabWgt->update();

    tabWgt->addTab(plot1,"平均延误统计");
}

void fmgment::doComputer(){


    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //填充计算结果数据 //TODO::..............
    outComingW->setRowCount(15);
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        QTableWidgetItem *item = new QTableWidgetItem ( this->currentDateTime_str.split(" ")[0]+" " +  QString::number(i+1,10) +":00" );
        item->setFlags(item->flags()&(~Qt::ItemIsEditable));//不可编辑
        outComingW->setItem(i, 0, item);
     }

    QStringList listhbh;
    listhbh<<"AUY190"<<"YGKL287"<<"GSWE32";
    for(int i=0;i<outComingW->rowCount();i++){
        QTableWidgetItem *item = new QTableWidgetItem (listhbh.at(i%3));
        item->setFlags(item->flags()&(~Qt::ItemIsEditable));
        outComingW->setItem(i, 1, item);
     }

    QStringList list2;
    list2<<"国航"<<"厦门航空公司"<<"东方航空公司";
    for(int i=0;i<outComingW->rowCount();i++){
        QTableWidgetItem *item = new QTableWidgetItem (list2.at(i%3));
        item->setFlags(item->flags()&(~Qt::ItemIsEditable));
        outComingW->setItem(i, 2, item);
     }

}



void fmgment::createAAR_data(){
/*
    int row_count = ui->tableWidget->rowCount(); //获取表单行数
    ui->tableWidget->insertRow(row_count); //插入新行

   QTableWidgetItem *item = new QTableWidgetItem();
   QTableWidgetItem *item1 = new QTableWidgetItem();
   QTableWidgetItem *item2 = new QTableWidgetItem();

   //设置对应的数据【1】
   item->setText("2017-8-12");
   item1->setText("5");
   item2->setText("4");
   ui->tableWidget->setItem(row_count, 0, item);
   ui->tableWidget->setItem(row_count, 1, item1);
   ui->tableWidget->setItem(row_count, 2, item2);
   ui->tableWidget->update();*/

   ui->tableWidget->setRowCount(36);
   for(int i=0;i<ui->tableWidget->rowCount();i++){
      for(int j=1;j<ui->tableWidget->columnCount();j++){
           QTableWidgetItem *item = new QTableWidgetItem (QString::number(i+j,10));
           ui->tableWidget->setItem(i, j, item);
        }
    }

   for(int i=0;i<ui->tableWidget->rowCount();i++){
       if (i<23){
           QTableWidgetItem *item = new QTableWidgetItem ( this->currentDateTime_str.split(" ")[0]+" " +  QString::number(i+1,10) +":00" );
           ui->tableWidget->setItem(i, 0, item);
       }else{
           QTableWidgetItem *item = new QTableWidgetItem ( this->currentDateTime_str.split(" ")[0] +" " +  QString::number((i+1)%24,10) +":00" );
           ui->tableWidget->setItem(i, 0, item);
       }

    }
}

void fmgment::doResetFun(){
    this->tabWgt->clear(); // 统计界面删除

    for(int i=0;i<outComingW->rowCount();i++){
           outComingW->removeRow(0);
           outComingW->update();
    }

}
