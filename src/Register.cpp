#pragma once
//Register page
#include "aes.h"
#include "Register.h"
#include "ui_third_win.h"
#include "main.cpp"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QApplication>
#include <second_win.h>
#include <QCoreApplication>
#include <QDebug>
#include <QCryptographicHash>
#include <QByteArray>
#include <QtAlgorithms>
#include <QCryptographicHash>
#include <QDateTime>






third_win::third_win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::third_win)
{
    MainWindow::Database_connect();
    ui->setupUi(this);


}

third_win::~third_win()
{
    delete ui;
}

void third_win::on_pushButton_clicked()

{



        QString username,password,unique_username{""};
    QSqlQuery reg_user;



        try {


    if(unique_username=="UNIQUE constraint failed: _login_.username Unable to fetch row"){
        ui->rules_box->setPlaceholderText("Same username pick another");


    }

    username = third_win::ui->lineEdit_username->text();
    password = third_win::ui->lineEdit_password->text();
    qDebug()<<username;
    qDebug()<<password;
    qDebug()<<username.isEmpty();

    if(username.isEmpty()|| password.isEmpty()){

        qDebug()<<"Empty username cannot be empty ";
        return;
    }

    MainWindow::Database_connect();
    if(!MainWindow::login_db.open()){
        qDebug()<<"Database not open";
    }

    if(!reg_user.exec("CREATE TABLE IF NOT EXISTS _" + username + "_transaction (id INTEGER PRIMARY KEY, expense INTEGER, date TEXT)")) {
        qDebug()<<"Table creation failed";
        qDebug()<<"Error: "<<reg_user.lastError().text();
    }

    QSqlQuery query;
    query.prepare("INSERT INTO _login_ (username, password) "
                  "VALUES (?, ?)");
    query.addBindValue(username);
    query.addBindValue(password);

    if (!query.exec()) {
        qDebug() << "Error: Failed to insert data into database.";
        unique_username = query.lastError().text();
    }



   if (reg_user.exec("select * from _login_ where username='"+username+"'and password='"+password+"'")){
        int count=0;
        while(reg_user.next()){
            count++;;

        }

        if(count==1){
            int close_checker=MainWindow::Database_disconect();
            if(close_checker==1){
                MainWindow::Database_disconect();
            }

            secondary = new second_win(this);
            secondary->show();
            qDebug()<<"user created";
            MainWindow::username=username;
            return;
        }

    }
        }catch(std::exception &e){
    qDebug()<<"Error: "<<e.what();

        }

}



unsigned char encryption_key[] = "YourEncryptionKey";
unsigned char iv[] = "YourIVValue";

// Function to encrypt data using AES-CBC
std::string encryptAES(const std::string &input) {
        AES_KEY aesKey;
        AES_set_encrypt_key(encryption_key, 256, &aesKey);

        size_t inputLength = input.length();
        size_t encryptedLength = ((inputLength + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
        unsigned char encryptedData[encryptedLength];

        AES_cbc_encrypt((const unsigned char *)input.c_str(), encryptedData, inputLength, &aesKey, iv, AES_ENCRYPT);

        return std::string((char *)encryptedData, encryptedLength);
}

// Function to decrypt data using AES-CBC
std::string decryptAES(const std::string &input) {
        AES_KEY aesKey;
        AES_set_decrypt_key(encryption_key, 256, &aesKey);

        size_t inputLength = input.length();
        unsigned char decryptedData[inputLength];

        AES_cbc_encrypt((const unsigned char *)input.c_str(), decryptedData, inputLength, &aesKey, iv, AES_DECRYPT);

        return std::string((char *)decryptedData);
}
