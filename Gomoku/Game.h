#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include <vector>

#include "GameDef.h"

#include "PieceManager.h"
#include "People.h"
#include "Computer.h"

#include "PlayerMenuStage.h"
#include "BoardMenuStage.h"
#include "DiffcultMenuStage.h"
#include "CheckerBoardStage.h"

class Game
{
public:
	Game();
	~Game();

	void run();

	void addStage(GameDef::StageEnum name, Stage* stage);
	void changeStage(GameDef::StageEnum name);

	void setBoardGridRule(const GameDef::BoardGridEnum boardGrid);
	void setDifficultRule(const GameDef::DifficultEnum difficult);
	void setPlayerTypeRule(const GameDef::PlayerTypeEnum playerType);

	Rule getRule();

	const sf::RenderWindow& getWindow() const;
private:
	sf::RenderWindow m_window;

	Rule m_rule;
	PieceManager* m_pieceMgr;

	Stage *m_curStage;
	std::map<GameDef::StageEnum, Stage*> m_StageMap;
};

