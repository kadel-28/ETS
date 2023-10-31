#pragma once

#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include "second_win.h"

namespace Ui {
class third_win;
}

class third_win : public QDialog{
    Q_OBJECT

public:
    explicit third_win(QWidget *parent = nullptr);
    ~third_win();

private slots:
    void on_pushButton_clicked();

private:
    Ui::third_win *ui;
    second_win *secondary;
};

#endif // REGISTER_H
