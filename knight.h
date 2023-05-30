#pragma once
#include "piece.h"
#include "board.h"


/***********************************************************************
 * Header File:
 *    KNIGHT: Knight Piece
 *
 * Summary:
 *    Functions as a Knight Piece in a chess game.
 ************************************************************************/
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
	PieceType getLetter() { return KNIGHT; }
	void display(ogstream &gout);
};

