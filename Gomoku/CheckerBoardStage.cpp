#include "CheckerBoardStage.h"

#include "Game.h"
#include "GameDef.h"
#include "People.h"
#include "Computer.h"
#include "PieceManager.h"

#include <iostream>

CheckerBoardStage::CheckerBoardStage(Game* game, sf::RenderWindow& window):Stage(game), 
	m_boardNum(0), m_window(window), m_winLabel(sf::Vector2f(750, 500)), m_winLine(sf::Color::Red)
{
	initBackGround();

	Button* btn1 = new Button(" HOME ", sf::Color::Black, sf::Vector2f(200, 50), sf::Vector2f(750, 100), std::bind(&CheckerBoardStage::backToHomePageButtonFun, this));
	Button* btn2 = new Button(" RESTART ", sf::Color::Black, sf::Vector2f(200, 50), sf::Vector2f(750, 200), std::bind(&CheckerBoardStage::restartButtonFun, this));

	m_buttonVec.push_back(btn1);
	m_buttonVec.push_back(btn2);

	m_winLabel.setSize(38);
	m_winLabel.setEnable(false);
}

CheckerBoardStage::~CheckerBoardStage() 
{
	for (auto it : m_buttonVec) delete it;

	deletePlayer();
}

void CheckerBoardStage::onEnter()
{
	setRule(m_game->getRule());

	deployBoaardLine();
	deployPlayer();
}

void CheckerBoardStage::onExit()
{
	deletePlayer();
	clearLine();
}

void CheckerBoardStage::setRule(const Rule &rule)
{
	m_Rule = rule;

	switch (m_Rule.boardGrid)
	{
	case GameDef::FiveXFive:
		m_boardNum = 5;
		break;
	case GameDef::TenXTen:
		m_boardNum = 10;
		break;
	case GameDef::FifteenXFifteen:
		m_boardNum = 15;
		break;
	default:
		break;
	}
}

void CheckerBoardStage::deployBoaardLine()
{
	const float gridWidth = (GameDef::Board::BoardHeight - m_boardNum * GameDef::Board::LineThickness) / (m_boardNum + 1);
	const float linelength = gridWidth * (m_boardNum - 1) + m_boardNum * GameDef::Board::LineThickness;

	for (int i = 0; i < m_boardNum; ++i) {
		sf::RectangleShape rectangle(sf::Vector2f(linelength, GameDef::Board::LineThickness));
		rectangle.setFillColor(sf::Color::Black);
		rectangle.setPosition(gridWidth, gridWidth * (i + 1) + GameDef::Board::LineThickness * i);
		m_horizontalLine.push_back(rectangle);
	}

	for (int i = 0; i < m_boardNum; ++i) {
		sf::RectangleShape rectangle(sf::Vector2f(GameDef::Board::LineThickness, linelength));
		rectangle.setFillColor(sf::Color::Black);
		rectangle.setPosition(gridWidth * (i + 1) + GameDef::Board::LineThickness * i, gridWidth);
		m_verticalLine.push_back(rectangle);
	}
}

void CheckerBoardStage::deployPlayer()
{
	m_pieceMgr = new PieceManager(m_boardNum);
	m_referee = new Referee(m_pieceMgr);

	switch (m_Rule.playerType)
	{
	case GameDef::PlayerTypeEnum::ComputerVsPlayer:
		m_p1 = new People(m_window, PieceColor::White, m_pieceMgr);
		m_p1->changeTurn();
		m_p2 = new Computer(PieceColor::Black, m_pieceMgr);
		break;
	case GameDef::PlayerTypeEnum::PlayerVsPlayer:
		m_p1 = new People(m_window, PieceColor::Black, m_pieceMgr);
		m_p2 = new People(m_window, PieceColor::White, m_pieceMgr);
		m_p2->changeTurn();
		break;
	} 
}

void CheckerBoardStage::clearLine()
{
	m_horizontalLine.clear();
	m_verticalLine.clear();
	m_winLine.deleteLine();
}

void CheckerBoardStage::deletePlayer()
{
	if (m_p1) delete m_p1;
	if (m_p2) delete m_p2;
	if (m_pieceMgr) delete m_pieceMgr;
	if (m_referee) delete m_referee;

	m_p1 = NULL;
	m_p2 = NULL;
	m_pieceMgr = NULL;
	m_referee = NULL;
}

void CheckerBoardStage::handleEvent(sf::Event e)
{
	for (auto it : m_buttonVec)
		it->handleEvent(e, m_game->getWindow());

	if (m_referee && !m_referee->isWin()) 
	{
		if (m_p1->isMyTurn()) {
			if (m_p1->action())
				m_p2->changeTurn();
		}
		else if (m_p2->isMyTurn()) {
			if (m_p2->action())
				m_p1->changeTurn();
		}

		if (m_referee->isWin()) {
			if (m_p1->isMyTurn()) m_p1->changeTurn();
			if (m_p2->isMyTurn()) m_p2->changeTurn();

			m_winLabel.setText(m_referee->getWinner() + "  WIN !!!");
			m_winLabel.setEnable(true);

			m_winLine.setLine(m_referee->getWinTwoPos()[0], m_referee->getWinTwoPos()[1], m_boardNum);
		}
	}
}

void CheckerBoardStage::initBackGround()
{
	m_backGround.setFillColor(sf::Color(200, 130, 0));
}

void CheckerBoardStage::drawActor(sf::RenderWindow& window)
{
	for (int i = 0; i < m_boardNum; ++i) {
		window.draw(m_horizontalLine[i]);
		window.draw(m_verticalLine[i]);
	}

	for (auto it : m_buttonVec)
		it->draw(window);

	m_pieceMgr->draw(window);
	m_winLabel.draw(window);
	m_winLine.draw(window);
}

void CheckerBoardStage::backToHomePageButtonFun()
{
	m_winLabel.setEnable(false);
	changeStage(GameDef::StageEnum::PlayerMenu);
}

void CheckerBoardStage::restartButtonFun()
{
	m_winLabel.setEnable(false);
	onEnter();
	changeStage(GameDef::StageEnum::CheckBoard);
}


