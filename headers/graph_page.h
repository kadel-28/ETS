#pragma once

#ifndef GRAPH_PAGE_H
#define GRAPH_PAGE_H

#include <QDialog>

namespace Ui {
class Graph_page;
}

class Graph_page : public QDialog
{
    Q_OBJECT

public:
    explicit Graph_page(QWidget *parent = nullptr);
    ~Graph_page();

private:
    Ui::Graph_page *ui;
};

#endif // GRAPH_PAGE_H
