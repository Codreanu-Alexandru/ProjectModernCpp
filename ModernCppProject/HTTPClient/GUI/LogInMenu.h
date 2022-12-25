#pragma once

#include <QMainWindow>
#include "ui_LogInMenu.h"
#include <cpr/cpr.h>
#include <crow.h>
#include <qmessagebox.h>
#include "LoggedInMenu.h"
#include "AuthUtils.h"

class LogInMenu : public QMainWindow
{
	Q_OBJECT

public:
	LogInMenu(QWidget *parent = nullptr);
	~LogInMenu();

private slots:
	void on_logIn2PushButton_clicked();
	void on_back1PushButton_clicked();

private:
	Ui::LogInMenuClass ui;
	QWidget* parentWindow;
	LoggedInMenu* loggedInMenu;
};
