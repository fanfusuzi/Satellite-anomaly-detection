#ifndef SETMODEDIALOG_H
#define SETMODEDIALOG_H

#include <QDialog>

namespace Ui {
class setModeDialog;
}

class setModeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit setModeDialog(QWidget *parent = 0);
    ~setModeDialog();

    void setCom();


private slots:
    void on_pushButton_clicked();

private:
    Ui::setModeDialog *ui;
};

#endif // SETMODEDIALOG_H
