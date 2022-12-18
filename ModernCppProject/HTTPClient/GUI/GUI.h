#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"
#include <qpixmap.h>
#include "LogInMenu.h"
#include "SignUpMenu.h"

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    ~GUI();

private slots:
    void on_logInPushButton_clicked();
    void on_signUpPushButton_clicked();
    void on_tutorialPushButton_clicked();
    void on_exitPushButton_clicked();

private:
    Ui::GUIClass ui;
    LogInMenu* logInMenu;
    SignUpMenu* signUpMenu;
};
