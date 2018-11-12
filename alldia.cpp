#include "alldia.h"
#include "ui_alldia.h"
#include "lightpoint.h"
#include "test1dialog.h"
#include <iostream>
#include "handbookdialog.h"
#include <QMessageBox>
allDia::allDia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::allDia)
{
    ui->setupUi(this);

    // 设置背景图片
    ui->widget->setStyleSheet("QWidget#widget {background: url(:/images/images/all.png); }");

    // 使用Grid布局
    QGridLayout * pLayout = new QGridLayout();
    // 生成 2行 3列 共 6 个控件
    LightPoint *pLightPoint;
    for(int index = 0; index < 6; index++)
    {
        pLightPoint = new LightPoint(this);
        pLayout->addWidget(pLightPoint, index/2, index%2, 1, 1);
        // 控件指针加入列表，以便设置颜色，等同于 widgets.push_back(pLightPoint);
        widgets << pLightPoint;
    }

    // 设置布局到主窗口上的QWidget
    ui->widget->setLayout(pLayout);
    // 颜色列表
    QList<QColor> colors;
    //
    colors << "#00B17D" << "#00B17D" << "#009679" << "#009679" << "#009679" << "#009679";
    // 循环设置颜色
    for (int index = 0; index < widgets.count(); index++) {
        widgets.at(index)->setBgColor(colors.at(index));
    }
    std::cout<< "tttt111" << std::endl;

    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::ApplicationModal);
    this->setFixedSize( this->width (),this->height ());


}

allDia::~allDia()
{
    delete ui;
}



void allDia::on_pushButton_clicked()
{
    dia1 = new test1Dialog();
    dia1->show();
    std::cout << "ttt" <<std::endl;
}



void allDia::on_pushButton_pressed()
{
    dia1 = new test1Dialog();
    dia1->show();
    std::cout << "ttt" <<std::endl;
}

void allDia::on_pushButton_2_clicked()
{
    dia2 = new test2Dialog();
    dia2->show();
    std::cout << "ttt" <<std::endl;
}

void allDia::on_pushButton_3_clicked()
{
    dia3 = new test3Dialog();
    dia3->show();
    std::cout << "ttt" <<std::endl;
}

void allDia::on_pushButton_4_clicked()
{
    dia4 = new test4Dialog();
    dia4->show();
    std::cout << "ttt" <<std::endl;
}

void allDia::on_pushButton_5_clicked()
{
    dia5 = new test5Dialog();
    dia5->show();
    std::cout << "ttt" <<std::endl;
}

void allDia::on_pushButton_6_clicked()
{
    dia6 = new test6Dialog();
    dia6->show();
    std::cout << "ttt" <<std::endl;
}

void allDia::on_pushButton_7_clicked()
{
    QMessageBox::information(this, "对话框", "当前无报警部件", QMessageBox::Yes );
}
