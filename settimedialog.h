#ifndef SETTIMEDIALOG_H
#define SETTIMEDIALOG_H

#include <QDialog>

namespace Ui {
class setTimeDialog;
}

class setTimeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit setTimeDialog(QWidget *parent = 0);
    ~setTimeDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::setTimeDialog *ui;
};

#endif // SETTIMEDIALOG_H
