/***********************************************************************
 * Header File:
 *    ROOK: Rook Piece
 *
 * Summary:
 *    Functions as the Rook piece in the game of chess
 ************************************************************************/
#pragma once
#include "piece.h"
#include "position.h"
#include "board.h"


/// <summary>
/// 
/// CLASS: ROOK
/// 
/// </summary>
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
	PieceType getLetter() { return ROOK; }
	void display(ogstream &gout);
};

