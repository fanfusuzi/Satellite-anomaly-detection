#include "alldigot.h"
#include "ui_alldigot.h"

allDigot::allDigot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::allDigot)
{
    ui->setupUi(this);
}

allDigot::~allDigot()
{
    delete ui;
}
