#include "Lobby.h"
#include <qtimer.h>
#include <string>

Lobby::Lobby(QWidget* parent, CurrentUser* currentUser)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	parentWindow = parent;
	loggedUser = currentUser;

	timerSeconds = 15;
	playersInLobby = 0;

	QPixmap pix("./hourglass_clipart.png");
	ui.hourglassImageLabel->setPixmap(pix.scaled(ui.hourglassImageLabel->width(), ui.hourglassImageLabel->height(), Qt::KeepAspectRatio));

	QFont font("Arial", 12);
	ui.timerLabel->setFont(font);
	ui.numberOfPlayersLabel->setFont(font);

	auto lobbyResponse = cpr::Put(
		cpr::Url{ "http://localhost:4960/sendPlayerInLobbyToServer" },
		cpr::Payload{
			{ "username", loggedUser->getUsername() }
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

	ui.numberOfPlayersLabel->setText(QString::number(lobbyData["playersInLobby"].i()));

	switch (response.status_code) {

	case 303:

		ui.timerLabel->setText(QString::number(lobbyData["timerSeconds"].i()));

		break;

	case 302:

		timer->stop();
		QMessageBox::warning(this, "Lobby Error", "Insufficient players to start a game.");
		this->close();
		parentWindow->show();
		return;

		break;

	case 301:

		timer->stop();
		hide();
		gameWindow = new Game(parentWindow, loggedUser);
		gameWindow->show();

		break;

	default:

		break;
	}
}


void Lobby::on_cancelPushButton_clicked()
{
	auto lobbyResponse = cpr::Put(
		cpr::Url{ "http://localhost:4960/removePlayerFromLobby" },
		cpr::Payload{
			{ "username", loggedUser->getUsername() }
		}
	);

	timer->stop();
	this->close();
	parentWindow->show();
}

Lobby::~Lobby()
{}
