#include "MenuStage.h"

#include "Game.h"

MenuStage::MenuStage(Game* game):Stage(game)
{
	initBackGround();
}

MenuStage::~MenuStage()
{
	for (auto it : m_buttonVec) delete it;

	m_buttonVec.clear();
}

void MenuStage::handleEvent(sf::Event e)
{
	for (auto it : m_buttonVec)
		it->handleEvent(e, m_game->getWindow());
}

void MenuStage::initBackGround()
{
	m_backGround.setFillColor(sf::Color(200, 130, 0));
}

void MenuStage::drawActor(sf::RenderWindow& window)
{
	for (auto it : m_buttonVec)
		it->draw(window);
}
