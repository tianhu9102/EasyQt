#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QIcon>

#include <QTreeWidget>
#include <QTreeWidgetItem>

class TreeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = 0);

    void setInitParameters();
    void setConstructIhm();
    void setConnections();

signals:

public slots:
};

#endif // TREEWIDGET_H
