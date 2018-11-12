#include "test2dialog.h"
#include "ui_test2dialog.h"
#include <QSqlQuery>
#include <QTimer>
test2Dialog::test2Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test2Dialog)
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

test2Dialog::~test2Dialog()
{
    delete ui;
}

void test2Dialog::getdata()
{
    QSqlQuery sql_query;
    QString sql1 = "select * from test21 order by id desc limit 0,1;";
    QString sql2 = "select * from test22 order by id desc limit 0,1;";
    QString sql3 = "select * from test23 order by id desc limit 0,1;";
    QString sql4 = "select * from test24 order by id desc limit 0,1;";
    QString sql5 = "select * from test25 order by id desc limit 0,1;";
    QString sql6 = "select * from test26 order by id desc limit 0,1;";
    QString sql7 = "select * from test27 order by id desc limit 0,1;";
    QString sql8 = "select * from test28 order by id desc limit 0,1;";
    QString sql9 = "select * from test29 order by id desc limit 0,1;";
    QString sql10 = "select * from test210 order by id desc limit 0,1;";
    sql_query.exec(sql1);



    float value;
    int estimate;
    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test21->setText(s);

        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test21->size(), Qt::KeepAspectRatio);
            ui->label_test21->setScaledContents(true);
            ui->label_test21->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test21->size(), Qt::KeepAspectRatio);
            ui->label_test21->setScaledContents(true);
            ui->label_test21->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql2);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test22->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test22->size(), Qt::KeepAspectRatio);
            ui->label_test22->setScaledContents(true);
            ui->label_test22->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test22->size(), Qt::KeepAspectRatio);
            ui->label_test22->setScaledContents(true);
            ui->label_test22->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql3);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test23->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test23->size(), Qt::KeepAspectRatio);
            ui->label_test23->setScaledContents(true);
            ui->label_test23->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test23->size(), Qt::KeepAspectRatio);
            ui->label_test23->setScaledContents(true);
            ui->label_test23->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql4);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();

        QString s = QString("%1").arg(value);
        ui->lineEdit_test24->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test24->size(), Qt::KeepAspectRatio);
            ui->label_test24->setScaledContents(true);
            ui->label_test24->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test24->size(), Qt::KeepAspectRatio);
            ui->label_test24->setScaledContents(true);
            ui->label_test24->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql5);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test25->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test25->size(), Qt::KeepAspectRatio);
            ui->label_test25->setScaledContents(true);
            ui->label_test25->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test25->size(), Qt::KeepAspectRatio);
            ui->label_test25->setScaledContents(true);
            ui->label_test25->setPixmap(*pixmap);
        }
    }

    sql_query.exec(sql6);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test26->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test26->size(), Qt::KeepAspectRatio);
            ui->label_test26->setScaledContents(true);
            ui->label_test26->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test26->size(), Qt::KeepAspectRatio);
            ui->label_test26->setScaledContents(true);
            ui->label_test26->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql7);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test27->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test27->size(), Qt::KeepAspectRatio);
            ui->label_test27->setScaledContents(true);
            ui->label_test27->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test27->size(), Qt::KeepAspectRatio);
            ui->label_test27->setScaledContents(true);
            ui->label_test27->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql8);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test28->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test28->size(), Qt::KeepAspectRatio);
            ui->label_test28->setScaledContents(true);
            ui->label_test28->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test28->size(), Qt::KeepAspectRatio);
            ui->label_test28->setScaledContents(true);
            ui->label_test28->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql9);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test29->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test29->size(), Qt::KeepAspectRatio);
            ui->label_test29->setScaledContents(true);
            ui->label_test29->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test29->size(), Qt::KeepAspectRatio);
            ui->label_test29->setScaledContents(true);
            ui->label_test29->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql10);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test210->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test210->size(), Qt::KeepAspectRatio);
            ui->label_test210->setScaledContents(true);
            ui->label_test210->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test210->size(), Qt::KeepAspectRatio);
            ui->label_test210->setScaledContents(true);
            ui->label_test210->setPixmap(*pixmap);
        }

    }


}
