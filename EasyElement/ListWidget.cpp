#include "ListWidget.h"

ListWidget::ListWidget(QWidget *parent) : QWidget(parent)
{
    this->setInitParameters();
    this->setConstructIhm();
    this->setConnections();
}


void ListWidget::setInitParameters(){
    this->resize(600,400);
    this->setWindowIcon( QIcon(":/EasyCommon/icons/icon0/lala.png") );
    this->setWindowTitle(tr("QListWidget示例"));

    qlistWidget = new QListWidget();
    QListWidgetItem* item0 = new QListWidgetItem(QIcon(":/EasyCommon/icons/icon0/image_configuration.png"),"fire",qlistWidget);
    QListWidgetItem* item1 = new QListWidgetItem(QIcon(":/EasyCommon/icons/icon0/image_update.png"),"water",qlistWidget);
    QListWidgetItem* item2 = new QListWidgetItem(QIcon(":/EasyCommon/icons/icon0/image_zoomin.png"),"stone",qlistWidget);
    QListWidgetItem* item3 = new QListWidgetItem(QIcon(":/EasyCommon/icons/icon0/image_zoomout.png"),"steel",qlistWidget);

    //设置文字位置
    //item0->setTextAlignment(Qt::AlignCenter);

    //改变item大小
    item0->setSizeHint(QSize(60,60));

    item0->setFlags(Qt::ItemIsSelectable |  Qt::ItemIsEnabled);
    item1->setFlags(Qt::ItemIsSelectable |  Qt::ItemIsEnabled);
    item2->setFlags(Qt::ItemIsSelectable |  Qt::ItemIsEnabled);
    item3->setFlags(Qt::ItemIsSelectable |  Qt::ItemIsEnabled);


    //设置item形式为图标在上，文字在下
    qlistWidget->setViewMode(QListWidget::IconMode);

    //在指定位置插入元素
    QListWidgetItem*  itemNew = new QListWidgetItem(QIcon(":/EasyCommon/icons/icon0/image_zoomout.png"),"KK",qlistWidget);
    qlistWidget->insertItem(2,itemNew);

    infoWidget = new QWidget();
    vBLayout = new QVBoxLayout(infoWidget);
    labelInfo = new QLabel("新增item:");
    txtItem = new QLineEdit();
    btn_Ok = new QPushButton("添加");
    //vBLayout->addWidget(labelInfo);
    vBLayout->addWidget(txtItem);
    vBLayout->addWidget(btn_Ok);
    vBLayout->addSpacerItem(new QSpacerItem(20,300));


    //labelInfo->setFixedWidth(100);
    hBoxLayout = new QHBoxLayout(this);
    hBoxLayout->addWidget(qlistWidget);
    hBoxLayout->addWidget(infoWidget);

}

void ListWidget::setConstructIhm(){
    
}
void ListWidget::setConnections(){

    //QObject::connect(qlistWidget, SIGNAL(currentTextChanged(const QString &)), labelInfo, SLOT(setText(const QString &)));

    connect(this->btn_Ok,SIGNAL(clicked(bool)),this,SLOT(addItemFun()) );

    //item双击事件
    QObject::connect(this->qlistWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)) ,this,SLOT(doubleClickFun(QListWidgetItem*)) );

}

void ListWidget::doubleClickFun(QListWidgetItem* item){
    QMessageBox::information(this,"waring",item->text());
}

void ListWidget::addItemFun(){

    if(this->txtItem->text()!=NULL){
        QListWidgetItem* item = new QListWidgetItem();
        item->setText( this->txtItem->text() );
        this->qlistWidget->addItem(item);
    }else{
         QMessageBox::information(this,"waring",tr("不能为空"));
    }


    this->txtItem->clear();
}
