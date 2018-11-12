#include "test5dialog.h"
#include "ui_test5dialog.h"
#include <QSqlQuery>
#include <QTimer>
test5Dialog::test5Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test5Dialog)
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

test5Dialog::~test5Dialog()
{
    delete ui;
}

void test5Dialog::getdata()
{
    QSqlQuery sql_query;
    QString sql1 = "select * from test51 order by id desc limit 0,1;";
    QString sql2 = "select * from test52 order by id desc limit 0,1;";
    QString sql3 = "select * from test53 order by id desc limit 0,1;";

    sql_query.exec(sql1);



    float value;
    int estimate;
    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test51->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test51->size(), Qt::KeepAspectRatio);
            ui->label_test51->setScaledContents(true);
            ui->label_test51->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test51->size(), Qt::KeepAspectRatio);
            ui->label_test51->setScaledContents(true);
            ui->label_test51->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql2);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test52->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test52->size(), Qt::KeepAspectRatio);
            ui->label_test52->setScaledContents(true);
            ui->label_test52->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test52->size(), Qt::KeepAspectRatio);
            ui->label_test52->setScaledContents(true);
            ui->label_test52->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql3);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test53->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test53->size(), Qt::KeepAspectRatio);
            ui->label_test53->setScaledContents(true);
            ui->label_test53->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test53->size(), Qt::KeepAspectRatio);
            ui->label_test53->setScaledContents(true);
            ui->label_test53->setPixmap(*pixmap);
        }

    }


}
