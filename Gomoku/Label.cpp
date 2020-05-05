#include "Label.h"

Label::Label(sf::Vector2f pos): m_size(0)
{
	initTxt();
	m_text.setPosition(pos);
}

Label::~Label()
{
}

void Label::initTxt()
{
	if (!m_font.loadFromFile("Arial.ttf"))
	{
		//error
	}

	m_text.setFont(m_font);
	m_text.setFillColor(sf::Color::Red);
}

void Label::setText(std::string str)
{
	m_text.setString(str);
}

void Label::setSize(int size)
{
	m_size = size;
	m_text.setCharacterSize(m_size);
}

void Label::setEnable(bool enable)
{
	if (enable)
		m_text.setCharacterSize(m_size);
	else
		m_text.setCharacterSize(0);
}

void Label::draw(sf::RenderWindow& window)
{
	window.draw(m_text);
}
