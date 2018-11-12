#include "setbounddialog.h"
#include "ui_setbounddialog.h"
#include <QSqlQuery>
#include <iostream>
#include <QMessageBox>
#include <mainwindow.h>
using namespace  std;
setBoundDialog::setBoundDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setBoundDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::ApplicationModal);
     this->setFixedSize( this->width (),this->height ());
}

setBoundDialog::~setBoundDialog()
{
    delete ui;
}

void setBoundDialog::on_pushButton_clicked()
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

    if(ui->comboBox_2->currentText() == "上阈值")
    {
        bound = "high";
    }
    else if(ui->comboBox_2->currentText() == "下阈值")
    {
        bound = "low";
    }

    QSqlQuery sql_query;

    QString sql = "UPDATE test SET value = " + ui->lineEdit->text() + " WHERE name = " +"'" +table1 + bound + "'";
    if(sql_query.exec(sql))
    {
        std::cout << "更新阈值成功" <<std::endl;

    }

    QMessageBox::information(this, QString().fromLocal8Bit("提示"),"更新成功",QMessageBox::Yes);

    this->close();




}

void setBoundDialog::on_pushButton_2_clicked()
{
    this->close();
}
