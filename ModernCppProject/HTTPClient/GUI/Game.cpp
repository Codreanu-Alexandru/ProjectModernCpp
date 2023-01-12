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
		map = new QGridLayout;
		generateMap(mapHeight, mapWidth);
		showMap(mapHeight, mapWidth);
	}
}

Game::~Game()
{}

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
