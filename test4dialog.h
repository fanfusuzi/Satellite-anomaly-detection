#ifndef TEST4DIALOG_H
#define TEST4DIALOG_H

#include <QDialog>

namespace Ui {
class test4Dialog;
}

class test4Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit test4Dialog(QWidget *parent = 0);
    ~test4Dialog();

    void getdata();

private:
    Ui::test4Dialog *ui;
};

#endif // TEST4DIALOG_H
