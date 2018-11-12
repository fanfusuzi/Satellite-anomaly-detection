#include "lightpoint.h"
#include "qpainter.h"
#include "qevent.h"
#include "qtimer.h"

LightPoint::LightPoint(QWidget *parent) : QWidget(parent)
{
    step = 10;
    interval = 100;    
    bgColor = QColor(255, 0, 0);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(100);

    offset = 0;
    add = true;
}

LightPoint::~LightPoint()
{
    if (timer->isActive()) {
        timer->stop();
    }
}

void LightPoint::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    // 绘制准备工作 启用反锯齿
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    // 平移坐标轴中心,
    painter.translate(rect().width() / 2, rect().height() / 2);
    //绘制背景
    drawBg(&painter);
}

void LightPoint::drawBg(QPainter *painter)
{
    // 半径为当前 宽 或者 高 的一半
    int radius = qMin(rect().width(), rect().height())/2;
    // 保存当前painter
    painter->save();
    // 以点为中心的渐变色
    QRadialGradient g(QPoint(0, 0), radius);
    // 循环加减
    (offset < 100 && add) ? (offset += step) : (add = false);
    (offset > 0 && !add) ? (offset -= step) : (add = true);
    // 按照 点范围[0.0,1.0] 对于 每点的颜色
    bgColor.setAlpha( 200+offset > 255 ? 255 : 200+offset );
    g.setColorAt(0.0, bgColor);
    bgColor.setAlpha( 140+offset);
    g.setColorAt(0.2, bgColor);
    bgColor.setAlpha( 80+offset);
    g.setColorAt(0.4, bgColor);
    bgColor.setAlpha( 20+offset >= 0 ? 20+offset : 0 );
    g.setColorAt(0.6, bgColor);
    bgColor.setAlpha( -60+offset >= 0 ? -50+offset : 0 );
    g.setColorAt(0.8, bgColor);
    bgColor.setAlpha( 0 );
    g.setColorAt(1.0, bgColor);
    // 设置 画笔 图形的边界线
    painter->setPen(Qt::NoPen);
    // 设置 画刷 画刷为 点向外辐射的渐变色
    painter->setBrush(g);
    // 画椭圆，长=宽 为原型
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    // 回复保存的
    painter->restore();
}

int LightPoint::getStep() const
{
    return this->step;
}

int LightPoint::getInterval() const
{
    return this->interval;
}

QColor LightPoint::getBgColor() const
{
    return this->bgColor;
}

QSize LightPoint::sizeHint() const
{
    return QSize(100, 100);
}

QSize LightPoint::minimumSizeHint() const
{
    return QSize(5, 5);
}

void LightPoint::setStep(int step)
{
    if (this->step != step) {
        this->step = step;
        update();
    }
}

void LightPoint::setInterval(int interval)
{
    if (this->interval != interval) {
        this->interval = interval;
        timer->setInterval(interval);
        update();
    }
}

void LightPoint::setBgColor(const QColor &bgColor)
{
    if (this->bgColor != bgColor) {
        this->bgColor = bgColor;
        update();
    }
}
