#include "People.h"

#include <iostream>
People::People(sf::RenderWindow& window, PieceColor pieceColor, PieceManager *pieceMgr):
	Player(pieceColor, pieceMgr), m_window(window)
{
}

People::~People()
{

}

bool People::action()
{

	bool isPlace = false;

	if (isButtonPressed()) {
		sf::Vector2i cursorPos = sf::Mouse::getPosition(m_window);
		sf::FloatRect cursorRect(cursorPos.x, cursorPos.y, 1, 1);
		
		isPlace = m_pieceMgr->playerAction(cursorRect, m_pieceColor);

		if (isPlace)
			m_isMyTurn = false;
	}

	return isPlace;
}

bool People::isButtonPressed()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		return true;

	return false;
}