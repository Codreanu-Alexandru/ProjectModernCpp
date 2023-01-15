#include "NumericQuestion.h"

NumericQuestion::NumericQuestion(QWidget* parent, uint16_t &numberOfChoices, uint16_t &orderPlace, uint16_t userId)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	auto firstPhaseResponse = cpr::Get(cpr::Url{ "http://localhost:4960/numericQ/0" });
	auto questionJson = crow::json::load(firstPhaseResponse.text);
	std::string question = questionJson["question"].s();
	ui.questionLabel->setFont(QFont("Arial", 12));
	ui.questionLabel->setText(QString::fromUtf8(question.data(), int(question.size())));
	//ui.Question->setText(QString::fromStdString(questionJson["question"].s()));

	m_numberOfChoices = &numberOfChoices;
	m_orderPlace = &orderPlace;
	m_userId = userId;

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

	this->close();

	auto answerPut = cpr::Put(
		cpr::Url{ "http://localhost:4960/numericAnswer/"+std::to_string(m_userId)},
		cpr::Payload{
			{ "answer", answerStr },
			{"time", "30"}
		}
	);
	if (answerPut.status_code == 200 || answerPut.status_code == 201)
	{
		//parentWindow->show();
		this->close();
	}
	//if (answerPut.status_code == 200 || answerPut.status_code == 201)
	//{
	//	auto phaseDataGet = cpr::Get(cpr::Url{ "http://localhost:4960/phaseData/" + std::to_string(0) });
	//	auto PhaseData = crow::json::load(phaseDataGet.text);
	//	/*game->setNumberOfChoices(PhaseData["numberOfChoices"].i());
	//	game->setOrderPlace(PhaseData["orderPlace"].i());*/
	//}
	//else {
	//	ui.ErrorLabel->setText("Incorrect answer: it has to be a number. Try again.");
	//}
	//
}
