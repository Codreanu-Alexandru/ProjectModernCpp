#include "LogInMenu.h"

LogInMenu::LogInMenu(QWidget *parent)
	: QMainWindow(parent)
{
	//cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/users" });
	//clientInstance = new ClientInfo();

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

	QString qString_username = ui.usernameLineEdit->text();
	QString qString_password = ui.passwordLineEdit->text();

	std::string username = qString_username.toStdString();
	std::string password = qString_password.toStdString();

	//std::vector<std::pair<std::string, std::string> > serverUsersInfos = clientInstance->getUserInfo();

	if (username == "test" && password == "test") {
		
		hide();
		loggedInMenu = new LoggedInMenu(this);
		loggedInMenu->show();
	}
	else {
		ui.errorLabel->setText("Incorrect username or password. Try again.");
	}
}

void LogInMenu::on_back1PushButton_clicked() {

	this->close();
	parentWindow->show();
}