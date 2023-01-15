#include "ProfileViewTab.h"

ProfileViewTab::ProfileViewTab(QWidget *parent, CurrentUser* currentUser)
	: QMainWindow(parent)
{
	parentWindow = parent;
	ui.setupUi(this);
	loggedUser = currentUser;

	QPixmap pix("./conqueror_clipart.png");
	ui.conquerorImageLabel->setPixmap(pix.scaled(ui.conquerorImageLabel->width(), ui.conquerorImageLabel->height(), Qt::KeepAspectRatio));

	QFont font("Arial", 14);

	//Setting the username
	ui.usernameLabel->setFont(font);
	ui.usernameLabel->setText(QString::fromUtf8(loggedUser->getUsername().data(), int(loggedUser->getUsername().size())));
	
	//Extracting the last 10 games played, if they exist
	const std::string matchHistory = loggedUser->getMatchHistory();
	std::string last10Matches = "";
	uint16_t nrOfGames = 0;

	for (const char& result : matchHistory) {
		
		last10Matches += result + " ";
		nrOfGames++;
		if (nrOfGames == 10) {
			break;
		}
	}
	while (nrOfGames <= 10) {

		last10Matches += "- ";
		nrOfGames++;
	}

	ui.matchHistoryLabel->setFont(font);
	ui.matchHistoryLabel->setText(QString::fromUtf8(last10Matches.data(), int(last10Matches.size())));

	//Calculating the winrate and number of wins
	uint16_t nrOfWins = 0;
	float winrate = 0.0;

	if (matchHistory.size() > 0) {

		for (const char& result : matchHistory) {
			winrate += ((int)result - 48 == 1) ? 1 : 0;
		}
		nrOfWins = (int)winrate;
		winrate /= matchHistory.size();
		winrate *= 100;
	}

	ui.winrateLabel->setFont(font);
	ui.winrateLabel->setText(QString::fromUtf8(std::to_string(winrate).data(), int(std::to_string(winrate).size())));

	ui.nrOfWinsLabel->setFont(font);
	ui.nrOfWinsLabel->setText(QString::fromUtf8(std::to_string(nrOfWins).data(), int(std::to_string(nrOfWins).size())));
}

ProfileViewTab::~ProfileViewTab()
{}

void ProfileViewTab::on_backProfilePushButton_clicked() {

	this->close();
	parentWindow->show();
}