#include "PieceManager.h"

PieceManager::PieceManager(int boardNum):m_boardNum(boardNum)
{
	const float gridWidth = (GameDef::Board::BoardHeight - m_boardNum * GameDef::Board::LineThickness) / (m_boardNum + 1);
	const float pieceRadius = gridWidth / 2;

	for (int i= 0; i < m_boardNum; ++i)
	{
		std::vector<Piece> pieceVec;
		for (int j = 0; j < m_boardNum; ++j)
		{ 
			BoardPos pos = {gridWidth - pieceRadius/2 + j * (gridWidth + GameDef::Board::LineThickness), 
							gridWidth * (i + 1) + GameDef::Board::LineThickness * i - pieceRadius/2 };
			Piece piece(boardNum, pos);
			pieceVec.push_back(piece);
		}
		m_PieceVec.push_back(pieceVec);
	}
}

PieceManager::~PieceManager()
{
}

void PieceManager::initAllPiece()
{
	for (int i = 0; i < m_boardNum; i++)
		for (int j = 0; j < m_boardNum; j++)
			m_PieceVec[i][j].init();
}

bool PieceManager::playerAction(const sf::FloatRect cursorRect, const sf::Color color)
{
	for (int i = 0; i < m_boardNum; i++)
	{
		for (int j = 0; j < m_boardNum; j++)
		{
			if (cursorRect.intersects(m_PieceVec[i][j].getGlobalBounds()) && !m_PieceVec[i][j].isPlaced())
			{
				PlacePiece(i, j, color);
				return true;
			}
		}
	}

	return false;
}

void PieceManager::PlacePiece(const int x, const int y, const sf::Color color)
{
	m_PieceVec[x][y].setPiece(color);
}

std::vector<std::vector<Piece> > PieceManager::getAllPieceData()
{
	return m_PieceVec;
}

void PieceManager::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < m_boardNum; i++)
		for (int j = 0; j < m_boardNum; j++)
			window.draw(m_PieceVec[i][j]);
}
