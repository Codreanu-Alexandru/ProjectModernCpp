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

	QPixmap pix("./hourglass_clipart.png");
	int img_width = ui.hourglassImageLabel->width();
	int img_height = ui.hourglassImageLabel->height();
	ui.hourglassImageLabel->setPixmap(pix.scaled(img_width, img_height, Qt::KeepAspectRatio));

	QFont font("Arial", 12);
	ui.timerLabel->setFont(font);
	ui.numberOfPlayersLabel->setFont(font);

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

	QString playersText = QString::number(lobbyData["playersInLobby"].i());
	ui.numberOfPlayersLabel->setText(playersText);

	if (response.status_code == 303)
	{
		QString timerText = QString::number(lobbyData["timerSeconds"].i());
		ui.timerLabel->setText(timerText);
	}
	else if (response.status_code == 302)
	{	
		timer->stop();
		QMessageBox::warning(this, "Lobby Error", "Insufficient players to start a game.");
		this->close();
		parentWindow->show();
		return;
	}
	else if (response.status_code == 301)
	{
		timer->stop();
		hide();
		game = new Game(parentWindow, m_username);
		game->show();
		
	}
}


void Lobby::on_cancelPushButton_clicked()
{
	auto lobbyResponse = cpr::Put(
		cpr::Url{ "http://localhost:4960/removePlayerFromLobby" },
		cpr::Payload{
			{ "username", m_username }
		}
	);

	timer->stop();
	this->close();
	parentWindow->show();
}

Lobby::~Lobby()
{}
