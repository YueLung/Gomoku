#include "WinLine.h"

WinLine::WinLine(sf::Color color): m_color(color)
{
}

WinLine::~WinLine()
{
}

void WinLine::setLine(sf::Vector2f pos1, sf::Vector2f pos2, const int boardNum)
{
	const float gridWidth = (GameDef::Board::BoardHeight - boardNum * GameDef::Board::LineThickness) / (boardNum + 1);

	sf::Vector2f startPos;

	m_shape.setSize(sf::Vector2f(GameDef::Board::LineThickness, gridWidth * 4.5));

	if ((int)pos1.y == (int)pos2.y) {
		startPos = pos1.x > pos2.x ? pos2 : pos1;
		m_shape.rotate(-90);
	}
	else{
		startPos = pos1;
		if ((int)pos1.x > (int)pos2.x) {
			m_shape.rotate(45);
			m_shape.setSize(sf::Vector2f(GameDef::Board::LineThickness, gridWidth * 6.5));
		}
		else if ((int)pos1.x < (int)pos2.x) {
			m_shape.rotate(-45);
			m_shape.setSize(sf::Vector2f(GameDef::Board::LineThickness, gridWidth * 6.5));
		}
	}

	startPos.y += gridWidth / 2;
	startPos.x += gridWidth / 2;
	
	m_shape.setFillColor(m_color);
	
	m_shape.setPosition(startPos);
}

void WinLine::deleteLine()
{
	m_shape.setFillColor(sf::Color::Transparent);
	m_shape.rotate(-m_shape.getRotation());
}

void WinLine::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}
