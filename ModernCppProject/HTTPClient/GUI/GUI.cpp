#include "GUI.h"

GUI::GUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QPixmap pix("./emperor_clipart.png");
    int img_width = ui.mainMenuImage->width();
    int img_height = ui.mainMenuImage->height();
    ui.mainMenuImage->setPixmap(pix.scaled(img_width, img_height, Qt::KeepAspectRatio));
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