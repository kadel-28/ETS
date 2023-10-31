#pragma once
#include "mainwindow.h"
#include "ui_mainwindow.h"
QSqlDatabase  MainWindow::login_db;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    static int clicked_checker{};
    if(clicked_checker==0){}
    int checker = Database_connect();
    if(checker==1){
        qDebug()<<"Already open";
    }
    if(!login_db.open()){
        Database_connect();
    }



    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QSqlQuery check;





    if (check.exec("select * from _login_ where username='"+username+"'and password='"+password+"'")){
        int count=0;
        while(check.next()){
            count++;;

        }
        if(count==1){
            int close_checker=Database_disconect();
            if(close_checker==1){
                Database_disconect();
            }

            secondary = new second_win(this);
            //secondary->show();
            MainWindow::username=username;
            this->hide();



            secondary->hasFocus();
            secondary->setModal(true);

            secondary->activateWindow();
            secondary->exec();

            if(!secondary->isActiveWindow()){
                this->show(),close();

            }

        }
        else{
            int close_checker=Database_disconect();
            if(close_checker==1){
                Database_disconect();
            }
            this->clearFocus();
            this->hide();

            third =new third_win(this);
            third;
            third->exec();
            if(!third->isActiveWindow()){
                this->show(),close();

            }

        }

    }

    clicked_checker++;

}

int MainWindow::Database_connect(){
    if(login_db.open()){
        return 1;
    }

    login_db = QSqlDatabase::addDatabase("QSQLITE");
    login_db.transaction();
    login_db.setDatabaseName("C:/Users/aakas/OneDrive/Desktop/programming/C++,C/Uni_project/ETS/sqlite/new.SQlite");
    return 0;

}



int MainWindow::Database_disconect(){


    login_db.close();
    login_db.removeDatabase(QSqlDatabase::defaultConnection);

    if(login_db.open()){
        return 1;
    }
    return 0;

}
