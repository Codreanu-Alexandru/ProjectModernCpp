#include "LogInMenu.h"
//#include "../Client/AuthUtils.cpp"

LogInMenu::LogInMenu(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QPixmap pix("./spartan_clipart.png");
	int img_width = ui.LogInImage->width();
	int img_height = ui.LogInImage->height();
	ui.LogInImage->setPixmap(pix.scaled(img_width, img_height, Qt::KeepAspectRatio));
}

LogInMenu::~LogInMenu()
{}

void LogInMenu::on_logIn2PushButton_clicked() {

	//cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/users" });

	QString qString_username = ui.usernameLineEdit->text();
	QString qString_password = ui.passwordLineEdit->text();

	std::string username = qString_username.toStdString();
	std::string password = qString_password.toStdString();

	if (username == "test" && password == "test") {
	// EMPTY
	}
	else {
		ui.errorLabel->setText("Incorrect username or password. Try again.");
	}
}

void LogInMenu::on_back1PushButton_clicked() {

	hide();
}