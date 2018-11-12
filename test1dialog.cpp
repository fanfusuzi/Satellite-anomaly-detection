#include "test1dialog.h"
#include "ui_test1dialog.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <string>
#include <QTimer>
#include <iostream>
using namespace std;
test1Dialog::test1Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test1Dialog)
{
    ui->setupUi(this);
    this->getdata();
    //这里实现插入是是插入数据
    this->timer = new QTimer(this);

    connect(this->timer,SIGNAL(timeout()),this,SLOT(getdata()));
    timer->start(1000);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::ApplicationModal);
     this->setFixedSize( this->width (),this->height ());



}

test1Dialog::~test1Dialog()
{
    delete ui;
}

void test1Dialog::getdata()
{
    std::cout << "test" << std::endl;
    QSqlQuery sql_query;
    QString sql1 = "select * from test11 order by id desc limit 0,1;";
    QString sql2 = "select * from test12 order by id desc limit 0,1;";
    QString sql3 = "select * from test13 order by id desc limit 0,1;";
    QString sql4 = "select * from test14 order by id desc limit 0,1;";
    QString sql5 = "select * from test15 order by id desc limit 0,1;";
    QString sql6 = "select * from test16 order by id desc limit 0,1;";
    sql_query.exec(sql1);



    float value;
    int estimate;
    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        std::cout << value << std::endl;
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test11->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test11->size(), Qt::KeepAspectRatio);
            ui->label_test11->setScaledContents(true);
            ui->label_test11->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test11->size(), Qt::KeepAspectRatio);
            ui->label_test11->setScaledContents(true);
            ui->label_test11->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql2);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test12->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test12->size(), Qt::KeepAspectRatio);
            ui->label_test12->setScaledContents(true);
            ui->label_test12->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test12->size(), Qt::KeepAspectRatio);
            ui->label_test12->setScaledContents(true);
            ui->label_test12->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql3);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test13->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test13->size(), Qt::KeepAspectRatio);
            ui->label_test13->setScaledContents(true);
            ui->label_test13->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test13->size(), Qt::KeepAspectRatio);
            ui->label_test13->setScaledContents(true);
            ui->label_test13->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql4);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();

        QString s = QString("%1").arg(value);
        ui->lineEdit_test14->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test14->size(), Qt::KeepAspectRatio);
            ui->label_test14->setScaledContents(true);
            ui->label_test14->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test14->size(), Qt::KeepAspectRatio);
            ui->label_test14->setScaledContents(true);
            ui->label_test14->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql5);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test15->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test15->size(), Qt::KeepAspectRatio);
            ui->label_test15->setScaledContents(true);
            ui->label_test15->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test15->size(), Qt::KeepAspectRatio);
            ui->label_test15->setScaledContents(true);
            ui->label_test15->setPixmap(*pixmap);
        }
    }

    sql_query.exec(sql6);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test16->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test16->size(), Qt::KeepAspectRatio);
            ui->label_test16->setScaledContents(true);
            ui->label_test16->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test16->size(), Qt::KeepAspectRatio);
            ui->label_test16->setScaledContents(true);
            ui->label_test16->setPixmap(*pixmap);
        }

    }

}
