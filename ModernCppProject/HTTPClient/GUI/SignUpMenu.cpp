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

	QString qString_username = ui.username2LineEdit->text();
	QString qString_password = ui.password2LineEdit->text();

	std::string username = qString_username.toStdString();
	std::string password = qString_password.toStdString();

	if (username == "test") {
		// EMPTY
	}
	else {
		ui.signUpErrorLabel->setText("Username already taken. Try a different one.");
	}
}

void SignUpMenu::on_back2PushButton_clicked() {

	this->close();
	parentWindow->show();
}