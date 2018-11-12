#ifndef LOGINDIA_H
#define LOGINDIA_H

#include <QDialog>

namespace Ui {
class LoginDia;
}

class LoginDia : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDia(QWidget *parent = 0);
    ~LoginDia();

private slots:
    void on_pushButton_clicked();

    void on_loginButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::LoginDia *ui;
};

#endif // LOGINDIA_H
