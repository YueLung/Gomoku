#include "BoardMenuStage.h"

#include "Game.h"

BoardMenuStage::BoardMenuStage(Game* game) : MenuStage(game)
{
	Button* btn1 = new Button(" 5  X 5  ", sf::Color::Black, sf::Vector2f(300, 50), sf::Vector2f(350, 300), std::bind(&BoardMenuStage::fiveXfiveButtonFun, this));
	Button* btn2 = new Button(" 10 X 10 ", sf::Color::Black, sf::Vector2f(300, 50), sf::Vector2f(350, 400), std::bind(&BoardMenuStage::tenXtenButtonFun, this));
	Button* btn3 = new Button(" 15 X 15 ", sf::Color::Black, sf::Vector2f(300, 50), sf::Vector2f(350, 500), std::bind(&BoardMenuStage::fifteenXfifteenButtonFun, this));
	m_buttonVec.push_back(btn1);
	m_buttonVec.push_back(btn2);
	m_buttonVec.push_back(btn3);
}

BoardMenuStage::~BoardMenuStage()
{
}

void BoardMenuStage::fiveXfiveButtonFun()
{
	m_game->setBoardGridRule(GameDef::FiveXFive);
	changeStage(GameDef::StageEnum::CheckBoard);
}

void BoardMenuStage::tenXtenButtonFun()
{
	m_game->setBoardGridRule(GameDef::TenXTen);
	changeStage(GameDef::StageEnum::CheckBoard);
}

void BoardMenuStage::fifteenXfifteenButtonFun()
{
	m_game->setBoardGridRule(GameDef::FifteenXFifteen);
	changeStage(GameDef::StageEnum::CheckBoard);
}
