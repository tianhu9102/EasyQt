#include "EasyQHcommunicate.h"

EasyQHcommunicate::EasyQHcommunicate(QWidget *parent) : QWidget(parent)
{
     this->manager = new QNetworkAccessManager(this);

     connect(this->manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(doResponse(QNetworkReply*)));

     this->manager->get(QNetworkRequest(QUrl("http://localhost:8080/DemoSSM/user/queryUserDataSets2")));
}

EasyQHcommunicate::~EasyQHcommunicate(){

}

void EasyQHcommunicate::doResponse(QNetworkReply* reply){

    QTextCodec *codec = QTextCodec::codecForName("utf8");
    //ʹ��utf8����, ����������ʾ����
    QString str = codec->toUnicode(reply->readAll());
    qDebug()<<str;
}
