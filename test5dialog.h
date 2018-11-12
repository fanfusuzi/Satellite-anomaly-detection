#ifndef TEST5DIALOG_H
#define TEST5DIALOG_H

#include <QDialog>

namespace Ui {
class test5Dialog;
}

class test5Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit test5Dialog(QWidget *parent = 0);
    ~test5Dialog();
    void getdata();

private:
    Ui::test5Dialog *ui;
};

#endif // TEST5DIALOG_H
