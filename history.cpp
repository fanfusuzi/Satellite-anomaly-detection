#include "history.h"
#include "ui_history.h"
#include <QSqlQuery>
#include <QDateTime>
#include <QString>
history::history(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);
    init();
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::ApplicationModal);
    this->setFixedSize( this->width (),this->height ());
}

history::~history()
{
    delete ui;
}

void history::init()
{
    QString get_sql = "select * from   history";
    QSqlQuery sql_query;
    QDateTime time;
    QString name;
    int estimate;


    sql_query.exec(get_sql);
    while(sql_query.next())
    {

        time = sql_query.value(1).toDateTime();
        name = sql_query.value(2).toString();


        estimate = sql_query.value(3).toInt();


        int rowIndex = ui->tableWidget->rowCount();

        ui->tableWidget->setRowCount(rowIndex + 1);//总行数增加1

        ui->tableWidget->setRowHeight(rowIndex  , 24);


        QString content1 = time.toString("yyyy-MM-dd HH:mm:ss");



        QString content2 = "出水口水流温度";

        QString content3 = "正常范围";
        QTableWidgetItem *item1 = new QTableWidgetItem (content1);
        QTableWidgetItem *item2 = new QTableWidgetItem (content2);
        QTableWidgetItem *item3 = new QTableWidgetItem (content3);




        //ui->tableWidget->setItem(rowIndex, 0, item1);
        ui->tableWidget->setItem(rowIndex,0,item1);
        ui->tableWidget->setItem(rowIndex,1,item2);
        ui->tableWidget->setItem(rowIndex,2,item3);

        ui->tableWidget->setFocus();


    }
}
