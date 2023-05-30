/***********************************************************************
 * Header File:
 *    KNIGHT: Knight Piece
 *
 * Authors: Braeden Pope, Caleb Nuttall
 * 
 * Summary:
 *    Functions as a Knight Piece in a chess game.
 ************************************************************************/

#pragma once
#include "piece.h"
#include "board.h"


/// <summary>
/// 
/// CLASS: KNIGHT
/// 
/// </summary>
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

