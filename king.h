#pragma once
#include "piece.h"
#include "board.h"
class King :
    public Piece
{
public:
	King(int row, int col, bool isWhite)
	{
		this->position = Position(row, col);
		this->fWhite = isWhite;
	}

	void getMoves(std::set<Move>& moves, Board board)
	{

	}
};

