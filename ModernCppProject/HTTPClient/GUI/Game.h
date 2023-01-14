#pragma once

#include <QMainWindow>
#include "ui_Game.h"
#include <cpr/cpr.h>
#include <crow.h>
#include "qgridlayout.h"
#include "qpushbutton.h"
#include "qwidget.h"
#include "qstring.h"
#include "AuthUtils.h"

class Game : public QMainWindow
{
	Q_OBJECT

public:
	Game(QWidget *parent, std::string username);
	~Game();
	
	void Display();
	void generateMap(size_t kHeight, size_t kWidth);
	void showMap(size_t kHeight, size_t kWidth);

private:
	Ui::GameClass ui;
	QWidget *parentWindow;
	int mapWidth;
	int mapHeight;
	std::string username;
	QGridLayout* map;
	QWidget* mapWidget;
};
