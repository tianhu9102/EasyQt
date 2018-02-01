#include "MainGUI.h"
#include "EasyButton.h"

MainGUI::MainGUI(QWidget *parent) : QWidget(parent)
{
    this->setInitParameters();
    this->setConstructIhm();
    this->setConnections();
}

void MainGUI::setInitParameters(){
    this->resize(300,600);
    this->setWindowIcon( QIcon(":/EasyCommon/icons/icon0/lala.png") );
    this->setWindowTitle(tr("主界面"));

    vBoxLayout = new QVBoxLayout(this);
    btWt = new QWidget();

    bt_listWt = new QPushButton(btWt);
    bt_treeWt = new QPushButton(btWt);
    bt_tableWt = new QPushButton(btWt);
    bt_plotWt = new QPushButton(btWt);


    //位置
    bt_listWt->setGeometry(QRect(20, 40, 80, 40));
    bt_treeWt->setGeometry(QRect(120, 40, 80, 40));
    bt_tableWt->setGeometry(QRect(20, 100, 80, 40));
    bt_plotWt->setGeometry(QRect(120, 100, 80, 40));

    //文字
    bt_listWt->setText(tr("listWidget"));
    bt_treeWt->setText(tr("treeWidget"));
    bt_tableWt->setText(tr("tableWidget"));
    bt_plotWt->setText(tr("plotWidget"));

    bt_listWt->setStyleSheet("QPushButton{background:darkGray;} \
                              QPushButton:hover{background:yellow}\
                              QPushButton:pressed{background:skyblue}");

    //样式
    /*bt_listWt->setStyleSheet("QPushButton{border-image: url(:/images/image_configuration.png);}"
                             "QPushButton:hover{border-image: url(:/images/image_update.png);}"
                             "QPushButton:pressed{border-image: url(:/images/image_zoomin.png);}");*/

    /*bt_listWt->setIcon(QIcon(":/images/image_configuration.png"));
    bt_treeWt->setIcon(QIcon(":/images/image_update.png"));
    bt_tableWt->setIcon(QIcon(":/images/image_zoomin.png"));
    bt_plotWt->setIcon(QIcon(":/images/image_zoomout.png"));*/

    listWigt = new ListWidget();
    treeWigt = new TreeWidget();
    tableWigt = new TableWidget();
}

void MainGUI::setConstructIhm(){
    vBoxLayout->addWidget(btWt);

}
void MainGUI::setConnections(){
   //connect(this->bt_listWt,SIGNAL(clicked(bool),this, SLOT(testListWgt() ) );
    connect(this->bt_listWt,SIGNAL(clicked()), this, SLOT(testListWgt()));
    connect(this->bt_treeWt,SIGNAL(clicked()), this, SLOT(testTreeWgt()));
    connect(this->bt_tableWt,SIGNAL(clicked()), this, SLOT(testTableWgt()));
    connect(this->bt_plotWt,SIGNAL(clicked()), this, SLOT(testPlotWgt()));

}
void MainGUI::testListWgt(){
    this->listWigt->show();
    this->listWigt->move(100,+50);

}
void MainGUI::testTreeWgt(){
    this->treeWigt->show();
    this->treeWigt->move(550,50);

}
void MainGUI::testTableWgt(){
    this->tableWigt->show();
    this->tableWigt->move(100,450);
}

void MainGUI::testPlotWgt(){

}
