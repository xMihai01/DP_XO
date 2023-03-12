#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "IGame.h"
#include <vector>
#include <QPushButton>
#include "QtListener.h"

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

    QMap<QPushButton*, uint8_t> boardSlots;
    IGamePtr game;
    IGameListenerPtr qtListener;
};

#endif // GAMEWINDOW_H
