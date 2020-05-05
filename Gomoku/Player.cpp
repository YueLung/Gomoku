#include "Player.h"

Player::Player(PieceColor pieceColor, PieceManager *pieceMgr):m_turnNum(1), 
	m_pieceMgr(pieceMgr), m_isMyTurn(false)
{
	switch (pieceColor)
	{
	case White:
		m_pieceColor = sf::Color::White;
		break;
	case Black:
		m_pieceColor = sf::Color::Black;
		break;
	default:
		break;
	}
}

Player::~Player()
{
}

void Player::changeTurn()
{
	m_isMyTurn = !m_isMyTurn;
}
