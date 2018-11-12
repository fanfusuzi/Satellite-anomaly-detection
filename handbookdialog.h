#ifndef HANDBOOKDIALOG_H
#define HANDBOOKDIALOG_H

#include <QDialog>

namespace Ui {
class handbookDialog;
}

class handbookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit handbookDialog(QWidget *parent = 0);
    ~handbookDialog();

private:
    Ui::handbookDialog *ui;
};

#endif // HANDBOOKDIALOG_H
