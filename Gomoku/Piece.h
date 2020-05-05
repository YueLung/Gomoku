#pragma once
#include <SFML/Graphics.hpp>

#include "GameDef.h"

struct BoardPos
{
	int x;
	int y;
};

class Piece :public sf::CircleShape
{
public:

	Piece(const int boardGridNum, BoardPos pos);
	~Piece();

	void init();

	double getRaius() { return m_radius; }

	void setPiece(sf::Color color);
	bool isPlaced() { return m_placedFlag; };
	
private:
	bool m_placedFlag;
	float m_radius;
	sf::Color m_color;
	BoardPos m_pos;
};

