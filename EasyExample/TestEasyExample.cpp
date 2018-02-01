#include "TestEasyExample.h"

TestEasyExample::TestEasyExample()
{

}

#include "EasyTable.h"
void TestEasyExample::easyTableExample(){

    EasyTable* easyTable = new EasyTable();
    easyTable->setEasyStyleSheet();                       // yourself style

    QStringList listHeader;
    listHeader<<"id"<<"name"<<"age"<<"add"<<"class";   // yourself nature
    QTableWidget* easytable= easyTable->setEasyInitParams(listHeader);

    // yourself datasets: here 22 rows
    easyTable->setEasyDatas();
    easyTable->setEasyDatas();
    for(int n=0;n<20;n++){
        easyTable->setEasyDatasIcons();
    }
    easytable->show();
}

#include "EasyChart.h"
void TestEasyExample::easyChartExample(){

    EasyChart* easyChart = new EasyChart();
    easyChart->setEasyStyleSheet();
    easyChart->setEasyInitParams();
    easyChart->setEasyDatas();

}

#include "EasyPC.h"
void TestEasyExample::easyPCExample(){

}
