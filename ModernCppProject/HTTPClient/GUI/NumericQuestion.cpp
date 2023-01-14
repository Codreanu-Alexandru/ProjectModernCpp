#include "NumericQuestion.h"

NumericQuestion::NumericQuestion(QWidget* parent, Game& game)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	parentWindow = parent;
	this->game = &game;
	auto firstPhaseResponse = cpr::Get(cpr::Url{ "http://localhost:4960/numericQ/0" });
	auto questionJson = crow::json::load(firstPhaseResponse.text);
	QString question = QString::fromStdString(questionJson["question"].s());
	ui.Question->setText(question);
	//put with answer, id and time
	//response 
	// get with id in link with order number and number of choices
	//game.orderNumber = response
	// game.number of choices = number of choices
	//return to game
}

NumericQuestion::~NumericQuestion()
{}

void NumericQuestion::on_SendButton_clicked()
{
	QString qString_answer = ui.AnswerLine->text();
	std::string answerStr = qString_answer.toLocal8Bit().constData();

	auto answerPut = cpr::Put(
		cpr::Url{ "http://localhost:4960/numericAnswer" },
		cpr::Payload{
			{ "answer", answerStr }
		}
	);
	if (answerPut.status_code == 200 || answerPut.status_code == 201)
	{
		auto phaseDataGet = cpr::Get(cpr::Url{ "http://localhost:4960/phaseData/" + std::to_string(game->getUserId()) });
		auto PhaseData = crow::json::load(phaseDataGet.text);
		game->setNumberOfChoices(PhaseData["numberOfChoices"].i());
		game->setOrderPlace(PhaseData["orderPlace"].i());
	}
	else{
		ui.ErrorLabel->setText("Incorrect answer: it has to be a number. Try again.");
	}
	
