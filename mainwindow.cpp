#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <QSqlDatabase>
#include<iostream>
#include <QString>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QDateTime>
#include <string>
#include <QHeaderView>
#include <QTimer>
#include <QChart>
#include <QGridLayout>
#include <fstream>
#include <sstream>
#include "history.h"
#include <logindia.h>
#include "setbounddialog.h"
#include "getdatadialog.h"
#include "settimedialog.h"
#include "handbookdialog.h"
#include "test1dialog.h"
#include "test2dialog.h"
#include "test3dialog.h"
#include "test4dialog.h"
#include "test5dialog.h"
#include "test6dialog.h"
#include "alldia.h"
#include "setmodedialog.h"
#include "connection.h"
using namespace std;

QString table;

int timeSetting = 3 * 1000;


QString DateSetting = "0";
QString HourSettting = "0";

std::vector<rawdata> rawDataList;
int count_rawData = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    chart(new QChart)
{


    ui->setupUi(this);

    //这里实现插入是是插入数据
    QTimer *timer = new QTimer(this);
    QString s = "test11";
    connect(timer,SIGNAL(timeout()),this,SLOT(insertData()));
    timer->start(1000);
    count = 0;

    //连接ihis
    this->ihis = new IHistorianData();

    //ui->tableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);

    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    initChart();

    timer1 = new QTimer(this);

    connect(timer1, SIGNAL(timeout()), this, SLOT(timerSlot()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(toTable()));

    //设置combox
    insertDataCom();
    //
    this->test = true;
    this->timeSpan = 3 * 1000;

    ui->treeWidget->setItemsExpandable(false);
    ui->treeWidget->expandAll();


}

void MainWindow::insertData()
{
    /*
    QSqlQuery sql_query;
    QString insert_sql1 = "INSERT INTO test11 (name,value,estimate) VALUES ('wang',1.0,1 );";
    QString insert_sql2 = "INSERT INTO test12 (name,value,estimate) VALUES ('li',2.0,2 );";
    QString insert_sql3 = "INSERT INTO test13 (name,value,estimate) VALUES ('gg',3.0,3 );";
    QString insert_sql4 = "INSERT INTO test14 (name,value,estimate) VALUES ('dd',4.0,4 );";
    QString insert_sql5 = "INSERT INTO test15 (name,value,estimate) VALUES ('aa',5.0,5 );";
    QString insert_sql6 = "INSERT INTO test12 (name,value,estimate) VALUES ('mm',6.0,6 );";
    sql_query.exec(insert_sql1);
    sql_query.exec(insert_sql3);
    sql_query.exec(insert_sql4);
    sql_query.exec(insert_sql5);
    sql_query.exec(insert_sql6);
    if(!sql_query.exec(insert_sql2))
    {
        //cout <<"insert wrong";
    }
    else
    {
        //qDebug() << "insert successfully";
    }
    */

    this->insertOneData("test11");
    this->insertOneData("test12");
    this->insertOneData("test13");
    this->insertOneData("test14");
    this->insertOneData("test15");
    this->insertOneData("test16");

    this->insertOneData("test21");
    this->insertOneData("test22");
    this->insertOneData("test23");
    this->insertOneData("test24");
    this->insertOneData("test25");
    this->insertOneData("test26");
    this->insertOneData("test27");
    this->insertOneData("test28");
    this->insertOneData("test29");
    this->insertOneData("test210");

    this->insertOneData("test31");
    this->insertOneData("test32");
    this->insertOneData("test33");
    this->insertOneData("test34");

     this->insertOneData("test41");

    this->insertOneData("test51");
    this->insertOneData("test52");
    this->insertOneData("test53");

    this->insertOneData("test61");
    this->insertOneData("test62");


    count ++;

}

MainWindow::~MainWindow()
{
    delete ui;
}







void MainWindow::getData(QString &name,QDateTime &time,int &estimate,float &value)
{
    QSqlQuery sql_query;
    QString sql = "select * from "+table+" order by id desc limit 0,1;";
    sql_query.exec(sql);

    while(sql_query.next())
    {
        time = sql_query.value(1).toDateTime();
        name = sql_query.value(2).toString();

        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();

    }




}

void MainWindow::on_treeWidget_doubleClicked(const QModelIndex &index)
{


    this->timeSpan = timeSetting;
    QTreeWidgetItem *item = ui->treeWidget->currentItem();

    if (item->text(0) == "总报警面板")
    {
        diaall = new allDia();
        diaall->show();

     }
    if (item->text(0) == "冷却水出水温度")
    {
        //清空原来的数据的数据
        //timer1->disconnect();
        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test11";

        //设置表的范围
        setChartRange();

     }
    else if(item->text(0) == "冷却水出口水压")
    {        
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test12";
        //设置表的范围
        setChartRange();






    }
    else if(item->text(0) == "冷却水水流量")
    {
            //清空原来的数据的数据

            this->series->clear();
            ui->tableWidget->setRowCount(0);
            ui->tableWidget->clearContents();
            //重新设置
            timer1->start(this->timeSpan);
            //设置当前表为
            table = "test13";
            //设置表的范围
            setChartRange();

    }
    else if(item->text(0) == "冷却水回水温度")
    {
            //清空原来的数据的数据

            this->series->clear();
            ui->tableWidget->setRowCount(0);
            ui->tableWidget->clearContents();
            //重新设置
            timer1->start(this->timeSpan);
            //设置当前表为
            table = "test14";
            //设置表的范围
            setChartRange();

    }
    else if(item->text(0) == "冷却水机组水控制设定温度")
    {
            //清空原来的数据的数据

            this->series->clear();
            ui->tableWidget->setRowCount(0);
            ui->tableWidget->clearContents();
            //重新设置
            timer1->start(this->timeSpan);
            //设置当前表为
            table = "test15";
            //设置表的范围
            setChartRange();

    }
    else if(item->text(0) == "冷却水压缩机排气温度")
    {
            //清空原来的数据的数据

            this->series->clear();
            ui->tableWidget->setRowCount(0);
            ui->tableWidget->clearContents();
            //重新设置
            timer1->start(this->timeSpan);
            //设置当前表为
            table = "test16";
            //设置表的范围
            setChartRange();

    }

    if (item->text(0) == "低温泵1级冷头温度")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test21";
        //设置表的范围
        setChartRange();
    }

    else if (item->text(0) == "低温泵2级冷头温度")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test22";
        //设置表的范围
        setChartRange();
    }

    else if (item->text(0) == "低温泵1#胀板温度")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test23";
        //设置表的范围
        setChartRange();
    }

    else if (item->text(0) == "低温泵2#胀板温度")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test24";
        //设置表的范围
        setChartRange();
    }

    else if (item->text(0) == "低温泵3#胀板温度")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test25";
        //设置表的范围
        setChartRange();
    }

    else if (item->text(0) == "低温泵供电状态")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test26";
        //设置表的范围
        setChartRange();
    }

    else if (item->text(0) == "低温泵1级加热器运行状态")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test27";
        //设置表的范围
        setChartRange();
    }

    else if (item->text(0) == "低温泵2级加热器运行状态")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test28";
        //设置表的范围
        setChartRange();
    }
    else if (item->text(0) == "低温泵状态")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test29";
        //设置表的范围
        setChartRange();
    } else if (item->text(0) == "低温泵运行电流")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test210";
        //设置表的范围
        setChartRange();
    }

    if (item->text(0) == "分子泵电流")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test31";
        //设置表的范围
        setChartRange();
    }
    else  if (item->text(0) == "分子泵频率")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test32";
        //设置表的范围
        setChartRange();
    }
    else  if (item->text(0) == "分子泵状态")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test33";
        //设置表的范围
        setChartRange();
    }
    else  if (item->text(0) == "分子泵温度")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test34";
        //设置表的范围
        setChartRange();
    }



    if (item->text(0) == "热沉平均温度")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test41";
        //设置表的范围
        setChartRange();
    }


    if (item->text(0) == "低温系统1#液氮泵电流")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test51";
        //设置表的范围
        setChartRange();
    }else  if (item->text(0) == "低温系统1#液氮泵电压")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test52";
        //设置表的范围
        setChartRange();
    }else  if (item->text(0) == "低温系统1#液氮泵功率")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test53";
        //设置表的范围
        setChartRange();
    }

    if (item->text(0) == "储槽液位")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test61";
        //设置表的范围
        setChartRange();
    }else  if (item->text(0) == "储槽压力")
    {
        //清空原来的数据的数据

        this->series->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        //重新设置
        timer1->start(this->timeSpan);
        //设置当前表为
        table = "test62";
        //设置表的范围
        setChartRange();
    }


    if(item->text(0) == "冷却水机组")
    {
        diaa = new test1Dialog();
        diaa->show();
    }
    else if(item->text(0) == "低温泵")
    {
        diab = new test2Dialog();
        diab->show();
    }
    else if(item->text(0) == "分子泵")
    {
        diac = new test3Dialog();
        diac->show();

    }else if(item->text(0) == "热沉温度")
    {
        diad = new test4Dialog();
        diad->show();
    }else if(item->text(0) == "液氮泵")
    {
        diae = new test5Dialog();
        diae->show();
    }else if(item->text(0) == "液氮储槽"){
        diaf = new test6Dialog();
        diaf->show();
    }









}

QSqlDatabase MainWindow::getConnect()
{
    //数据库连接文件
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("weixingsuo.db");

    if (!db.open()) {

       QMessageBox::critical(0, qApp->tr("Cannot open database"),

           qApp->tr("Unable to establisha database connection."

                     ), QMessageBox::Cancel);
       cout << "lianjie shibai" << endl;
       return db;


    }
    else
        cout << "chenggong lianjie" << endl;
}

void MainWindow::toTable()
{
    QString name;
    QDateTime time;
    int estimate;
    float value;


    MainWindow::getData(name,time,estimate,value);

    int rowIndex = ui->tableWidget->rowCount();

    ui->tableWidget->setRowCount(rowIndex + 1);//总行数增加1

    ui->tableWidget->setRowHeight(rowIndex  , 24);


    QString content1 = time.toString("yyyy-MM-dd");


    QString content2 = time.toString("HH:mm:ss");
    QString content3 = "出水口水流温度";
    QString content4 = QString("%1").arg(value);
    QString content5;
    if(estimate == 1)
    {
        content5= "正常范围";

    }
    else{
        content5 = "异常数据";
    }
    this->setAlarm(estimate);

    QTableWidgetItem *item1 = new QTableWidgetItem (content1);
    QTableWidgetItem *item2 = new QTableWidgetItem (content2);
    QTableWidgetItem *item3 = new QTableWidgetItem (content3);
    QTableWidgetItem *item4 = new QTableWidgetItem (content4);
    QTableWidgetItem *item5 = new QTableWidgetItem (content5);



    //ui->tableWidget->setItem(rowIndex, 0, item1);
    ui->tableWidget->setItem(rowIndex,0,item1);
    ui->tableWidget->setItem(rowIndex,1,item2);
    ui->tableWidget->setItem(rowIndex,2,item3);
    ui->tableWidget->setItem(rowIndex,3,item4);
    ui->tableWidget->setItem(rowIndex,4,item5);

    ui->tableWidget->setFocus();
    ui->tableWidget->scrollToBottom();
}

void MainWindow::initChart()
{
    series = new QLineSeries;

    chart->addSeries(series);

    //    series->setUseOpenGL(true);

    chart->createDefaultAxes();
    chart->axisY()->setRange(-10, 10);
    chart->axisX()->setRange(0, 60);

    chart->axisX()->setTitleFont(QFont("Microsoft YaHei", 10, QFont::Normal, true));
    chart->axisY()->setTitleFont(QFont("Microsoft YaHei", 10, QFont::Normal, true));
    chart->axisX()->setTitleText("Time/ " + QString(timeSetting / 1000) + "sec");
    chart->axisY()->setTitleText("Value");

    chart->axisX()->setGridLineVisible(false);
    chart->axisY()->setGridLineVisible(false);

    /* hide legend */
    chart->legend()->hide();
    chart->setTitle("real data chart");
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);



    QGridLayout *layout = new QGridLayout();
    layout->addWidget(chartView);
    ui->widget_3->setLayout(layout);
}

void MainWindow::updateData()
{
    int i;
    QVector<QPointF> oldData = series->pointsVector();
    QVector<QPointF> data;

    if (oldData.size() < 60) {
        data = series->pointsVector();
    } else {
        /* 添加之前老的数据到新的vector中，不复制最前的数据，即每次替换前面的数据
         * 由于这里每次只添加1个数据，所以为1，使用时根据实际情况修改
         */
        for (i = 1; i < oldData.size(); ++i) {
            data.append(QPointF(i - 1 , oldData.at(i).y()));
        }
    }

    qint64 size = data.size();
    /* 这里表示插入新的数据，因为每次只插入1个，这里为i < 1,
     * 但为了后面方便插入多个数据，先这样写
     */

    QString name;
    QDateTime time;
    int estimate;
    float value;
    MainWindow::getData(name,time,estimate,value);

    for(i = 0; i < 1; ++i){
        data.append(QPointF(i + size, value));
    }

    series->replace(data);

    count++;

}

void MainWindow::timerSlot()
{
    if (QObject::sender() == timer1) {
        updateData();
    }
}

void MainWindow::setChartRange()
{
    float low;
    float high;
    float avg;
    getOneDate(table,low,high,avg);
    this->chart->axisY()->setRange(low, high);

}

void MainWindow::insertOneData(QString s)
{
    QSqlQuery sql_query;

    RealDate date = this->readdata(s);
    float result = date.value;
    int state = date.state;
    QString time = date.time;

    QString insert_sql = "INSERT INTO "+ s +" (name,value,estimate,time) VALUES ('"+s+"',"+ QString("%1").arg(result)+",1 ,'"+time+"');";


    //sql_query.exec(insert_sql1);

    if(!sql_query.exec(insert_sql))
    {
        cout <<"insert wrong " << s.toStdString() << result <<endl;
    }
    else
    {
        //qDebug() << "insert successfully";
    }

}

void MainWindow::getOneDate(QString s,float &low,float &high,float &avg)
{
     QString get_sql1 = "select * from  test where name like '" +s+ "low'";
     QString get_sql2 = "select * from  test where name like '" +s+ "high'";
     QString get_sql3 = "select * from  test where name like '" +s+ "avg'";

     QSqlQuery sql_query;

     sql_query.exec(get_sql1);

     while(sql_query.next())
     {
         low = sql_query.value(1).toFloat();
     }

     sql_query.exec(get_sql2);

     while(sql_query.next())
     {
         high = sql_query.value(1).toFloat();
     }

     sql_query.exec(get_sql3);

     while(sql_query.next())
     {
         avg = sql_query.value(1).toFloat();
     }


}
void MainWindow::insertDataCom()
{

    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString str = time.toString("yyyy-MM-dd"); //设置显示格式
    ui->comboBox->addItem(str);
    ui->comboBox_2->addItem(str);
    for(int i = 1;i <= 10;i ++)
    {


        QString BeforeDaystr=time.addDays(-i).toString("yyyy-MM-dd");

        cout << "next is " << BeforeDaystr.toStdString() << endl;
        ui->comboBox->addItem(BeforeDaystr);
        ui->comboBox_2->addItem(BeforeDaystr);
    }




}

void MainWindow::setTime(int span)
{

    timeSetting = span;
}

void MainWindow::setMode(QString s1,QString s2)
{
    DateSetting = s1;
    HourSettting = s2;
    count_rawData = 0;
    std:: cout << DateSetting.toStdString() << std::endl;
    std:: cout << HourSettting.toStdString() << std::endl;
}

void MainWindow::on_pushButton_clicked()
{




    QString get_sql = "select * from  "+ table;
    QSqlQuery sql_query;
    ofstream outFile;
    outFile.open("data.csv", ios::out); // 打开模式可省略
    sql_query.exec(get_sql);
    while(sql_query.next())
    {
        string date = sql_query.value(1).toString().toStdString();
        float value = sql_query.value(3).toFloat();




        outFile << date << ',' << value << ',' << "正常状态" << endl;


    }
    outFile.close();
    QMessageBox::information(NULL, "对话框", "导出成功", QMessageBox::Yes );

}

void MainWindow::setAlarm(int estimate)
{
    if(this->test)
    {
        if(estimate == 1)
             ui->label_4->setPixmap(QPixmap(":/images/images/green.jpg"));
        else
             ui->label_4->setPixmap(QPixmap(":/images/images/red.jpg"));
    }







}

void MainWindow::on_pushButton_2_clicked()
{
    this->test = false;
    QTime delayTime = QTime::currentTime().addMSecs(1000 * 60 * 20);	//在当前时间上增加3S
    ui->label_4->setPixmap(QPixmap(":/images/images/green.jpg"));
    /* lyh delete -> 避免有拉拽小票冲突 */
    while( QTime::currentTime() < delayTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->test = true;
}


void MainWindow::on_pushButton_3_clicked()
{
    h = new history();
    h->show();

}

void MainWindow::on_action_triggered()
{
    dia1 = new setBoundDialog();
    dia1->show();
}

void MainWindow::on_action_6_triggered()
{
    dia3 = new setTimeDialog();
    dia3->show();
}

void MainWindow::on_action_2_triggered()
{
    //导出数据
    dia2 = new getDataDialog();
    dia2->show();
}

void MainWindow::on_action_5_triggered()
{

    dia4 = new handbookDialog();
    dia4->show();

}


void MainWindow::on_action_7_triggered()
{

    diaMode = new setModeDialog();
    diaMode->show();

}

void MainWindow::on_action_8_triggered()
{
    DateSetting = "0";
    HourSettting = "0";
}

MainWindow::RealDate MainWindow::readdata(QString table)
{

    RealDate t;
    rawdata r;
    r.quality = GOOD;
    r.timestamp.tm_year = 1994;
    r.timestamp.tm_mon = 12;
    r.timestamp.tm_mday = 20;
    r.timestamp.tm_hour = 12;
    r.timestamp.tm_min = 45;
    r.timestamp.tm_sec = 23;
    if(DateSetting ==QString::fromLocal8Bit("0") && HourSettting == QString::fromLocal8Bit("0"))
    {

        t.state = 1;
        t.tag = "sss";
        t.time = "2015-01-12 04:00";
        t.value = 3;
        return t;
    }
    else
    {
        if(count_rawData < 20000)
        {
            //r = data[count];
            t.state = 1;
            t.tag = "sss";
            t.time =  QString::number(1994) + QString("-") + QString::number(12) + QString("-") + QString::number(12) + QString(" ") + QString::number(20) +QString(":")+ QString::number(10)+  QString(":") +QString::number(31);
            t.value =15;
            count_rawData ++;
        }

        return t;
    }




}

QString MainWindow::getTag(QString table)
{

    return "test";

}


