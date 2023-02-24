#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "Game.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QString username, QWidget *parent = nullptr);
    ~GameWindow();

private:
    Ui::GameWindow *ui;
    Game game;
};

#endif // GAMEWINDOW_H
