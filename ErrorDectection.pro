#-------------------------------------------------
#
# Project created by QtCreator 2018-07-17T15:06:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ErrorDectection
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    logindia.cpp \
    history.cpp \
    setbounddialog.cpp \
    handbookdialog.cpp \
    getdatadialog.cpp \
    settimedialog.cpp \
    lightpoint.cpp \
    alldia.cpp \
    test1dialog.cpp \
    test2dialog.cpp \
    test3dialog.cpp \
    test4dialog.cpp \
    test5dialog.cpp \
    test6dialog.cpp \
    svm.cpp \
    setmodedialog.cpp \
    connection.cpp

HEADERS += \
        mainwindow.h \
    logindia.h \
    history.h \
    setbounddialog.h \
    handbookdialog.h \
    getdatadialog.h \
    settimedialog.h \
    lightpoint.h \
    alldia.h \
    test1dialog.h \
    test2dialog.h \
    test3dialog.h \
    test4dialog.h \
    test5dialog.h \
    test6dialog.h \
    svm.h \
    setmodedialog.h \
    connection.h

FORMS += \
    logindia.ui \
    mainwindow.ui \
    history.ui \
    setbounddialog.ui \
    handbookdialog.ui \
    getdatadialog.ui \
    settimedialog.ui \
    alldia.ui \
    test1dialog.ui \
    test2dialog.ui \
    test3dialog.ui \
    test4dialog.ui \
    test5dialog.ui \
    test6dialog.ui \
    setmodedialog.ui
RESOURCES += \
    errordetection.qrc


QT += sql

QT += charts


