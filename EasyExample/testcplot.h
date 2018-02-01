#ifndef TESTCPLOT_H
#define TESTCPLOT_H

#include <QWidget>

#endif // TESTCPLOT_H

namespace Ui {
class TestCPlot;
}

class TestCPlot : public QWidget
{
    Q_OBJECT

public:
    explicit TestCPlot(QWidget *parent = 0);
    ~TestCPlot();

private:
    Ui::TestCPlot *ui;


private slots:


};
