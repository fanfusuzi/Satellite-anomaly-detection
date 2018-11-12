#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QTimer>
#include <QChartView>
#include <QChart>
#include <QLineSeries>
#include "logindia.h"
#include "history.h"
#include "setbounddialog.h"
#include "getdatadialog.h"
#include "settimedialog.h"
#include "handbookdialog.h"
#include "test1dialog.h"
#include "test2dialog.h"
#include "test3dialog.h"
#include "test4dialog.h"
#include "test5dialog.h"
#include "test6dialog.h"
#include "setmodedialog.h"
#include "alldia.h"
#include <string>
#include <vector>
#include <connection.h>
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static QSqlDatabase getConnect();

    QTimer *timer1;

    QChartView *chartView;
    QChart *chart;
    QLineSeries *series;
    void initChart();
    history *h;
    test1Dialog *diaa;
    test2Dialog *diab;
    test3Dialog *diac;
    test4Dialog *diad;
    test5Dialog *diae;
    test6Dialog *diaf;
    struct RealDate{
        QString time;
        int state ;
        float value;
        QString tag;
    };

    allDia *diaall;

    static void getData(QString &name,QDateTime &time,int &estimate,float &value);
    quint16 count;

    void updateData();
    void setChartRange();
    void insertOneData(QString s);
    void getOneDate(QString s,float &low,float &high,float &avg);
    void insertDataCom();
    RealDate readdata(QString table);

    void static  setTime(int span);
    void static setMode(QString s1,QString s2);

    bool test;
    LoginDia *dia;
    setBoundDialog *dia1;
    getDataDialog *dia2;
    setTimeDialog *dia3;
    handbookDialog * dia4;
    setModeDialog *diaMode;

    QString getTag(QString table);



    IHistorianData *ihis;







    int timeSpan;




public slots:
    void insertData();

    void toTable();
    void timerSlot();
    void setAlarm(int estimate);


private slots:
    void on_treeWidget_doubleClicked(const QModelIndex &index);


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



    void on_pushButton_3_clicked();

    void on_action_triggered();

    void on_action_6_triggered();

    void on_action_2_triggered();

    void on_action_5_triggered();

    void on_action_7_triggered();

    void on_action_8_triggered();




private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
