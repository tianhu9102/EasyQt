#ifndef EASYPC_H
#define EASYPC_H

#include <QWidget>

#define MB (1024*1024)

class EasyPC : public QWidget
{
    Q_OBJECT
public:
    explicit EasyPC(QWidget *parent = 0);

    void setEasyInitParams();
    void setEasyStyleSheet();



signals:

public slots:
};

#endif // EASYPC_H
