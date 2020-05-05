#include "Computer.h"

#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
#include <iostream>

Computer::Computer(PieceColor pieceColor, PieceManager* pieceMgr):
	Player(pieceColor, pieceMgr)
{
	m_boardNum = pieceMgr->getBoardNum();

	for (int i = 0; i < m_boardNum; ++i)
	{
		std::vector<Com::PieceStatus> pieceStatusVec;
		std::vector<int> scoreVect;

		for (int j = 0; j < m_boardNum; ++j)
		{
			pieceStatusVec.push_back(Com::Empty);
			scoreVect.push_back(0);
		}

		m_scoreTable.push_back(scoreVect);
	}
}

Computer::~Computer()
{
}

void Computer::initScoreTable()
{
	for (int i = 0; i < m_boardNum; ++i)
		for (int j = 0; j < m_boardNum; ++j)
			m_scoreTable[i][j] = 0;

}

int Computer::getScore(const PieceStatusTable &pieceStatusTable)
{
	const int SCORE_REF_TABLE[5] = { 1, 3, 6, 10, 9999 };
	int res = 0;

	for (int i = 0; i < m_boardNum; ++i)
	{
		for (int j = 0; j < m_boardNum; ++j)
		{
			if (pieceStatusTable[i][j] == Com::PieceStatus::MyPiece)
			{
				int aPieceScore = 1;

				for (int k = 1; k < 5; ++k)
				{
					if (j + k >= m_boardNum)
						break;

					if (pieceStatusTable[i][j + k] == Com::PieceStatus::MyPiece)
						aPieceScore += SCORE_REF_TABLE[k];
					else
						break;
				}

				for (int k = 1; k < 5; ++k)
				{
					if (i + k >= m_boardNum)
						break;

					if (pieceStatusTable[i + k][j] == Com::PieceStatus::MyPiece)
						aPieceScore += SCORE_REF_TABLE[k];
					else
						break;
				}

				for (int k = 1; k < 5; ++k)
				{
					if (i + k >= m_boardNum || j + k >= m_boardNum)
						break;

					if (pieceStatusTable[i + k][j + k] == Com::PieceStatus::MyPiece)
						aPieceScore += SCORE_REF_TABLE[k];
					else
						break;
				}

				for (int k = 1; k < 5; ++k)
				{
					if (i + k >= m_boardNum || j - k < 0)
						break;

					if (pieceStatusTable[i + k][j - k] == Com::PieceStatus::MyPiece)
						aPieceScore += SCORE_REF_TABLE[k];
					else
						break;
				}

				res += aPieceScore;
			}
		}
	}

	return res;
}

PieceStatusTable Computer::getCurrentPieceStatusTable()
{
	PieceStatusTable pieceStatusTable(m_boardNum, std::vector<Com::PieceStatus>(m_boardNum, Com::PieceStatus::Empty));
	auto AllPieceData = m_pieceMgr->getAllPieceData();

	for (int i = 0; i < m_boardNum; ++i)
	{
		for (int j = 0; j < m_boardNum; ++j)
		{
			if (AllPieceData[i][j].getFillColor() == m_pieceColor)
				pieceStatusTable[i][j] = Com::PieceStatus::MyPiece;
			else if (AllPieceData[i][j].getFillColor() == sf::Color::Transparent)
				pieceStatusTable[i][j] = Com::PieceStatus::Empty;
			else
				pieceStatusTable[i][j] = Com::PieceStatus::HisPiece;
		}
	}

	return pieceStatusTable;
}

bool Computer::action()
{
	srand(time(NULL));

	int maxScoreX, maxScoreY, maxScoreValue;
	maxScoreValue = 0;

	PieceStatusTable pieceStatusTable = getCurrentPieceStatusTable();

	for (int i = 0; i < m_boardNum; ++i)
	{
		for (int j = 0; j < m_boardNum; ++j)
		{
			if (pieceStatusTable[i][j] == Com::PieceStatus::Empty)
			{
				PieceStatusTable nextPieceStatusTable;
				nextPieceStatusTable = pieceStatusTable;
				nextPieceStatusTable[i][j] = Com::PieceStatus::MyPiece;

				m_scoreTable[i][j] = getScore(nextPieceStatusTable);

				if (maxScoreValue < m_scoreTable[i][j])
				{
					maxScoreValue = m_scoreTable[i][j];
					maxScoreX = i;
					maxScoreY = j;
				}
			}
		}
	}
	//test
	std::cout << maxScoreValue<<"\r\n";

	m_pieceMgr->PlacePiece(maxScoreX, maxScoreY, m_pieceColor);
	m_isMyTurn = false;

	return true;
}
