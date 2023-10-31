#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "second_win.h"
#include "Register.h"
#include "adding_transaction_page.h"
#include "graph_page.h"
#include <QMessageBox>
#include<QtSql>
#include<QSqlDatabase>
#include<QtDebug>
#include<QFileInfo>
#include<QSqlQuery>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void er_printer();
    static int Database_connect();
    static int Database_disconect();
    ~MainWindow();
    QSqlDatabase static  login_db;


    QString static username;
private slots:

    void on_pushButton_clicked();

protected:

    Ui::MainWindow *ui;
    second_win *secondary;
    third_win *third;


};

#endif // MAINWINDOW_H
