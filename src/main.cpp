#include "aes.h"

#pragma once
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow Main_win ;
    Main_win.setWindowTitle("ETS");
    Main_win.show();
    Main_win.resize(800,450);
    MainWindow::Database_connect();




    return a.exec();
}
