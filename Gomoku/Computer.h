#pragma once
#include <vector>

#include "Player.h"

namespace Com{
	enum PieceStatus {
		Empty,MyPiece,HisPiece
	};
}

typedef std::vector<std::vector<Com::PieceStatus> > PieceStatusTable;

class Computer :public Player
{
public:
	Computer(PieceColor pieceColor, PieceManager* pieceMgr);
	~Computer();

	virtual bool action();
	void initScoreTable();
	int getScore(const PieceStatusTable&pieceStatusTable);
	
	PieceStatusTable getCurrentPieceStatusTable();

private:
	int m_boardNum;
	std::vector<std::vector<int> > m_scoreTable;
};

