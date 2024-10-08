/***********************************************************************
 * Header File:
 *    EMPTY: Empty space
 *
 * Authors: Braeden Pope, Caleb Nuttall
 * 
 * Summary:
 *    Represents an empty space on a chess board
 ************************************************************************/

#pragma once
#include "piece.h"
#include "board.h"

/// <summary>
/// 
/// CLASS: EMPTY
/// 
/// </summary>
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

