#include "adding_transaction_page.h"
#include "ui_adding_transaction_page.h"
#include <QMessageBox>

Adding_transaction_page::Adding_transaction_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adding_transaction_page)
{
    ui->setupUi(this);

}

Adding_transaction_page::~Adding_transaction_page()
{
    delete ui;
}

void Adding_transaction_page::on_pushButton_clicked()
{


}

void Adding_transaction_page::on_pushButton_2_clicked()
{
    int confirm = QMessageBox::critical(this,"conformation","Are you sure?","yes","no");
    qDebug()<<confirm;
    if(confirm==0){
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_7->clear();

        this->close();
    }
}

