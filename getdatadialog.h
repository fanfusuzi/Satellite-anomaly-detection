#ifndef GETDATADIALOG_H
#define GETDATADIALOG_H

#include <QDialog>

namespace Ui {
class getDataDialog;
}

class getDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit getDataDialog(QWidget *parent = 0);
    ~getDataDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::getDataDialog *ui;
};

#endif // GETDATADIALOG_H
