#pragma once
#include "PieceManager.h"

class Referee
{
	enum PieceStatus {
		Empty, White, Black
	};

	typedef std::vector<std::vector<PieceStatus> > PieceStatusTable;
public:

	Referee(PieceManager *pieceMgr);
	~Referee();

	bool isWin();

	inline std::string getWinner() { return m_winner; };
	inline std::vector<sf::Vector2f> getWinTwoPos() { return m_winPos;  };

	std::string transfColor(PieceStatus pieceStatus);

	PieceStatusTable getCurrentPieceStatusTable();

private:
	PieceManager* m_pieceMgr;
	int m_boardNum;
	std::string m_winner;
	std::vector<sf::Vector2f> m_winPos;
};

