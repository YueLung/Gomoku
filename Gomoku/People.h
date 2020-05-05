#pragma once
#include "Player.h"

class People :public Player
{
public:
	People(sf::RenderWindow &window, PieceColor pieceColor, PieceManager *pieceMgr);
	~People();

	bool action() override;
	bool isButtonPressed();
private:
	sf::RenderWindow &m_window;
};

