#ifndef ALLDIA_H
#define ALLDIA_H

#include <QWidget>
#include "lightpoint.h"
#include "test1dialog.h"
#include "test2dialog.h"
#include "test3dialog.h"
#include "test4dialog.h"
#include "test5dialog.h"
#include "test6dialog.h"
#include "handbookdialog.h"
namespace Ui {
class allDia;
}

class allDia : public QWidget
{
    Q_OBJECT

public:
    explicit allDia(QWidget *parent = 0);
    ~allDia();
    test1Dialog *dia1;
    test2Dialog *dia2;
    test3Dialog *dia3;
    test4Dialog *dia4;
    test5Dialog *dia5;
    test6Dialog *dia6;




private slots:
    void on_pushButton_clicked();



    void on_pushButton_pressed();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::allDia *ui;
    QList<LightPoint *> widgets;

};

#endif // ALLDIA_H
