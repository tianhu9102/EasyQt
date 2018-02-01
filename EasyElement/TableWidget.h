#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QIcon>

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHBoxLayout>
#include <QScrollBar>
#include <QHeaderView>

class TableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TableWidget(QWidget *parent = 0);
    void setInitParameters();
    void setConstructIhm();
    void setConnections();

signals:

public slots:
};

#endif // TABLEWIDGET_H
