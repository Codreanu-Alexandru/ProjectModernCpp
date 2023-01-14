#include "LogInMenu.h"

LogInMenu::LogInMenu(QWidget *parent)
	: QMainWindow(parent)
{
	parentWindow = parent;
	ui.setupUi(this);
	QPixmap pix("./spartan_clipart.png");
	int img_width = ui.LogInImage->width();
	int img_height = ui.LogInImage->height();
	ui.LogInImage->setPixmap(pix.scaled(img_width, img_height, Qt::KeepAspectRatio));
}

LogInMenu::~LogInMenu()
{}

void LogInMenu::on_logIn2PushButton_clicked() {

	cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:4960/users" });

	QString qString_username = ui.usernameLineEdit->text();
	QString qString_password = ui.passwordLineEdit->text();

	std::string username = qString_username.toLocal8Bit().constData();
	std::string password = qString_password.toLocal8Bit().constData();
	int id = -1;

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