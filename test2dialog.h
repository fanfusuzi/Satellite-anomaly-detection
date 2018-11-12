#ifndef TEST2DIALOG_H
#define TEST2DIALOG_H

#include <QDialog>

namespace Ui {
class test2Dialog;
}

class test2Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit test2Dialog(QWidget *parent = 0);
    ~test2Dialog();
    void getdata();

private:
    Ui::test2Dialog *ui;
};

#endif // TEST2DIALOG_H
