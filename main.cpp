#include <QApplication>
#include "MainGUI.h"

#include <QTextCodec>
#include <QFile>
#include "TestEasyExample.h"
#include "EasyQHcommunicate.h"
#include "RealTimeCurveQChartWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //ÉèÖÃÑùÊ½  http://blog.csdn.net/liang19890820/article/details/51993435
    QFile qssFile(":/EasyCommon/style/easySheet1.qss");
    qssFile.open(QFile::ReadOnly);
    app.setStyleSheet(qssFile.readAll());
    qssFile.close();

    EasyQHcommunicate qh;

    MainGUI* minUI = new MainGUI();
    minUI->show();

    RealTimeCurveQChartWidget w;
       w.resize(700, 400);
       w.show();


    return app.exec();
}
