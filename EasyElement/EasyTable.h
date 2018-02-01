#ifndef EASYTABLE_H
#define EASYTABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>

class EasyTable: public QWidget
{
public:
    explicit EasyTable(QWidget *parent = 0);

    QTableWidget* setEasyInitParams(QStringList headerList);
    void setEasyStyleSheet();

    void setEasyDatas();
    void setEasyDatasIcons();
    void clearEasyDatas();

private:
    QTableWidget* easyTable;


};

#endif // EASYTABLE_H
