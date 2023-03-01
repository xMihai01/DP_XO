#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "IGame.h"
#include <vector>
#include <QPushButton>

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QString username, QWidget *parent = nullptr);
    ~GameWindow();

private slots:

    void slotClicked();

private:
    Ui::GameWindow *ui;

    std::vector<QPushButton*> boardSlots;
    IGamePtr game;
};

#endif // GAMEWINDOW_H
