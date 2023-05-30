#pragma once

#include "piece.h"
#include "position.h"
#include "board.h"

class Queen : public Piece
{
public:
	Queen(Position pos, bool isWhite)
	{
		this->position = pos;
		this->fWhite = isWhite;
	}
	Queen(int row, int col, bool isWhite)
	{
		this->position = Position(row, col);
		this->fWhite = isWhite;
	}

	void getMoves(std::set<Move>& moves, Board& board);
	PieceType getLetter() { return QUEEN; };
	void display(ogstream &gout);
};