#include "MainGUI.h"
#include "EasyButton.h"


MainGUI::MainGUI(QWidget *parent) : QWidget(parent)
{

    for(int i=0;i<5;i++){
         pBtn[i]= new QPushButton();
         pBtn[i]->setObjectName("btn_"+QString::number(i,10));
         qDebug()<<pBtn[i]->objectName();
         pBtn[i]->setMaximumSize(100,40);
    }

    pBtn[0]->setText("easyTable");
    pBtn[1]->setText("easyTab");
    pBtn[2]->setText("easyTree");
    pBtn[3]->setText("easyList");
    pBtn[4]->setText("easyChart");

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(pBtn[0]);
    layout->addWidget(pBtn[1]);
    layout->addWidget(pBtn[2]);
    layout->addWidget(pBtn[3]);
    layout->addWidget(pBtn[4]);

    this->setLayout(layout);
    this->resize(800,600);

    connect(pBtn[1],SIGNAL(clicked(bool)),this,SLOT(easyTabWgtExample()));
    connect(pBtn[4],SIGNAL(clicked(bool)),this,SLOT(easyChartExample()));
}

void MainGUI::easyTabWgtExample(){
    QStringList listTitle;
    listTitle<<"Google"<<"ALi"<<"Baidu";
    EasyTab* tab = new EasyTab();
    tab->setEasyInitParams();
    tab->setEasyDatas(listTitle);
}

void MainGUI::easyChartExample(){

    EasyChart* easyChart = new EasyChart();
    easyChart->setEasyStyleSheet();
    easyChart->setEasyInitParams();
    easyChart->setEasyDatas();
}

#include <QtNetwork/QtNetwork>
void MainGUI::easyNetwork(){

}
