#include "getdatadialog.h"
#include "ui_getdatadialog.h"
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

using namespace std;
getDataDialog::getDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getDataDialog)
{
    ui->setupUi(this);

    //设置图标

    //
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString str = time.toString("yyyy-MM-dd"); //设置显示格式
    ui->comboBox_2->addItem(str);
    ui->comboBox_3->addItem(str);
    for(int i = 1;i <= 10;i ++)
    {


        QString BeforeDaystr=time.addDays(-i).toString("yyyy-MM-dd");

        cout << "next is " << BeforeDaystr.toStdString() << endl;
        ui->comboBox_2->addItem(BeforeDaystr);
        ui->comboBox_3->addItem(BeforeDaystr);
    }
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::ApplicationModal);
}

getDataDialog::~getDataDialog()
{
    delete ui;
}

void getDataDialog::on_pushButton_2_clicked()
{
    this->close();
}

void getDataDialog::on_pushButton_clicked()
{
    QString table1;

    QString bound;
    if (ui->comboBox->currentText() == "冷却水出水温度")
    {

        table1 = "test11";



     }
    else if(ui->comboBox->currentText() == "冷却水出口水压")
    {

        //设置当前表为
        table1 = "test12";
    }
    else if(ui->comboBox->currentText() == "冷却水水流量")
    {


            //设置当前表为
            table1 = "test13";


    }
    else if(ui->comboBox->currentText() == "冷却水回水温度")
    {

            //设置当前表为
            table1 = "test14";


    }
    else if(ui->comboBox->currentText() == "冷却水机组水控制设定温度")
    {

            //设置当前表为
            table1 = "test15";


    }
    else if(ui->comboBox->currentText() == "冷却水压缩机排气温度")
    {

            //设置当前表为
            table1 = "test16";


    }

    if (ui->comboBox->currentText() == "低温泵1级冷头温度")
    {

        //设置当前表为
        table1 = "test21";

    }

    else if (ui->comboBox->currentText() == "低温泵2级冷头温度")
    {

        //设置当前表为
        table1 = "test22";

    }

    else if (ui->comboBox->currentText() == "低温泵1#胀板温度")
    {

        //设置当前表为
        table1 = "test23";

    }

    else if (ui->comboBox->currentText() == "低温泵2#胀板温度")
    {

        //设置当前表为
        table1 = "test24";

    }

    else if (ui->comboBox->currentText() == "低温泵3#胀板温度")
    {

        //设置当前表为
        table1 = "test25";

    }

    else if (ui->comboBox->currentText() == "低温泵供电状态")
    {

        //设置当前表为
        table1 = "test26";

    }

    else if (ui->comboBox->currentText() == "低温泵1级加热器运行状态")
    {

        //设置当前表为
        table1 = "test27";

    }

    else if (ui->comboBox->currentText() == "低温泵2级加热器运行状态")
    {

        //设置当前表为
        table1 = "test28";

    }
    else if (ui->comboBox->currentText() == "低温泵状态")
    {

        //设置当前表为
        table1 = "test29";

    } else if (ui->comboBox->currentText() == "低温泵运行电流")
    {

        //设置当前表为
        table1 = "test210";

    }

    if (ui->comboBox->currentText() == "分子泵电流")
    {

        //设置当前表为
        table1 = "test31";

    }
    else  if (ui->comboBox->currentText() == "分子泵频率")
    {

        //设置当前表为
        table1 = "test32";

    }
    else  if (ui->comboBox->currentText() == "分子泵状态")
    {


        //设置当前表为
        table1 = "test33";

    }
    else  if (ui->comboBox->currentText() == "分子泵温度")
    {


        //设置当前表为
        table1 = "test34";

    }



    if (ui->comboBox->currentText() == "热沉平均温度")
    {


        //设置当前表为
        table1 = "test41";

    }


    if (ui->comboBox->currentText() == "低温系统1#液氮泵电流")
    {

        //设置当前表为
        table1 = "test51";

    }else  if (ui->comboBox->currentText() == "低温系统1#液氮泵电压")
    {

        //设置当前表为
        table1 = "test52";

    }else  if (ui->comboBox->currentText() == "低温系统1#液氮泵功率")
    {

        //设置当前表为
        table1 = "test53";

    }

    if (ui->comboBox->currentText() == "储槽液位")
    {

        //设置当前表为
        table1 = "test61";

    }else  if (ui->comboBox->currentText() == "储槽压力")
    {

        //设置当前表为
        table1 = "test62";

    }


    QString get_sql = "select * from  "+ table1;
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
    QMessageBox::information(this, QString().fromLocal8Bit("提示"),"导出成功",QMessageBox::Yes);
    this->setFixedSize( this->width (),this->height ());
    this->close();
}
