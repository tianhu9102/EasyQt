#ifndef MAINGUI_H
#define MAINGUI_H

#include <QObject>
#include <QWidget>


#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QIcon>
#include <QDebug>


#include "ListWidget.h"
#include "TreeWidget.h"
#include "TableWidget.h"
#include "EasyButton.h"

class MainGUI : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout* vBoxLayout;
    QWidget* btWt;
    QPushButton* bt_listWt;
    QPushButton* bt_treeWt;
    QPushButton* bt_tableWt;
    QPushButton* bt_plotWt;

    ListWidget* listWigt;
    TreeWidget* treeWigt;
    TableWidget* tableWigt;

public:
    explicit MainGUI(QWidget *parent = 0);

    void setInitParameters();
    void setConstructIhm();
    void setConnections();


signals:

public slots:
    void testListWgt();
    void testTreeWgt();
    void testTableWgt();
    void testPlotWgt();


};

#endif // MAINGUI_H
