#ifndef EASYQHCOMMUNICATE_H
#define EASYQHCOMMUNICATE_H

#include <QObject>
#include <QWidget>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtWidgets/QWidget>
#include <QTextCodec>
#include <QString>
#include <QUrl>
#include <QDebug>

class EasyQHcommunicate: public QWidget
{
    Q_OBJECT

public:
    EasyQHcommunicate(QWidget *parent = 0);
    ~EasyQHcommunicate();

private:

    QNetworkAccessManager* manager;

public Q_SLOTS:
    void doResponse(QNetworkReply*reply);

};

#endif // EASYQHCOMMUNICATE_H
