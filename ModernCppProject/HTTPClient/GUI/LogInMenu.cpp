#include "LogInMenu.h"

LogInMenu::LogInMenu(QWidget *parent)
	: QMainWindow(parent)
{
	parentWindow = parent;
	ui.setupUi(this);
	QPixmap pix("./spartan_clipart.png");
	ui.LogInImage->setPixmap(pix.scaled(ui.LogInImage->width(), ui.LogInImage->height(), Qt::KeepAspectRatio));
}

LogInMenu::~LogInMenu()
{}

void LogInMenu::on_logIn2PushButton_clicked() {

	cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:4960/users" });

	std::string username = ui.usernameLineEdit->text().toLocal8Bit().constData();
	std::string password = ui.passwordLineEdit->text().toLocal8Bit().constData();

	if (correctAuthentication(username, password, response)) {

		auto userResponse = cpr::Put(
			cpr::Url{ "http://localhost:4960/sendExistingUserToServer" },
			cpr::Payload{
				{ "username", username },
				{ "password", password }
			}
		);

		if (userResponse.status_code == 200 || userResponse.status_code == 201) {

			CurrentUser* currentUser = new CurrentUser;
			currentUser->createUser(username);

			hide();
			loggedInMenu = new LoggedInMenu(this, currentUser);
			loggedInMenu->show();
		}
		else {
			QMessageBox::warning(this, "Log In Error", "There was an error registering your information.");
		}
	}
	else {
		ui.errorLabel->setText("Incorrect username or password. Try again.");
	}
}

void LogInMenu::on_back1PushButton_clicked() {

	this->close();
	parentWindow->show();
}