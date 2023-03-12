#pragma once

#include "IGameListener.h"
#include "IGame.h"
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>

class QtListener : public IGameListener
{

public:

	QtListener(IGamePtr game, QMap <QPushButton*, uint8_t>& boardSlots, QLabel* gameStateLabel);

	void Update();
	void ShowGameState();

private:
	IGamePtr m_game;
	QMap<QPushButton*, uint8_t> m_boardSlots;
	QLabel* m_gameStateLabel;

};

