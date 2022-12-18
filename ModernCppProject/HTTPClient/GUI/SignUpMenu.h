#pragma once

#include <QMainWindow>
#include "ui_SignUpMenu.h"

class SignUpMenu : public QMainWindow
{
	Q_OBJECT

public:
	SignUpMenu(QWidget *parent = nullptr);
	~SignUpMenu();

private slots:
	void on_signUp2Button_clicked();

private:
	Ui::SignUpMenuClass ui;
};
