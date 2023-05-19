#pragma once

#include "piece.h"
#include "position.h"
#include <set>

class Pawn : public Piece
{
public:
	Pawn(int row, int col, bool isWhite)
	{
		this->position = Position(row, col);
		this->fWhite = isWhite;
	};
	void getMoves(std::set<Move> &moves, Board &board);

	char getLetter()
	{
		return 'p';
	}
};