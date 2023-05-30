/***********************************************************************
 * Header File:
 *    PAWN: Pawn Piece
 *
 * Authors: Braeden Pope, Caleb Nuttall
 * 
 * Summary:
 *    Functions as a pawn in a chess game
 ************************************************************************/
#pragma once

#include "piece.h"
#include "position.h"
#include <set>


/// <summary>
/// 
/// CLASS: PAWN
/// 
/// </summary>
class Pawn : public Piece
{
public:
	Pawn(int row, int col, bool isWhite)
	{
		this->position = Position(row, col);
		this->fWhite = isWhite;
	};
	void getMoves(std::set<Move> &moves, Board &board);

	PieceType getLetter() {	return PAWN; }
	void display(ogstream& gout);
};