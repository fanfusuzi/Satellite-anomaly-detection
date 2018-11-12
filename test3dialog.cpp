#include "test3dialog.h"
#include "ui_test3dialog.h"
#include <QSqlQuery>
#include <QTimer>
test3Dialog::test3Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test3Dialog)
{
    ui->setupUi(this);
    this->getdata();
    //这里实现插入是是插入数据
    QTimer *timer = new QTimer(this);
    QString s = "test11";
    connect(timer,SIGNAL(timeout()),this,SLOT(insertData()));
    timer->start(1000);

    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::ApplicationModal);
     this->setFixedSize( this->width (),this->height ());
}

test3Dialog::~test3Dialog()
{
    delete ui;
}

void test3Dialog::getdata()
{
    QSqlQuery sql_query;
    QString sql1 = "select * from test31 order by id desc limit 0,1;";
    QString sql2 = "select * from test32 order by id desc limit 0,1;";
    QString sql3 = "select * from test33 order by id desc limit 0,1;";
    QString sql4 = "select * from test34 order by id desc limit 0,1;";

    sql_query.exec(sql1);


    float value;
    int estimate;
    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test31->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test31->size(), Qt::KeepAspectRatio);
            ui->label_test31->setScaledContents(true);
            ui->label_test31->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test31->size(), Qt::KeepAspectRatio);
            ui->label_test31->setScaledContents(true);
            ui->label_test31->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql2);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test32->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test32->size(), Qt::KeepAspectRatio);
            ui->label_test32->setScaledContents(true);
            ui->label_test32->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test32->size(), Qt::KeepAspectRatio);
            ui->label_test32->setScaledContents(true);
            ui->label_test32->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql3);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test33->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test33->size(), Qt::KeepAspectRatio);
            ui->label_test33->setScaledContents(true);
            ui->label_test33->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test33->size(), Qt::KeepAspectRatio);
            ui->label_test33->setScaledContents(true);
            ui->label_test33->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql4);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();

        QString s = QString("%1").arg(value);
        ui->lineEdit_test34->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test34->size(), Qt::KeepAspectRatio);
            ui->label_test34->setScaledContents(true);
            ui->label_test34->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test34->size(), Qt::KeepAspectRatio);
            ui->label_test34->setScaledContents(true);
            ui->label_test34->setPixmap(*pixmap);
        }

    }




}
