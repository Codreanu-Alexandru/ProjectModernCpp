#include "SignUpMenu.h"

SignUpMenu::SignUpMenu(QWidget *parent)
	: QMainWindow(parent)
{
	parentWindow = parent;
	ui.setupUi(this);
	QPixmap pix_left("./royal_design_left.png");
	QPixmap pix_right("./royal_design_right.png");
	int left_img_width = ui.leftImageLabel->width();
	int left_img_height = ui.leftImageLabel->height();
	int right_img_width = ui.rightImageLabel->width();
	int right_img_height = ui.rightImageLabel->height();
	ui.leftImageLabel->setPixmap(pix_left.scaled(left_img_width, left_img_height, Qt::KeepAspectRatio));
	ui.rightImageLabel->setPixmap(pix_right.scaled(right_img_width, right_img_height, Qt::KeepAspectRatio));
}

SignUpMenu::~SignUpMenu()
{}

void SignUpMenu::on_signUp2Button_clicked() {

	cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:4960/users" });

	QString qString_username = ui.username2LineEdit->text();
	QString qString_password = ui.password2LineEdit->text();

	std::string username = qString_username.toLocal8Bit().constData();
	std::string password = qString_password.toLocal8Bit().constData();

	if (!existingUser(username, response)) {

		auto userResponse = cpr::Put(
			cpr::Url{ "http://localhost:4960/sendNewUserToServer" },
			cpr::Payload{
				{ "username", username },
				{ "password", password }
			}
		);

		if (userResponse.status_code == 200 || userResponse.status_code == 201) {

			QMessageBox::information(this, "Sing Up Info", "Your account has been succesfully created.");
			this->close();
			parentWindow->show();
		}
		else {
			QMessageBox::warning(this, "Log In Error", "There was an error registering your information.");
		}
	}
	else {
		ui.signUpErrorLabel->setText("Username already taken. Try a different one.");
	}
}

void SignUpMenu::on_back2PushButton_clicked() {

	this->close();
	parentWindow->show();
}