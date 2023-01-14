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
#include "NumericQuestion.h"

class Game : public QMainWindow
{
	Q_OBJECT

public:
	Game(QWidget *parent, std::string username, int userId);
	~Game();
	
	void Display();
	void generateMap(size_t kHeight, size_t kWidth);
	void showMap(size_t kHeight, size_t kWidth);
	void start();
	void setNumberOfChoices(int numberOfChoices);
	void setOrderPlace(int orderPlace);
	int getUserId();

private slots:
	void on_readyPushButton_clicked();

private:
	Ui::GameClass ui;
	QWidget *parentWindow;
	QTimer* qtimer;
	int mapWidth;
	int mapHeight;
	std::string username;
	NumericQuestion* numericQuestion;
	QGridLayout* map;
	QWidget* mapWidget;
	int numberOfChoices;
	int orderPlace;
	int userId;
};
