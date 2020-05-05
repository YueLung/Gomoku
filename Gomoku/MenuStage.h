#pragma once
#include "Stage.h"

#include "Button.h"
#include "GameDef.h"

class MenuStage :public Stage
{
public:
	MenuStage(Game* game);
	~MenuStage();

	void handleEvent(sf::Event e) override;
	void initBackGround() override;
	void drawActor(sf::RenderWindow& window) override;

protected:
	std::vector<Button*> m_buttonVec;
};

