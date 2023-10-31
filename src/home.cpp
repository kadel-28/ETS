#pragma once

#include "second_win.h"
#include "mainwindow.h"
#include "ui_second_win.h"
QString MainWindow::username;

second_win::second_win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::second_win)
{
    ui->setupUi(this);
    if(this->isActiveWindow()){
        table();
    }


}

second_win::~second_win()
{
    delete ui;
}

void second_win::on_pushButton_4_clicked()
{
    QMessageBox::information(this,"hello","this is a graph");

}



void second_win::table()
{   QString username = MainWindow::username;
    MainWindow::Database_connect();
    MainWindow::Database_connect();
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(MainWindow::login_db);

    qry->prepare("SELECT * FROM _" + username + "_transaction");
    qry->exec();


    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    qDebug()<<modal->lastError().text();

        if(!qry->exec()){
    qDebug()<<"Error";
    qDebug()<<qry->lastError().text();



    }
 MainWindow::Database_disconect();
    delete modal;
    delete qry;
    modal=nullptr;
    qry=nullptr;

}


void second_win::on_pushButton_clicked()
{      Adding_transaction_page a;
    home_page = new Adding_transaction_page(this);
    home_page->hasFocus();
    home_page->show();

}


void second_win::on_pushButton_3_clicked()
{
    ledger = new ledger_page(this);

    ledger->show();
    ledger->hasFocus();

}


void second_win::on_tableView_clicked(const QModelIndex &index)
{
    ledger = new ledger_page(this);
    ledger->show();
    ledger->hasFocus();

}

