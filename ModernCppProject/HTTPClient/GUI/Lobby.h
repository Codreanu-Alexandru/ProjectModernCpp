#pragma once

#include <QMainWindow>
#include "ui_Lobby.h"
#include <cpr/cpr.h>
#include <crow.h>
#include "Game.h"
#include <qmessagebox.h>
#include "CurrentUser.h"

class Lobby : public QMainWindow
{
	Q_OBJECT

public:
	Lobby(QWidget *parent, std::string username, int id);
	~Lobby();

public slots:
	void showTime();
	void on_cancelPushButton_clicked();

private:
	Ui::LobbyClass ui;
	QWidget* parentWindow;
	QTimer* timer;
	std::string m_username;
	int timerSeconds;
	int playersInLobby;
	Game* game;
	int userId;
};
