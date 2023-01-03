#pragma once

#include <QMainWindow>
#include "ui_SignUpMenu.h"
#include "AuthUtils.h"
#include <qmessagebox.h>

class SignUpMenu : public QMainWindow
{
	Q_OBJECT

public:
	SignUpMenu(QWidget *parent = nullptr);
	~SignUpMenu();

private slots:
	void on_signUp2Button_clicked();
	void on_back2PushButton_clicked();

private:
	Ui::SignUpMenuClass ui;
	QWidget* parentWindow;
};
