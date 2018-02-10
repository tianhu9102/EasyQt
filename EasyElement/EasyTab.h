#ifndef EASYTAB_H
#define EASYTAB_H

#include <QWidget>
#include <QTabWidget>
#include <QHBoxLayout>
#include <qdebug.h>
#include <QTableWidget>
#include "EasyTable.h"
#include <QTabWidget>

class EasyTab : public QWidget
{
    Q_OBJECT
public:
    explicit EasyTab(QWidget *parent = 0);

    void setEasyInitParams();
    void setEasyDatas(QStringList tabTittles);

private:
    QTabWidget* easyTab;

signals:

public slots:
};

#endif // EASYTAB_H
