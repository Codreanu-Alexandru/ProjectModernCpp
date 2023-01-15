#include "Game.h"

Game::Game(QWidget *parent, CurrentUser* currentUser)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	parentWindow = parent;
	loggedUser = currentUser;
	idTurn = 0;
	update_line = -1;
	update_col = -1;

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
}

Game::~Game()
{}

void Game::showEvent(QShowEvent* ev)
{
	QMainWindow::showEvent(ev);
	showEventHelper();
}

void Game::showEventHelper()
{
	QTimer::singleShot(3000, this, SLOT(start()));
}


void Game::generateMap(size_t rows, size_t cols)
{
	for (uint8_t index_line = 0; index_line < rows; index_line++) {
		for (uint8_t index_col = 0; index_col < cols; index_col++) {
			QPushButton* button = new QPushButton(QString("(%1, %2)").arg(index_line).arg(index_col));
			
			button->setText("100");
			button->resize(40, 80);
			button->move(40 * index_col, 40 * index_line);
			button->setAutoFillBackground(true);
			if (update_line == index_line && update_col == index_col) {

				button->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(0, 0, 0)");
			}
			else {
				button->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(0, 0, 0)");
			}
			button->show();

			map->addWidget(button, index_line, index_col);
			connect(button, &QPushButton::clicked, [=] { buttonClicked(index_line, index_col, 1); });
		}
	}

	ui.mapWidget->setLayout(map);
	ui.mapWidget->show();
}

void Game::buttonClicked(uint8_t row, uint8_t col, int id) {

	if (id == idTurn) {

		update_line = row;
		update_col = col;
		update();
	}
}

void Game::start() //Checks state
{
	auto stateResponse = cpr::Get(cpr::Url{ "http://localhost:4960/gameState" });
	auto gameState = crow::json::load(stateResponse.text);
	while(gameState["State"].i() != 6)
	{
		if (gameState["State"].i() == 1)
		{
			nQuestionWindow = new NumericQuestion(this, numberOfChoices, orderPlace, loggedUser->getId());
			nQuestionWindow->show();
			this->close();

			break;
		}
		else if (gameState["State"].i() == 2)
		{
			idTurn = 1;
		}

		stateResponse = cpr::Get(cpr::Url{ "http://localhost:4960/gameState" });
		gameState = crow::json::load(stateResponse.text);
		Sleep(1000);
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