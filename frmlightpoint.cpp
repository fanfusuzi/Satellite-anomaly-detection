#include "frmlightpoint.h"
#include "ui_frmlightpoint.h"
#include "lightpoint.h"

frmLightPoint::frmLightPoint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmLightPoint)
{
    ui->setupUi(this);

    // 设置背景图片
    ui->widget->setStyleSheet("QWidget#widget {background: url( :/images/images/all.png); }");

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
    colors << "#009679" << "#009679" << "#009679" << "#009679" << "#009679" << "#009679";
    // 循环设置颜色
    for (int index = 0; index < widgets.count(); index++) {
        widgets.at(index)->setBgColor(colors.at(index));
    }

}

frmLightPoint::~frmLightPoint()
{
    delete ui;
}
