#pragma once
#include <SFML/Graphics.hpp>

class Label
{
public:
	Label(sf::Vector2f pos);
	~Label();

	void initTxt();

	void setText(std::string str);
	void setSize(int size);

	void setEnable(bool enable);

	void draw(sf::RenderWindow& window) ;

private:
	sf::Font m_font;
	sf::Text m_text;
	int m_size;
};

