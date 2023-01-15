#pragma once

#include <QMainWindow>
#include "ui_NumericQuestion.h"
#include <cpr/cpr.h>
#include <crow.h>

class NumericQuestion : public QMainWindow
{
	Q_OBJECT

public:
	NumericQuestion(QWidget* parent, int& numberOfChoices, int& orderPlace, int& userId);
	~NumericQuestion();

private slots:
	void on_SendButton_clicked();

private:
	Ui::NumericQuestionClass ui;
	QWidget* parentWindow;
	int* m_numberOfChoices;
	int* m_orderPlace;
	int* m_userId;
};
