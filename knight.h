#pragma once
#include "piece.h"
#include "board.h"

class Knight :
    public Piece
{
public:
	Knight(int row, int col, bool isWhite)
	{
		this->position = Position(row, col);
		this->fWhite = isWhite;
	}

	void getMoves(std::set<Move>& moves, Board& board);
	char getLetter() { return 'n'; }
	void display(ogstream gout);
};

