#include "EasyButton.h"
/**
 * @brief EasyButton::EasyButton
 * @param parent
 */
EasyButton::EasyButton(QWidget *parent) : QWidget(parent)
{
    easyButton = new QPushButton();
}

void EasyButton::setEasyInitParams(QString text){
    easyButton->setText(text);
}

void EasyButton::setEasyStyleSheet(){
    easyButton->setStyleSheet("QPushButton{background:darkGray;} \
                               QPushButton:hover{background:yellow}\
                               QPushButton:pressed{background:skyblue}");
}

QPushButton* EasyButton::getEasyButton(){
    return this->easyButton;
}
