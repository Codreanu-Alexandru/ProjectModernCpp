#include "LoggedInMenu.h"

LoggedInMenu::LoggedInMenu(QWidget *parent, CurrentUser *currentUser)
	: QMainWindow(parent)
{
	parentWindow = parent;
	ui.setupUi(this);
	loggedUser = currentUser;

	QPixmap pix("./castle.png");
	int img_width = ui.castleImageLabel->width();
	int img_height = ui.castleImageLabel->height();
	ui.castleImageLabel->setPixmap(pix.scaled(img_width, img_height, Qt::KeepAspectRatio));
}

LoggedInMenu::~LoggedInMenu()
{}

void LoggedInMenu::on_playPushButton_clicked() {

	hide();
	preLobbyMenu = new PreLobbyMenu(this);
	preLobbyMenu->show();
}

void LoggedInMenu::on_viewMyProfilePushButton_clicked() {

	hide();
	profileViewTab = new ProfileViewTab(this, loggedUser);
	profileViewTab->show();
}

void LoggedInMenu::on_optionsPushButton_clicked() {

}

void LoggedInMenu::on_logOutPushButton_clicked() {

	this->close();
	parentWindow->show();
}

