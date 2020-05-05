#pragma once
#include "Stage.h"

#include <vector>

#include "Player.h"
#include "Button.h"
#include "Referee.h"
#include "Label.h"
#include "WinLine.h"
#include "GameDef.h"

class Player;
class PieceManager;

struct Rule {
	GameDef::BoardGridEnum boardGrid;
	GameDef::DifficultEnum difficult;
	GameDef::PlayerTypeEnum playerType;
};

class CheckerBoardStage :public Stage
{
public:

	CheckerBoardStage(Game *game, sf::RenderWindow& window);
	~CheckerBoardStage();

	void onEnter() override;
	void onExit() override;

	void setRule(const Rule &rule);

	void deployBoaardLine();
	void deployPlayer();

	void clearLine();
	void deletePlayer();

	void handleEvent(sf::Event e) override;

	void initBackGround() override;

	void drawActor(sf::RenderWindow& window) override;

	void backToHomePageButtonFun();
	void restartButtonFun();

	inline int getBoardNum() { return m_boardNum; }
private:
	sf::RenderWindow &m_window;
	Rule m_Rule;
	int m_boardNum;
	std::vector<sf::RectangleShape> m_horizontalLine;
	std::vector<sf::RectangleShape> m_verticalLine;
	std::vector<Button*> m_buttonVec;
	Label m_winLabel;
	WinLine m_winLine;

	PieceManager *m_pieceMgr;
	Player *m_p1;
	Player *m_p2;

	Referee* m_referee;
};

