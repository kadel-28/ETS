#pragma once
#ifndef SECOND_WIN_H
#define SECOND_WIN_H

#include <QDialog>
#include<QMessageBox>
#include "adding_transaction_page.h"
#include "ledger_page.h"

namespace Ui {
class second_win;
}

class second_win : public QDialog
{
    Q_OBJECT

public:
    explicit second_win(QWidget *parent = nullptr);
    ~second_win();

private slots:
    void on_pushButton_4_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void table();

private:
    Ui::second_win *ui;
    Adding_transaction_page *home_page;
    ledger_page *ledger;

};

#endif // SECOND_WIN_H
