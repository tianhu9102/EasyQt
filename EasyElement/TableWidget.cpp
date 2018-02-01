#include "TableWidget.h"

TableWidget::TableWidget(QWidget *parent) : QWidget(parent)
{
    this->setInitParameters();
    this->setConstructIhm();
    this->setConnections();
}

void TableWidget::setInitParameters(){
    this->resize(600,400);
    this->setWindowIcon( QIcon(":/EasyCommon/icons/icon0/lala.png") );
    this->setWindowTitle(tr("QTableWidget Example"));

    QTabWidget* tabWgt = new QTabWidget();
    QHBoxLayout* hLayout = new QHBoxLayout(this);
    hLayout->addWidget(tabWgt);

    tabWgt->addTab(new QWidget(),"tab0");

    // QTableWidget Usecase....
    QTableWidget* tab0Wgt = new QTableWidget();
    tabWgt->addTab(tab0Wgt,"tab1");

    // QTableWidget Header Resize
    //tab0Wgt->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tab0Wgt->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // QTableWidget ScrollBar
    tab0Wgt->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
    "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
    "QScrollBar::handle:hover{background:gray;}"
    "QScrollBar::sub-line{background:transparent;}"
    "QScrollBar::add-line{background:transparent;}");
    tab0Wgt->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
    "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
    "QScrollBar::handle:hover{background:gray;}"
    "QScrollBar::sub-line{background:transparent;}"
    "QScrollBar::add-line{background:transparent;}");

    // QTableWidget header
    QStringList hLabel;
    hLabel<<"ACID"<<"DEP"<<"DES"<<"DELAY";
    tab0Wgt->setColumnCount(hLabel.length());
    tab0Wgt->setHorizontalHeaderLabels(hLabel);
    //tab0Wgt->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:lightblue;color: black;padding-left: 4px;border: 1px solid #6c6c6c;}");    //设置表头字体，颜色，模

    // QTableWidget Add Item
    int rowCount =  tab0Wgt->rowCount();
    tab0Wgt->insertRow(rowCount);
    QTableWidgetItem* item0 = new QTableWidgetItem("CSC970");
    QTableWidgetItem* item1 = new QTableWidgetItem("ZBAA");
    QTableWidgetItem* item2 = new QTableWidgetItem("ZBSS");
    QTableWidgetItem* item3 = new QTableWidgetItem("16");
    item0->setTextAlignment(Qt::AlignCenter);
    item1->setTextAlignment(Qt::AlignCenter);
    item2->setTextAlignment(Qt::AlignCenter);
    item3->setTextAlignment(Qt::AlignCenter);
    tab0Wgt->setItem(rowCount,0,item0);
    tab0Wgt->setItem(rowCount,1,item1);
    tab0Wgt->setItem(rowCount,2,item2);
    tab0Wgt->setItem(rowCount,3,item3);

    rowCount =  tab0Wgt->rowCount();
    tab0Wgt->insertRow(rowCount);
    QTableWidgetItem* item4 = new QTableWidgetItem("CES");
    QTableWidgetItem* item5 = new QTableWidgetItem("ZPPP");
    QTableWidgetItem* item6 = new QTableWidgetItem("ZBSS");
    QTableWidgetItem* item7 = new QTableWidgetItem("0");
    item4->setTextAlignment(Qt::AlignCenter);
    item5->setTextAlignment(Qt::AlignCenter);
    item6->setTextAlignment(Qt::AlignCenter);
    item7->setTextAlignment(Qt::AlignCenter);
    tab0Wgt->setItem(rowCount,0,item4);
    tab0Wgt->setItem(rowCount,1,item5);
    tab0Wgt->setItem(rowCount,2,item6);
    tab0Wgt->setItem(rowCount,3,item7);

}
void TableWidget::setConstructIhm(){

}
void TableWidget::setConnections(){

}
