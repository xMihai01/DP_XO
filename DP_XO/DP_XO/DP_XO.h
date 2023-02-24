#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DP_XO.h"

class DP_XO : public QMainWindow
{
    Q_OBJECT

public:
    DP_XO(QWidget *parent = nullptr);
    ~DP_XO();

private slots:

    void joinButtonClicked();

private:
    Ui::DP_XOClass *ui;
};
