#pragma once

#ifndef ADDING_TRANSACTION_PAGE_H
#define ADDING_TRANSACTION_PAGE_H

#include <QDialog>

namespace Ui
{
    class Adding_transaction_page;
}

class Adding_transaction_page : public QDialog
{
    Q_OBJECT

public:
    explicit Adding_transaction_page(QWidget *parent = nullptr);
    ~Adding_transaction_page();

private slots:
    void on_pushButton_clicked();

    void on_dateTimeEdit_dateChanged(const QDate &date);

    void on_pushButton_2_clicked();

private:
    Ui::Adding_transaction_page *ui;
};

#endif // ADDING_TRANSACTION_PAGE_H
