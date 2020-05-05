#include "DiffcultMenuStage.h"

#include "Game.h"

DiffcultMenuStage::DiffcultMenuStage(Game* game) : MenuStage(game)
{
	Button* btn1 = new Button(" Easy ", sf::Color::Black, sf::Vector2f(300, 50), sf::Vector2f(350, 300), std::bind(&DiffcultMenuStage::easyButtonFun, this));
	Button* btn2 = new Button(" Medium ", sf::Color::Black, sf::Vector2f(300, 50), sf::Vector2f(350, 400), std::bind(&DiffcultMenuStage::mediumButtonFun, this));
	Button* btn3 = new Button(" Hard ", sf::Color::Black, sf::Vector2f(300, 50), sf::Vector2f(350, 500), std::bind(&DiffcultMenuStage::hardButtonFun, this));

	m_buttonVec.push_back(btn1);
	m_buttonVec.push_back(btn2);
	m_buttonVec.push_back(btn3);
}

DiffcultMenuStage::~DiffcultMenuStage()
{
}

void DiffcultMenuStage::easyButtonFun()
{
	m_game->setDifficultRule(GameDef::Easy);
	changeStage(GameDef::StageEnum::BoardMenu);
}

void DiffcultMenuStage::mediumButtonFun()
{
	m_game->setDifficultRule(GameDef::Medium);
	changeStage(GameDef::StageEnum::BoardMenu);
}

void DiffcultMenuStage::hardButtonFun()
{
	m_game->setDifficultRule(GameDef::Hard);
	changeStage(GameDef::StageEnum::BoardMenu);
}
