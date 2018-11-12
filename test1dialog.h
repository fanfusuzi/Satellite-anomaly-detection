#ifndef TEST1DIALOG_H
#define TEST1DIALOG_H

#include <QDialog>

namespace Ui {
class test1Dialog;
}

class test1Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit test1Dialog(QWidget *parent = 0);
    ~test1Dialog();
    QTimer *timer;
public slots:
    void getdata();

private:
    Ui::test1Dialog *ui;

};

#endif // TEST1DIALOG_H
