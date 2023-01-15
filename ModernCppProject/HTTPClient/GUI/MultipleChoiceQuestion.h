#pragma once

#include <QMainWindow>
#include "ui_MultipleChoiceQuestion.h"

class MultipleChoiceQuestion : public QMainWindow
{
	Q_OBJECT

public:
	MultipleChoiceQuestion(QWidget *parent = nullptr);
	~MultipleChoiceQuestion();

private slots:
	void on_option1PushButton_clicked();
	void on_option2PushButton_clicked();
	void on_option3PushButton_clicked();
	void on_option4PushButton_clicked();

private:
	Ui::MultipleChoiceQuestionClass ui;
	QWidget* parentWindow;

	uint16_t option;
};
