#include "setmodedialog.h"
#include "ui_setmodedialog.h"
#include <QTime>
#include <QString>
#include <mainwindow.h>
using namespace std;


setModeDialog::setModeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setModeDialog)
{
    ui->setupUi(this);
    this->setCom();
}

setModeDialog::~setModeDialog()
{
    delete ui;
}

void setModeDialog::setCom()
{
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString str = time.toString("yyyy-MM-dd"); //设置显示格式

    for(int i = 1;i <= 50;i ++)
    {


        QString BeforeDaystr=time.addDays(-i).toString("yyyy-MM-dd");


        ui->comboBox->addItem(BeforeDaystr);

    }

    for(int i = 0;i <= 23;i ++)
    {
         if(i <= 9)
            ui->comboBox_2->addItem("0" + QString::number(i, 10) + ":00");
         else
            ui->comboBox_2->addItem(QString::number(i, 10) + ":00");

    }
}

void setModeDialog::on_pushButton_clicked()
{

    MainWindow::setMode(ui->comboBox->currentText(),ui->comboBox_2->currentText());
    this->close();
}
