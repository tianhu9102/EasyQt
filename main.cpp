#include <QApplication>
#include "MainGUI.h"

#include "fmgment.h"
#include "MainWidget.h"
#include <QTextCodec>



#include "TestEasyExample.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    TestEasyExample easyTest;
    easyTest.easyTableExample();
    easyTest.easyChartExample();


    //设置样式  http://blog.csdn.net/liang19890820/article/details/51993435
    /*QFile qssFile(":/style/styleSheet.qss");
    qssFile.open(QFile::ReadOnly);
    app.setStyleSheet(qssFile.readAll());
    qssFile.close();*/

    //设置编码
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

   // MainGUI mainGui;
   // mainGui.show();

    return app.exec();
}
