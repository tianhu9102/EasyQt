#ifndef REALTIMECURVEQCHARTWIDGET_H
#define REALTIMECURVEQCHARTWIDGET_H
#include <QWidget>
#include <QList>

#include <QSplineSeries>
#include <QScatterSeries>
#include <QChart>
#include <QChartView>
#include <QPushButton>
#include <qdebug.h>
#include <QCategoryAxis>

using namespace QtCharts;
class RealTimeCurveQChartWidget : public QWidget {
    Q_OBJECT
public:
    explicit RealTimeCurveQChartWidget(QWidget *parent = 0);
    ~RealTimeCurveQChartWidget();
protected:
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
private:
    /**
     * ���յ�����Դ�����������ݣ�����Դ������λ�����ɼ������������ȡ�
     */
    void dataReceived(int value);
    int timerId;
    int maxSize;  // data ���洢 maxSize ��Ԫ��
    int maxX;
    int maxY;
    QList<double> data; // �洢ҵ�����ݵ� list
    QChart *chart;
    QChartView *chartView;
    QSplineSeries *splineSeries;
    QScatterSeries *scatterSeries;

    QCategoryAxis *axisY3;

public slots:
    void addLevel();
    void deleLevel();

    void dopBtnStop();
    void dopBtnStart();

};
#endif // REALTIMECURVEQCHARTWIDGET_H
