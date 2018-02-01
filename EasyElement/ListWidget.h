#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QICon>
#include <QLineEdit>
#include <QSpacerItem>

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>

class ListWidget : public QWidget
{
    Q_OBJECT

private:
    QHBoxLayout* hBoxLayout;
    QListWidget* qlistWidget;

    QVBoxLayout* vBLayout;
    QWidget* infoWidget;
    QLabel* labelInfo;
    QLineEdit* txtItem;
    QPushButton* btn_Ok;


public:
    explicit ListWidget(QWidget *parent = 0);
    void setInitParameters();
    void setConstructIhm();
    void setConnections();

signals:

private slots:
    void doubleClickFun(QListWidgetItem* item);
    void addItemFun();

};

#endif // LISTWIDGET_H
