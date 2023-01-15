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
	Lobby(QWidget *parent, CurrentUser* currentUser);
	~Lobby();

private slots:
	void on_cancelPushButton_clicked();

public slots:
	void showTime();

private:
	Ui::LobbyClass ui;
	QWidget* parentWindow;
	Game* gameWindow;
	CurrentUser* loggedUser;

	QTimer* timer;
	uint16_t timerSeconds;
	uint16_t playersInLobby;
};
