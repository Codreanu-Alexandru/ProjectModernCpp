#pragma once

#include <QMainWindow>
#include "ui_NumericQuestion.h"
#include <cpr/cpr.h>
#include <crow.h>

class NumericQuestion : public QMainWindow
{
	Q_OBJECT

public:
	NumericQuestion(QWidget* parent, uint16_t& numberOfChoices, uint16_t& orderPlace, uint16_t userId);
	~NumericQuestion();

private slots:
	void on_SendButton_clicked();

private:
	Ui::NumericQuestionClass ui;

	uint16_t* m_numberOfChoices;
	uint16_t* m_orderPlace;

	uint16_t m_userId;
};
