#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include "logindia.h"
#include <QSplashScreen>
#include <QPixmap>
#include <QSize>
#include <iostream>
#include <unistd.h>
#include <QDesktopWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
#include "mainwindow.h"
#include <QChar>
#include <QSet>
#include <history.h>
#include "alldia.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

using namespace std;





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    a.setWindowIcon(QPixmap(":/images/timg.jpeg"));

    LoginDia dig;


    if(dig.exec() == LoginDia::Accepted)
    {
        //w.setWindowState(Qt::WindowMaximized);
        QSplashScreen *splash = new QSplashScreen;
        Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
        splash->show();
        splash->setPixmap(QPixmap(":/images/images/timg.jpeg").scaled(600,400,Qt::KeepAspectRatio));

        splash->showMessage(QObject::tr("Setting up the main window..."),topRight, Qt::white);//显示信息
        //MainWindow w;



        MainWindow w;

        w.getConnect();
        sleep(5);
        splash->close();
        w.show();
        w.move((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);
        return a.exec();
    }



    return a.exec();
}

