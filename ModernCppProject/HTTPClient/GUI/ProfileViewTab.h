#pragma once

#include <QMainWindow>
#include "AuthUtils.h"
#include "ui_ProfileViewTab.h"


class ProfileViewTab : public QMainWindow
{
	Q_OBJECT

public:
	ProfileViewTab(QWidget *parent, CurrentUser* currentUser);
	~ProfileViewTab();

private slots:
	void on_backProfilePushButton_clicked();

private:
	Ui::ProfileViewTabClass ui;
	QWidget* parentWindow;
	CurrentUser* loggedUser;
};
