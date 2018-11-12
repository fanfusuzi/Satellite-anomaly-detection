#ifndef SETBOUNDDIALOG_H
#define SETBOUNDDIALOG_H

#include <QDialog>

namespace Ui {
class setBoundDialog;
}

class setBoundDialog : public QDialog
{
    Q_OBJECT

public:
    explicit setBoundDialog(QWidget *parent = 0);
    ~setBoundDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::setBoundDialog *ui;
};

#endif // SETBOUNDDIALOG_H
