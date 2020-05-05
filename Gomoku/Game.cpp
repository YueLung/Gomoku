#include "Game.h"

Game::Game() :m_window(sf::VideoMode(GameDef::Board::BoardWidth,
	GameDef::Board::BoardHeight), "Gomoku"), m_pieceMgr(NULL)
{
	addStage(GameDef::StageEnum::PlayerMenu, new PlayerMenuStage(this));
	addStage(GameDef::StageEnum::BoardMenu, new BoardMenuStage(this));
	addStage(GameDef::StageEnum::DiffcultMenu, new DiffcultMenuStage(this));
	addStage(GameDef::StageEnum::CheckBoard, new CheckerBoardStage(this, m_window));

	m_curStage = m_StageMap[GameDef::StageEnum::PlayerMenu];
}

Game::~Game()
{
	if (m_pieceMgr) delete m_pieceMgr;

	for (auto &i : m_StageMap) {
		delete i.second;
		i.second = nullptr;
	}
	
	m_pieceMgr = NULL;
}

void Game::run()
{
	while (m_window.isOpen()) {
		sf::Event event;
		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				m_window.close();

			m_curStage->handleEvent(event);
		}

		m_window.clear();

		m_curStage->draw(m_window);
		m_window.display();
	}
}

void Game::addStage(GameDef::StageEnum name, Stage* stage)
{
	if (m_StageMap.find(name) == m_StageMap.end()) {
		m_StageMap.insert(std::pair<GameDef::StageEnum, Stage*>(name, stage));
	}
	else {
		std::cout << "Error!! AddStage Reapeat";
	}
}

void Game::changeStage(GameDef::StageEnum name)
{
	if (m_StageMap.find(name) != m_StageMap.end()) {
		m_curStage->onExit();
		m_curStage = m_StageMap[name];
		m_curStage->onEnter();
	}
	else {
		//error
	}
}

void Game::setBoardGridRule(const GameDef::BoardGridEnum boardGrid)
{
	m_rule.boardGrid = boardGrid;
}

void Game::setDifficultRule(const GameDef::DifficultEnum difficult)
{
	m_rule.difficult = difficult;
}

void Game::setPlayerTypeRule(const GameDef::PlayerTypeEnum playerType)
{
	m_rule.playerType = playerType;
}

Rule Game::getRule()
{
	return m_rule;
}

const sf::RenderWindow& Game::getWindow() const
{
	return m_window;
}
