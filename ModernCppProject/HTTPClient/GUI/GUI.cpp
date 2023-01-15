#include "GUI.h"

GUI::GUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QPixmap pix("./emperor_clipart.png");
    ui.mainMenuImage->setPixmap(pix.scaled(ui.mainMenuImage->width(), ui.mainMenuImage->height(), Qt::KeepAspectRatio));
}

GUI::~GUI()
{}

void GUI::on_logInPushButton_clicked() {

    hide();
    logInMenu = new LogInMenu(this);
    logInMenu->show();
}

void GUI::on_signUpPushButton_clicked() {

    hide();
    signUpMenu = new SignUpMenu(this);
    signUpMenu->show();
}

void GUI::on_tutorialPushButton_clicked() {

}

void GUI::on_exitPushButton_clicked() {

    close();
}