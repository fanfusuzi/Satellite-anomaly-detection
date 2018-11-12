#ifndef TEST3DIALOG_H
#define TEST3DIALOG_H

#include <QDialog>

namespace Ui {
class test3Dialog;
}

class test3Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit test3Dialog(QWidget *parent = 0);
    ~test3Dialog();
    void getdata();

private:
    Ui::test3Dialog *ui;
};

#endif // TEST3DIALOG_H
