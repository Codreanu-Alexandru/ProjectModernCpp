#include "GUI.h"
#include <QtWidgets/QApplication>
#include <qfile.h>
#include <qmessagebox.h>
#include <iostream>
#include <numeric>
#include <sstream>
#include <regex>
#include <string>
#include <cpr/cpr.h>
#include <crow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Setting the template
    QFile styleSheetFile("./Irrorater.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);

    GUI w;
    w.show();
    return a.exec();
}
