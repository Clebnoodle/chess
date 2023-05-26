#pragma once
#include "piece.h"
#include "position.h"
#include "board.h"

class Rook :
    public Piece
{
public:
	Rook(int row, int col, bool isWhite)
	{
		this->position = Position(row, col);
		this->fWhite = isWhite;
	}

	void getMoves(std::set<Move>& moves, Board& board);
	char getLetter() { return 'r'; }
	void display(ogstream gout);
};

