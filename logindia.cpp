#include "logindia.h"
#include "ui_logindia.h"
#include <QMessageBox>
LoginDia::LoginDia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDia)
{
    ui->setupUi(this);
     this->setFixedSize( this->width (),this->height ());

}

LoginDia::~LoginDia()
{
    delete ui;

}

void LoginDia::on_pushButton_clicked()
{

}

void LoginDia::on_loginButton_clicked()
{
    // 判断用户名和密码是否正确，
    // 如果错误则弹出警告对话框
    if(ui->usrLineEdit->text().trimmed() == tr("admin") &&
           ui->pwdLineEdit->text() == tr("admin"))
    {
       accept();
    } else {
       QMessageBox::warning(this, tr("警告！"),
                   tr("用户名或密码错误！"),
                   QMessageBox::Yes);
       ui->usrLineEdit->clear();
       ui->pwdLineEdit->clear();
       ui->usrLineEdit->setFocus();
    }

}

void LoginDia::on_exitButton_clicked()
{
    this->close();
}
