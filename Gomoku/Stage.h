#pragma once
#include <SFML/Graphics.hpp>

#include "GameDef.h"
class Game;

class Stage
{
public:
	Stage(Game *game);
	virtual ~Stage();
	
	virtual void onEnter() {};
	virtual void onExit() {};

	virtual void handleEvent(sf::Event e) {};

	virtual void initBackGround() = 0;

	virtual void drawBackGround(sf::RenderWindow& window);
	virtual void drawActor(sf::RenderWindow& window) = 0;
	void draw(sf::RenderWindow& window);

	void changeStage(GameDef::StageEnum stage);

	Game* getGame();

protected:
	sf::RectangleShape m_backGround;
	Game* m_game;
		
};

