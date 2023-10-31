#include "graph_page.h"
#include "ui_graph_page.h"

Graph_page::Graph_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph_page)
{
    ui->setupUi(this);
}

Graph_page::~Graph_page()
{
    delete ui;
}
