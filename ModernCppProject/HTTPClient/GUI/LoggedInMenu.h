#pragma once

#include <QMainWindow>
#include "ui_LoggedInMenu.h"

class LoggedInMenu : public QMainWindow
{
	Q_OBJECT

public:
	LoggedInMenu(QWidget *parent = nullptr);
	~LoggedInMenu();

private slots:
	void on_playPushButton_clicked();
	void on_viewMyProfilePushButton_clicked();
	void on_optionsPushButton_clicked();
	void on_logOutPushButton_clicked();

private:
	Ui::LoggedInMenuClass ui;
	QWidget* parentWindow;
};
