#include "PlayerMenuStage.h"

#include "Game.h"
#include "GameDef.h"

PlayerMenuStage::PlayerMenuStage(Game* game) : MenuStage(game)
{
	Button* btn1 = new Button(" Player       VS Player", sf::Color::Black, sf::Vector2f(300, 50), sf::Vector2f(350, 300), std::bind(&PlayerMenuStage::playerVsPlayerButtonFun, this));
	Button* btn2 = new Button(" Computer VS Player", sf::Color::Black, sf::Vector2f(300, 50), sf::Vector2f(350, 400), std::bind(&PlayerMenuStage::computerVsPlayerButtonFun, this));
	m_buttonVec.push_back(btn1);
	m_buttonVec.push_back(btn2);
}

PlayerMenuStage::~PlayerMenuStage()
{
}

void PlayerMenuStage::playerVsPlayerButtonFun()
{
	m_game->setPlayerTypeRule(GameDef::PlayerVsPlayer);
	changeStage(GameDef::StageEnum::BoardMenu);
}

void PlayerMenuStage::computerVsPlayerButtonFun()
{
	m_game->setPlayerTypeRule(GameDef::ComputerVsPlayer);
	changeStage(GameDef::StageEnum::DiffcultMenu);
}
