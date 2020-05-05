#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Piece.h"

class PieceManager 
{
public:

	PieceManager(int boardNum);
	~PieceManager();

	void initAllPiece();

	bool playerAction(const sf::FloatRect cursorRect, const sf::Color color);
	void PlacePiece(const int x, const int y, const sf::Color color);
	void draw(sf::RenderWindow& window);

	inline int getBoardNum() { return m_boardNum; }
	std::vector<std::vector<Piece> > getAllPieceData();

private:
	int m_boardNum;
	std::vector<std::vector<Piece> > m_PieceVec;
};

