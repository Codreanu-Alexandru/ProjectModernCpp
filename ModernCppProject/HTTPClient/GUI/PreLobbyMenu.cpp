#include "PreLobbyMenu.h"

PreLobbyMenu::PreLobbyMenu(QWidget *parent)
	: QMainWindow(parent)
{
	parentWindow = parent;
	ui.setupUi(this);
}

PreLobbyMenu::~PreLobbyMenu()
{}

void PreLobbyMenu::on_twoPlayersPushButton_clicked()
{
}

void PreLobbyMenu::on_threePlayersPushButton_clicked()
{
}

void PreLobbyMenu::on_fourPlayersPushButton_clicked()
{
}



void PreLobbyMenu::on_backLobbyPushButton_clicked() {

	this->close();
	parentWindow->show();
}

