#ifndef EASYBUTTON_H
#define EASYBUTTON_H

#include <QWidget>
#include <QPushButton>

class EasyButton : public QWidget
{
    Q_OBJECT
public:
    explicit EasyButton(QWidget *parent = 0);

    void setEasyInitParams(QString text);
    void setEasyStyleSheet();

    QPushButton* getEasyButton();

private:
    QPushButton* easyButton;

signals:

public slots:
};

#endif // EASYBUTTON_H
