#pragma once

#include <QMainWindow>
#include "ui_PreLobbyMenu.h"

class PreLobbyMenu : public QMainWindow
{
	Q_OBJECT

public:
	PreLobbyMenu(QWidget *parent = nullptr);
	~PreLobbyMenu();

private slots:
	void on_backLobbyPushButton_clicked();
	void on_twoPlayersPushButton_clicked();
	void on_threePlayersPushButton_clicked();
	void on_fourPlayersPushButton_clicked();

private:
	Ui::PreLobbyMenuClass ui;
	QWidget* parentWindow;
};
