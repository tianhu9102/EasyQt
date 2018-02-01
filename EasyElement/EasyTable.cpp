#include "EasyTable.h"

EasyTable::EasyTable(QWidget *parent) : QWidget(parent)
{
    easyTable = new QTableWidget();
}

/**
 * @brief EasyTable::setEasyInitParams
 * @param headerList
 * @return
 *
 * set the header labels
 *
 */
QTableWidget* EasyTable::setEasyInitParams(QStringList headerList){

    easyTable->setColumnCount(headerList.length());
    easyTable->setHorizontalHeaderLabels(headerList);
    easyTable->horizontalHeader()->setFixedHeight(30);
    easyTable->resize(600,350);

    easyTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    easyTable->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:darkCyan;color: black;padding-left: 4px;border: 1px solid #6c6c6c;}");    //设置表头字体，颜色，模
    easyTable->horizontalHeader()->setFixedHeight(30);
    easyTable->setFocusPolicy(Qt::NoFocus); //去除选中虚线框

    QFont fontt("Microsoft YaHei",14,45);
    QPalette palett;
    palett.setColor(QPalette::WindowText,Qt::white);
    easyTable->horizontalHeader()->setFont(fontt);
    easyTable->horizontalHeader()->setPalette(palett);

    return easyTable;
}

void EasyTable::setEasyStyleSheet(){

    easyTable->setStyleSheet("QTableWidget::{background:darkGray;};\
                              QScrollBar:vertical{\
                                                     height: 20px;\
                                                     background: transparent;\
                                                     margin-top: 3px;\
                                                     margin-bottom: 3px;\}"
                             );
}

//!---------------------------------------------------
/**
 * @brief EasyTable::setEasyDatas
 * item without icon, text only
 */
void EasyTable::setEasyDatas(){
    int rowCount = easyTable->rowCount();
    easyTable->insertRow(rowCount);

    QTableWidgetItem* item[easyTable->columnCount()];
    for(int i=0;i<easyTable->columnCount();i++){
            item[i] = new QTableWidgetItem("SCS");
            item[i]->setTextAlignment(Qt::AlignCenter);
            easyTable->setItem(rowCount,i,item[i]);
    }
}

/**
 * @brief EasyTable::setEasyDatasIcons
 * item with icon and text
 */
void EasyTable::setEasyDatasIcons(){
    int rowCount = easyTable->rowCount();
    easyTable->insertRow(rowCount);

    QTableWidgetItem* item[easyTable->columnCount()];

    // yourself items: icon and text
    for(int i=0;i<easyTable->columnCount();i++){
            item[i] = new QTableWidgetItem(QIcon(":/EasyCommon/icons/icon0/title.png"),"SCS");
            item[i]->setTextAlignment(Qt::AlignCenter);
            easyTable->setItem(rowCount,i,item[i]);
    }
}

/**
 * @brief EasyTable::clearEasyDatas
 * clear all the datas except the header
 */
void EasyTable::clearEasyDatas(){
      for(int i=easyTable->rowCount();i>-1;i--){
            easyTable->removeRow(i);
      }
}
