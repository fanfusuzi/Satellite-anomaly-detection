#ifndef TEST6DIALOG_H
#define TEST6DIALOG_H

#include <QDialog>

namespace Ui {
class test6Dialog;
}

class test6Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit test6Dialog(QWidget *parent = 0);
    ~test6Dialog();
    void getdata();

private:
    Ui::test6Dialog *ui;
};

#endif // TEST6DIALOG_H
