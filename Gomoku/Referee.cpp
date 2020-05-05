#include "Referee.h"

Referee::Referee(PieceManager* pieceMgr): m_pieceMgr(pieceMgr), m_winner("")
{
	m_boardNum = pieceMgr->getBoardNum();
}

Referee::~Referee()
{
}

bool Referee::isWin()
{
	Referee::PieceStatusTable pieceStatusTable = getCurrentPieceStatusTable();
	auto AllPieceData = m_pieceMgr->getAllPieceData();

	for (int i = 0; i < m_boardNum; ++i)
	{
		for (int j = 0; j < m_boardNum; ++j)
		{
			for (int k = 1; k < 5; ++k)
			{
				if (j + k >= m_boardNum)
					break;

				if (pieceStatusTable[i][j + k] != pieceStatusTable[i][j] || 
					pieceStatusTable[i][j + k] == PieceStatus::Empty)
					break;
				
				if (k == 4) {
					m_winner = transfColor(pieceStatusTable[i][j]);
					
					m_winPos.push_back(AllPieceData[i][j].getPosition());
					m_winPos.push_back(AllPieceData[i][j + 4].getPosition());
					return true;
				}
			}

			for (int k = 1; k < 5; ++k)
			{
				if (i + k >= m_boardNum)
					break;

				if (pieceStatusTable[i + k][j] != pieceStatusTable[i][j] ||
					pieceStatusTable[i + k][j] == PieceStatus::Empty)
					break;

				if (k == 4) {
					m_winner = transfColor(pieceStatusTable[i][j]);

					m_winPos.push_back(AllPieceData[i][j].getPosition());
					m_winPos.push_back(AllPieceData[i + 4][j].getPosition());
					return true;
				}
			}

			for (int k = 1; k < 5; ++k)
			{
				if (i + k >= m_boardNum || j + k >= m_boardNum)
					break;

				if (pieceStatusTable[i + k][j + k] != pieceStatusTable[i][j] ||
					pieceStatusTable[i + k][j + k] == PieceStatus::Empty)
					break;

				if (k == 4) {
					m_winner = transfColor(pieceStatusTable[i][j]);

					m_winPos.push_back(AllPieceData[i][j].getPosition());
					m_winPos.push_back(AllPieceData[i + 4][j + 4].getPosition());
					return true;
				}
			}

			for (int k = 1; k < 5; ++k)
			{
				if (i + k >= m_boardNum || j - k < 0)
					break;

				if (pieceStatusTable[i + k][j - k] != pieceStatusTable[i][j] ||
					pieceStatusTable[i + k][j - k] == PieceStatus::Empty)
					break;

				if (k == 4) {
					m_winner = transfColor(pieceStatusTable[i][j]);

					m_winPos.push_back(AllPieceData[i][j].getPosition());
					m_winPos.push_back(AllPieceData[i + 4][j - 4].getPosition());
					return true;
				}
			}		
		}
	}

	return false;
}

std::string Referee::transfColor(PieceStatus pieceStatus)
{
	std::string ret;

	switch (pieceStatus)
	{
	case Referee::Empty:
		ret = "";
		break;
	case Referee::White:
		ret = "White";
		break;
	case Referee::Black:
		ret = "Black";
		break;
	default:
		break;
	}

	return ret;
}

Referee::PieceStatusTable Referee::getCurrentPieceStatusTable()
{
	PieceStatusTable pieceStatusTable(m_boardNum, std::vector<PieceStatus>(m_boardNum, PieceStatus::Empty));
	auto AllPieceData = m_pieceMgr->getAllPieceData();
	
	for (int i = 0; i < m_boardNum; ++i)
	{
		for (int j = 0; j < m_boardNum; ++j)
		{
			if (AllPieceData[i][j].getFillColor() == sf::Color::White)
				pieceStatusTable[i][j] = PieceStatus::White;
			else if (AllPieceData[i][j].getFillColor() == sf::Color::Black)
				pieceStatusTable[i][j] = PieceStatus::Black;
			else
				pieceStatusTable[i][j] = PieceStatus::Empty;
		}
	}

	return pieceStatusTable;
}
