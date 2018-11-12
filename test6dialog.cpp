#include "test6dialog.h"
#include "ui_test6dialog.h"
#include <QSqlQuery>
#include <QTimer>
test6Dialog::test6Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test6Dialog)
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

test6Dialog::~test6Dialog()
{
    delete ui;
}

void test6Dialog::getdata()
{
    QSqlQuery sql_query;
    QString sql1 = "select * from test61 order by id desc limit 0,1;";
    QString sql2 = "select * from test62 order by id desc limit 0,1;";


    sql_query.exec(sql1);



    float value;
    int estimate;
    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test61->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test61->size(), Qt::KeepAspectRatio);
            ui->label_test61->setScaledContents(true);
            ui->label_test61->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test61->size(), Qt::KeepAspectRatio);
            ui->label_test61->setScaledContents(true);
            ui->label_test61->setPixmap(*pixmap);
        }

    }

    sql_query.exec(sql2);

    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test62->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test62->size(), Qt::KeepAspectRatio);
            ui->label_test62->setScaledContents(true);
            ui->label_test62->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test62->size(), Qt::KeepAspectRatio);
            ui->label_test62->setScaledContents(true);
            ui->label_test62->setPixmap(*pixmap);
        }

    }









}
