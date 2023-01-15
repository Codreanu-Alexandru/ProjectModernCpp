#include "Game.h"

Game::Game(QWidget *parent, CurrentUser* currentUser)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	parentWindow = parent;
	loggedUser = currentUser;

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

	start();
}

Game::~Game()
{}

void Game::Display() {

}

void Game::generateMap(size_t rows, size_t cols)
{
	for (int index_line = 0; index_line < rows; index_line++) {
		for (int index_col = 0; index_col < cols; index_col++) {
			QPushButton* button = new QPushButton();
			
			button->setText("100");
			button->resize(40, 80);
			button->move(40 * index_col, 40 * index_line);
			button->setAutoFillBackground(true);
			button->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(0, 0, 0)");
			button->show();

			map->addWidget(button, index_line, index_col);
		}
	}

	ui.mapWidget->setLayout(map);
	ui.mapWidget->show();
}

//void Game::showMap(size_t kHeight, size_t kWidth)
//{
//	QMainWindow *window = new QMainWindow;
//	this->setCentralWidget(ui.mapWidget);
//	update();
//}

void Game::start()//check state
{
	auto stateResponse = cpr::Get(cpr::Url{ "http://localhost:4960/gameState" });
	auto gameState = crow::json::load(stateResponse.text);
	if(gameState["State"].i() != 5)
	{
		if (gameState["State"].i() == 1)
		{
			nQuestionWindow = new NumericQuestion(this, numberOfChoices, orderPlace, loggedUser->getId());
			nQuestionWindow->show();

			//opens numeric question window(game)
			
			
			//returns to game
			// 
			//get turn 
			//if turn = game.orderNumber
			//while(number of choices > 0)
			//text label cu select region. show
		}
		if (gameState["State"].i() == 3)
		{
			
		}
	}
}

void Game::setNumberOfChoices(int numberOfChoices)
{
	this->numberOfChoices = numberOfChoices;
}

void Game::setOrderPlace(int orderPlace)
{
	this->orderPlace = orderPlace;
}