#pragma once
#include <SFML/Graphics.hpp>

#include "GameDef.h"

class WinLine
{
public:
	WinLine(sf::Color color);
	~WinLine();

	void setLine(sf::Vector2f pos1, sf::Vector2f pos2, const int boardNum);
	void deleteLine();

	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape m_shape;
	sf::Color m_color;
};

