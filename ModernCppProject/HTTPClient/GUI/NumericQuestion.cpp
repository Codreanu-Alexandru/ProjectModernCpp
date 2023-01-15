#include "NumericQuestion.h"

NumericQuestion::NumericQuestion(QWidget* parent, uint16_t &numberOfChoices, uint16_t &orderPlace, uint16_t userId)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_numberOfChoices = &numberOfChoices;
	m_orderPlace = &orderPlace;
	m_userId = userId;

	//Extracting the unparsed question
	auto firstPhaseResponse = cpr::Get(cpr::Url{ "http://localhost:4960/numericQ/0" });
	auto questionJson = crow::json::load(firstPhaseResponse.text);
	std::vector<std::string> parsed_args =  split(questionJson["question"].s(), "/");

	bool isNumeric = questionJson["isNumeric"].b();
	if (isNumeric) {
		ui.questionLabel->setFont(QFont("Arial", 12, Qt::AlignCenter));
		ui.questionLabel->setText(QString::fromUtf8(parsed_args[0].data(), int(parsed_args[0].size())));
	}

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
	auto answerPut = cpr::Put(
		cpr::Url{ "http://localhost:4960/numericAnswer/" + std::to_string(m_userId)},
		cpr::Payload{
			{ "answer", ui.AnswerLine->text().toLocal8Bit().constData() },
			{"time", "30"}
		}
	);
	if (answerPut.status_code == 200 || answerPut.status_code == 201)
	{
		this->close();
	}
}
