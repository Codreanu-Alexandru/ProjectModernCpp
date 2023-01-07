#pragma once

#include <QMainWindow>
#include "ui_LoggedInMenu.h"
#include "PreLobbyMenu.h"
#include "ProfileViewTab.h"
#include "Lobby.h"

class LoggedInMenu : public QMainWindow
{
	Q_OBJECT

public:
	LoggedInMenu(QWidget *parent, CurrentUser* currentUser);
	~LoggedInMenu();

private slots:
	void on_playPushButton_clicked();
	void on_viewMyProfilePushButton_clicked();
	void on_optionsPushButton_clicked();
	void on_logOutPushButton_clicked();

private:
	Ui::LoggedInMenuClass ui;
	QWidget* parentWindow;
	CurrentUser* loggedUser;
	PreLobbyMenu* preLobbyMenu;
	Lobby* lobby;
	ProfileViewTab* profileViewTab;
};
