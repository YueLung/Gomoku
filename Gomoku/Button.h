#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

#include "GameDef.h"

class Button 
{
public:
	Button(std::string name, sf::Color color, sf::Vector2f size, sf::Vector2f pos, std::function<void(void)> fun);
	~Button();

	void initTxt();

	void handleEvent(sf::Event e, const sf::RenderWindow& window) ;
	void setPosition(const sf::Vector2f pos) ;
	void setSize(const sf::Vector2f size) ;

	void setButtonColor(sf::Color color);
	void setTxtColor(sf::Color color);

	void draw(sf::RenderWindow& window);

	bool m_enable;

private:
	sf::RectangleShape m_shape;
	sf::Color m_shapeColor;
	std::string m_name;
	sf::Font m_font;
	sf::Text m_text;
	
	std::function<void(void)> m_PressFun;

};

