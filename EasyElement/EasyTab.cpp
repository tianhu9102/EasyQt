#include "EasyTab.h"

EasyTab::EasyTab(QWidget *parent) : QWidget(parent)
{
    easyTab = new QTabWidget();
}

void EasyTab::setEasyInitParams(){
    this->resize(800,600);
}
void EasyTab::setEasyDatas(QStringList tabTittles){


    QWidget* w0 = new QWidget();

    EasyTable* easyTable = new EasyTable();
    QStringList listtitle;  listtitle<<"beijing"<<"tianjin"<<"shenzhen"<<"shanghai";
    QTableWidget* easytableWgt=  easyTable->setEasyInitParams(listtitle);
    easyTable->setEasyDatas();
    easyTable->setEasyDatas();
    easyTable->setEasyDatas();
    for(int n=0;n<20;n++){
        easyTable->setEasyDatasIcons();
    }

    easyTab->addTab(w0,"fruits");
    easyTab->addTab(easytableWgt,"class");

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(easyTab);
    this->setLayout(layout);
    this->show();
    qDebug()<<"mmm";
}
