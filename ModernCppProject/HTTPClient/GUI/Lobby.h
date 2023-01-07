#pragma once

#include <QMainWindow>
#include "ui_Lobby.h"
#include <cpr/cpr.h>
#include <crow.h>
#include "Game.h"

class Lobby : public QMainWindow
{
	Q_OBJECT

public:
	Lobby(QWidget *parent, std::string username);
	~Lobby();

public slots:
	void showTime();

private:
	Ui::LobbyClass ui;
	QWidget* parentWindow;
	QTimer* timer;
	std::string m_username;
	int timerSeconds;
	int playersInLobby;
	Game* game;
};
