#pragma once

#include <QMainWindow>
#include "ui_NumericQuestion.h"
#include <cpr/cpr.h>
#include <crow.h>

class NumericQuestion : public QMainWindow
{
	Q_OBJECT

public:
	NumericQuestion(QWidget *parent);
	~NumericQuestion();

private slots:
	void on_SendButton_clicked();

private:
	Ui::NumericQuestionClass ui;
	QWidget* parentWindow;
};
