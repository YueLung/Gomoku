#include "Piece.h"

Piece::Piece(int boardGridNum, BoardPos pos):m_pos(pos)
{
	const float gridWidth = (GameDef::Board::BoardHeight - boardGridNum * GameDef::Board::LineThickness) / (boardGridNum + 1);
	m_radius = gridWidth / 2;

	init();
}

Piece::~Piece()
{
}

void Piece::init()
{
	m_placedFlag = false;
	setRadius(m_radius / 2);
	setPosition(m_pos.x, m_pos.y);
	setFillColor(sf::Color::Transparent);
}

void Piece::setPiece(sf::Color color)
{
	m_placedFlag = true;
	m_color = color;
	setRadius(m_radius);
	move(sf::Vector2f(-(m_radius / 2), -(m_radius / 2)));
	setFillColor(m_color);
}
