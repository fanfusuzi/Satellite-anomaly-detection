#include "test4dialog.h"
#include "ui_test4dialog.h"
#include <QSqlQuery>
#include <QTimer>
test4Dialog::test4Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test4Dialog)
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

test4Dialog::~test4Dialog()
{
    delete ui;
}

void test4Dialog::getdata()
{
    QSqlQuery sql_query;
    QString sql1 = "select * from test41 order by id desc limit 0,1;";

    sql_query.exec(sql1);



    float value;
    int estimate;
    while(sql_query.next())
    {


        value = sql_query.value(3).toFloat();
        estimate = sql_query.value(4).toInt();
        QString s = QString("%1").arg(value);
        ui->lineEdit_test41->setText(s);
        if(estimate == 1)
        {
            QPixmap *pixmap = new QPixmap(":/images/images/green.jpg");
            pixmap->scaled(ui->label_test41->size(), Qt::KeepAspectRatio);
            ui->label_test41->setScaledContents(true);
            ui->label_test41->setPixmap(*pixmap);
        }
        else
        {
            QPixmap *pixmap = new QPixmap(":/images/images/red.jpg");
            pixmap->scaled(ui->label_test41->size(), Qt::KeepAspectRatio);
            ui->label_test41->setScaledContents(true);
            ui->label_test41->setPixmap(*pixmap);
        }

    }







}
