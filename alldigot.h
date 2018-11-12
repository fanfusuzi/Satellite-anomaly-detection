#ifndef ALLDIGOT_H
#define ALLDIGOT_H

#include <QWidget>

namespace Ui {
class allDigot;
}

class allDigot : public QWidget
{
    Q_OBJECT

public:
    explicit allDigot(QWidget *parent = 0);
    ~allDigot();

private:
    Ui::allDigot *ui;
};

#endif // ALLDIGOT_H
