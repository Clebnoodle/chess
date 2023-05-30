#pragma once
#include "piece.h"
#include "board.h"


/***********************************************************************
 * Header File:
 *    BISHOP: Bishop Piece
 *
 * Summary:
 *    Functions as the Bishop piece in the game of chess
 ************************************************************************/
class Bishop :
    public Piece
{
public:
	Bishop(int row, int col, bool isWhite)
	{
		this->position = Position(row, col);
		this->fWhite = isWhite;
	}

	void getMoves(std::set<Move>& moves, Board& board);
	PieceType getLetter() { return BISHOP; }
	void display(ogstream &gout);
};

