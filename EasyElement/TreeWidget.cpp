#include "TreeWidget.h"

TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent)
{
    this->setInitParameters();
    this->setConstructIhm();
    this->setConnections();
}

void TreeWidget::setInitParameters(){
    this->resize(600,400);
    this->setWindowIcon( QIcon(":/EasyCommon/icons/icon0/lala.png") );
    this->setWindowTitle(tr("QTreeWidgetÓÃÀý"));
    //this->setStyleSheet("background:darkGray");
    this->setStyleSheet("background:darkCyan");
}

void TreeWidget::setConstructIhm(){

}

void TreeWidget::setConnections(){

//    clxzCombox->setStyleSheet("QComboBox{border:1px solid #d7d7d7; border-radius: 3px; padding: 1px 18px 1px 3px;} "
//                              "QComboBox:editable{ background: white; }"
//                              "QComboBox:!editable{ background: #fbfbfb; color:#666666}"
//                              "QComboBox::drop-down{ subcontrol-origin: padding; subcontrol-position: top right; width: 22px; border-left-width: 1px; border-left-color: #c9c9c9; border-left-style: solid; /* just a single line */ border-top-right-radius: 3px; /* same radius as the QComboBox */ border-bottom-right-radius: 3px; }"
//                              "QComboBox::down-arrow { image: url(:/down.png); }"
//                              "QComboBox::down-arrow:on { /* shift the arrow when popup is open */ top: 1px; left: 1px;}"
//                              "QComboBox QAbstractItemView::item{max-width: 30px;min-height: 20px}");

}


//sliderTime[i]->setStyleSheet("QSlider::groove:horizontal{border:0px;height:4px;}"
//                         "QSlider::sub-page:horizontal{background:white;}"
//                         "QSlider::add-page:horizontal{background:lightgray;}"
//                         "QSlider::handle:horizontal{background:white;width:10px;border-radius:5px;margin:-3px 0px -3px 0px;}"
//                         );
