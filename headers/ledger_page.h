
#pragma once

#ifndef LEDGER_PAGE_H
#define LEDGER_PAGE_H

#include <QDialog>

namespace Ui {
class ledger_page;
}

class ledger_page : public QDialog
{
    Q_OBJECT

public:
    explicit ledger_page(QWidget *parent = nullptr);
    ~ledger_page();

private:
    Ui::ledger_page *ui;
};

#endif // LEDGER_PAGE_H
