#include "Stage.h"

#include "Game.h"

Stage::Stage(Game* game):m_game(game)
{
	m_backGround.setSize(sf::Vector2f(GameDef::Board::BoardWidth,
		GameDef::Board::BoardHeight));

}

Stage::~Stage()
{

}

void Stage::initBackGround()
{
}

void Stage::drawBackGround(sf::RenderWindow& window)
{
	window.draw(m_backGround);
}

void Stage::draw(sf::RenderWindow& window)
{
	drawBackGround(window);
	drawActor(window);
}

void Stage::changeStage(GameDef::StageEnum stage)
{
	m_game->changeStage(stage);
}

Game* Stage::getGame()
{
	return m_game; 
}
