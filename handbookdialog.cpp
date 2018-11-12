#include "handbookdialog.h"
#include "ui_handbookdialog.h"

handbookDialog::handbookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::handbookDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::ApplicationModal);
    this->setFixedSize( this->width (),this->height ());

}

handbookDialog::~handbookDialog()
{
    delete ui;
}
