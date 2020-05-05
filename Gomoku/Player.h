#pragma once
#include "PieceManager.h"

enum PieceColor {
	White,
	Black
};

class Player 
{
public:
	Player(PieceColor pieceColor, PieceManager *pieceMgr);
	~Player();

	bool isMyTurn() { return m_isMyTurn; };
	virtual bool action() = 0;
	void changeTurn();

protected:
	bool m_isMyTurn;
	int m_turnNum;
	sf::Color m_pieceColor;
	PieceManager *m_pieceMgr;
};

