#include "MultipleChoiceQuestion.h"

MultipleChoiceQuestion::MultipleChoiceQuestion(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	std::string question = "Intrebare intrebatoare";
	ui.questionLabel->setFont(QFont("Arial", 12));
	ui.questionLabel->setText(QString::fromUtf8(question.data(), int(question.size())));
}

MultipleChoiceQuestion::~MultipleChoiceQuestion()
{}

void MultipleChoiceQuestion::on_option1PushButton_clicked() {
	option = 1;
}

void MultipleChoiceQuestion::on_option2PushButton_clicked() {
	option = 2;
}

void MultipleChoiceQuestion::on_option3PushButton_clicked() {
	option = 3;
}

void MultipleChoiceQuestion::on_option4PushButton_clicked() {
	option = 4;
}