#include "Game.h"

Game::Game(QWidget *parent, std::string username)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	parentWindow = parent;
	this->setStyleSheet("");
	this->username = username;
	int mapHeight = 0;
	int mapWidth = 0;
	auto startGame = cpr::Put(
		cpr::Url{ "http://localhost:4960/startGame" }
	);
	if (startGame.status_code == 200 || startGame.status_code == 201) {
		auto gameData = crow::json::load(startGame.text);

		std::vector<std::string> usernames_parsed = split(gameData["usernames_unparsed"].s(), " ");

		mapHeight = gameData["mapHeight"].i();
		mapWidth = gameData["mapWidth"].i();
		map = new QGridLayout;
		generateMap(mapHeight, mapWidth);
		//showMap(mapHeight, mapWidth);

		QPixmap pix;

		pix.load("./red_player1.png");
		ui.Player1Label->setPixmap(pix.scaled(ui.Player1Label->width(), ui.Player1Label->height(), Qt::KeepAspectRatio));
		ui.Player1Username->setText((QString::fromUtf8((usernames_parsed[0].data()),
			int(usernames_parsed[0].size()))));

		pix.load("./blue_player2.png");
		ui.Player2Label->setPixmap(pix.scaled(ui.Player2Label->width(), ui.Player2Label->height(), Qt::KeepAspectRatio));
		ui.Player2Username->setText((QString::fromUtf8((usernames_parsed[1].data()),
			int(usernames_parsed[1].size()))));

		if (gameData["nrPlayers"].i() >= 3) {

			pix.load("./yellow_player3.png");
			ui.Player3Label->setPixmap(pix.scaled(ui.Player3Label->width(), ui.Player3Label->height(), Qt::KeepAspectRatio));
			ui.Player3Username->setText((QString::fromUtf8((usernames_parsed[2].data()),
				int(usernames_parsed[2].size()))));

			if (gameData["nrPlayers"].i() == 4) {

				pix.load("./green_player4.png");
				ui.Player4Label->setPixmap(pix.scaled(ui.Player4Label->width(), ui.Player4Label->height(), Qt::KeepAspectRatio));
				ui.Player4Username->setText((QString::fromUtf8((usernames_parsed[3].data()),
					int(usernames_parsed[3].size()))));
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
			QPushButton* button = new QPushButton();
			
			button->setText("100");
			button->resize(40, 80);
			button->move(40 * j, 40 * i);
			button->setAutoFillBackground(true);
			button->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(0, 0, 0)");
			button->show();
			map->addWidget(button, i, j);
		}
	}

	ui.mapWidget->setLayout(map);
	ui.mapWidget->show();
}

void Game::showMap(size_t kHeight, size_t kWidth)
{
	QMainWindow *window = new QMainWindow;
	this->setCentralWidget(ui.mapWidget);
	update();
}
