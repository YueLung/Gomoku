#include "Button.h"

#include <iostream>
Button::Button(std::string name, sf::Color color, sf::Vector2f size, sf::Vector2f pos
	, std::function<void(void)> fun)
	: m_name(name), m_shapeColor(color), m_PressFun(fun), m_enable(false)
{	
	initTxt();

	m_shape.setFillColor(color);
	setSize(size);
	setPosition(pos);
}

Button::~Button()
{
}

void Button::initTxt()
{
	if (!m_font.loadFromFile( "Arial.ttf" ))
	{
		//error
	}

	m_text.setFont(m_font);
	m_text.setString(m_name);
	m_text.setFillColor(sf::Color::White);
}

void Button::handleEvent(sf::Event e, const sf::RenderWindow& window)
{
	auto pos = sf::Mouse::getPosition(window);

	if (m_shape.getGlobalBounds().contains((float)pos.x, (float)pos.y))
		setButtonColor(sf::Color::Red);
	else
		setButtonColor(m_shapeColor);

	switch (e.type) {
	case sf::Event::MouseButtonPressed:
		switch (e.mouseButton.button) {
		case sf::Mouse::Left:
			if (m_shape.getGlobalBounds().contains((float)pos.x, (float)pos.y)) {
				m_PressFun();
			}

		default:
			break;
		}

	default:
		break;
	}
}

void Button::setPosition(const sf::Vector2f pos)
{
	m_shape.setPosition(pos);
	m_text.setPosition(pos);
}

void Button::setSize(const sf::Vector2f size)
{
	m_shape.setSize(size);
	m_text.setCharacterSize(30);
}

void Button::setButtonColor(sf::Color color)
{
	m_shape.setFillColor(color);
}

void Button::setTxtColor(sf::Color color)
{
	m_text.setFillColor(color);
}

void Button::draw(sf::RenderWindow& window)
{
		window.draw(m_shape);
		window.draw(m_text);
}
