#include "ledger_page.h"
#include "ui_ledger_page.h"

ledger_page::ledger_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ledger_page)
{
    ui->setupUi(this);
}

ledger_page::~ledger_page()
{
    delete ui;
}
