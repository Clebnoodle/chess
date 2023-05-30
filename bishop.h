/***********************************************************************
 * Header File:
 *    BISHOP: Bishop Piece
 *
 * Authors: Braeden Pope, Caleb Nuttall
 * 
 * Summary:
 *    Functions as the Bishop piece in the game of chess
 ************************************************************************/

#pragma once
#include "piece.h"
#include "board.h"


/// <summary>
/// 
/// CLASS: BISHOP
/// 
/// </summary>
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

