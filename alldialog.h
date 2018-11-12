#ifndef ALLDIALOG_H
#define ALLDIALOG_H
#include "lightpoint.h"
#include <QWidget>

namespace Ui {
class allDialog;
}

class allDialog : public QWidget
{
    Q_OBJECT

public:
    explicit allDialog(QWidget *parent = 0);
    ~allDialog();

private:
    Ui::allDialog *ui;
    QList<LightPoint *> widgets;
};

#endif // ALLDIALOG_H
