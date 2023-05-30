#pragma once
#include "piece.h"
#include "board.h"

/***********************************************************************
 * Header File:
 *    KING: King Piece
 *
 * Summary:
 *    Functions as the King piece in the game of chess
 ************************************************************************/
class King :
    public Piece
{
public:
	King(int row, int col, bool isWhite)
	{
		this->position = Position(row, col);
		this->fWhite = isWhite;
	}

	void getMoves(std::set<Move>& moves, Board& board);
	PieceType getLetter() { return KING; }
	void display(ogstream &gout);
};

