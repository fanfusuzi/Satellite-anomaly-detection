#include "settimedialog.h"
#include "ui_settimedialog.h"
#include "mainwindow.h"
#include <QMessageBox>
setTimeDialog::setTimeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setTimeDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::ApplicationModal);
     this->setFixedSize( this->width (),this->height ());

}

setTimeDialog::~setTimeDialog()
{
    delete ui;
}

void setTimeDialog::on_pushButton_clicked()
{
    int span = 3 * 1000;
    if(ui->comboBox->currentText() == "1s")
    {
        span = 1 * 1000;
    }
    else if (ui->comboBox->currentText() == "5s")
    {
        span = 5 * 1000;
    }
    else if (ui->comboBox->currentText() == "10s")
    {
        span = 10 * 1000;
    }
    else if(ui->comboBox->currentText() == "1min")
    {
        span = 60 * 1000;
    }
    else if (ui->comboBox->currentText() == "5min")
    {
        span = 5 * 60 * 1000;
    }
    MainWindow::setTime(span);
    QMessageBox::information(this, QString().fromLocal8Bit("提示"),"更新成功",QMessageBox::Yes);
}

void setTimeDialog::on_pushButton_2_clicked()
{
    this->close();
}
