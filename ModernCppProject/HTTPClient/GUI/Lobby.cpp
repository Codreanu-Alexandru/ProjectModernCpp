#include "Lobby.h"
#include <qtimer.h>
#include <string>

Lobby::Lobby(QWidget* parent, std::string username)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	parentWindow = parent;
	timerSeconds = 30;
	m_username = username;
	playersInLobby = 1;

	auto lobbyResponse = cpr::Put(
		cpr::Url{ "http://localhost:4960/sendPlayerInLobbyToServer" },
		cpr::Payload{
			{ "username", m_username }
		}
	);
	
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
	timer->start(1000);

}

void Lobby::showTime()
{
	
	cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:4960/lobbyInfo" });
	
	auto lobbyData = crow::json::load(response.text);
	//auto lobbyData = std::stoi(response.text);
	
	QString playersText = QString::number(lobbyData["playersInLobby"].i());
	ui.NumberOfPlayers->setText(playersText);

	if (response.status_code == 303)
	{
		QString timerText = QString::number(lobbyData["timerSeconds"].i());
		ui.Timer->setText(timerText);
	}
	if (response.status_code == 302)
	{
		timer->stop();
		hide();
		game = new Game(parentWindow);
		game->show();
	}


}

Lobby::~Lobby()
{}
