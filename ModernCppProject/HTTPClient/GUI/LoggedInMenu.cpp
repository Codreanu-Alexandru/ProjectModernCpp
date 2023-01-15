#include "LoggedInMenu.h"


LoggedInMenu::LoggedInMenu(QWidget *parent, CurrentUser *currentUser)
	: QMainWindow(parent)
{
	parentWindow = parent;
	ui.setupUi(this);
	loggedUser = currentUser;

	QPixmap pix("./castle.png");
	ui.castleImageLabel->setPixmap(pix.scaled(ui.castleImageLabel->width(), ui.castleImageLabel->height(), Qt::KeepAspectRatio));
}

LoggedInMenu::~LoggedInMenu()
{}

void LoggedInMenu::on_playPushButton_clicked() {

	hide();
	lobby = new Lobby(this, loggedUser);
	lobby->show();
}

void LoggedInMenu::on_viewMyProfilePushButton_clicked() {

	hide();
	profileViewTab = new ProfileViewTab(this, loggedUser);
	profileViewTab->show();
}

void LoggedInMenu::on_deleteAccountPushButton_clicked() {

	auto deleteUserResponse = cpr::Put(
		cpr::Url{ "http://localhost:4960/deleteUserFromServer" },
		cpr::Payload{
			{ "username", loggedUser->getUsername()}
		}
	);
	if (deleteUserResponse.status_code == 200 || deleteUserResponse.status_code == 201) {

		QMessageBox::information(this, "Delete Account Info", "Your account has been succesfully deleted.");
		this->close();
		parentWindow->show();
	}
	else {

		QMessageBox::warning(this, "Delete Account Error", "There was an error registering your information.");
	}
}

void LoggedInMenu::on_logOutPushButton_clicked() {

	this->close();
	parentWindow->show();
}

