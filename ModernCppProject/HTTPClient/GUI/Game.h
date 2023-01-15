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
#include "MultipleChoiceQuestion.h"
#include <Windows.h>
#include <qtimer.h>

class Game : public QMainWindow
{
	Q_OBJECT

public:
	Game(QWidget *parent, CurrentUser* currentUser);
	~Game();
	
	void generateMap(size_t kHeight, size_t kWidth);
	void showMap(size_t kHeight, size_t kWidth);
	void setNumberOfChoices(int numberOfChoices);
	void setOrderPlace(int orderPlace);

protected:
	void showEvent(QShowEvent* ev);

private slots:
	void buttonClicked(uint8_t row, uint8_t col, int id);
	void start();

private:
	void showEventHelper();

private:
	Ui::GameClass ui;
	QWidget *parentWindow;
	NumericQuestion* nQuestionWindow;
	MultipleChoiceQuestion* mQuestionWindow;
	CurrentUser* loggedUser;

	QWidget* mapWidget;
	QGridLayout* map;
	size_t mapWidth;
	size_t mapHeight;

	uint8_t idTurn;
	uint8_t update_line;
	uint8_t update_col;
	uint16_t numberOfChoices;
	uint16_t orderPlace;
	QTimer* timer;


};
