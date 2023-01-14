#include "Game.h"

Game::Game(QWidget *parent, std::string username)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	parentWindow = parent;
	this->username = username;
	int mapHeight = 0;
	int mapWidth = 0;
	auto startGame = cpr::Put(
		cpr::Url{ "http://localhost:4960/startGame" }
	);
	if (startGame.status_code == 200 || startGame.status_code == 201) {
		auto gameData = crow::json::load(startGame.text);
		mapHeight = gameData["mapHeight"].i();
		mapWidth = gameData["mapWidth"].i();
		/*map = new QGridLayout;
		generateMap(mapHeight, mapWidth);
		showMap(mapHeight, mapWidth);*/

		QPixmap pix;

		pix.load("./red_player1.png");
		int imgw = ui.Player1Label->width();
		int imgh = ui.Player1Label->height();
		ui.Player1Label->setPixmap(pix.scaled(imgw, imgh, Qt::KeepAspectRatio));
		ui.Player1Username->setText("Player 1");

		pix.load("./blue_player2.png");
		ui.Player2Label->setPixmap(pix.scaled(ui.Player2Label->width(), ui.Player2Label->height(), Qt::KeepAspectRatio));
		ui.Player2Username->setText("Player 2");

		if (gameData["nrPlayers"].i() >= 3) {

			pix.load("./yellow_player3.png");
			ui.Player3Label->setPixmap(pix.scaled(ui.Player3Label->width(), ui.Player3Label->height(), Qt::KeepAspectRatio));
			ui.Player3Username->setText("Player 3");

			if (gameData["nrPlayers"].i() == 4) {

				pix.load("./green_player4.png");
				ui.Player4Label->setPixmap(pix.scaled(ui.Player4Label->width(), ui.Player4Label->height(), Qt::KeepAspectRatio));
				ui.Player4Username->setText("Player 4");
			}
		}
	}
}

Game::~Game()
{}

void Game::Display() {


}

void Game::generateMap(size_t rows, size_t cols)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			QPushButton* button = new QPushButton("r");
			button->resize(40, 40);
			button->move(40 * j, 40 * i);
			button->show();
			map->addWidget(button, i, j);
		}
	}

	mapWidget = new QWidget;
	mapWidget->setLayout(map);
}

void Game::showMap(size_t kHeight, size_t kWidth)
{
	QMainWindow *window = new QMainWindow;
	this->setCentralWidget(mapWidget);
	update();
}
