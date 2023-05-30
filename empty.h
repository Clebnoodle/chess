#pragma once
#include "piece.h"
#include "board.h"

/***********************************************************************
 * Header File:
 *    EMPTY: Empty space
 *
 * Summary:
 *    Represents an empty space on a chess board
 ************************************************************************/
class Empty : public Piece
{
public:
	Empty(char location)
	{
		this->position.setIndex(location);
	}
	void getMoves(std::set<Move>& moves, Board board);

	PieceType getLetter() { return EMPTY; }
};

