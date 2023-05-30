/***********************************************************************
 * Source File:
 *    Rook
 * Author:
 *    Braeden Pope, Caleb Nuttall
 * Summary:
 *    Represents a single rook piece
 ************************************************************************/

#include "rook.h"
#include "position.h"
#include "piece.h"
#include <set>
using namespace std;

/******************************************
 * ROOK : DISPLAY
 * Draws our rook in its location
 ******************************************/
void Rook::display(ogstream& gout)
{
	gout.drawRook(position.getLocation(), !isWhite());
}

/******************************************
 * ROOK : GET MOVES
 * Gets the moves our rook can make
 ******************************************/
void Rook::getMoves(set<Move>& moves, Board& board)
{
	Delta delta[4] =
	{
					 {1,  0},
		 { 0, -1},       {0, 1},
					{ -1, 0} 
	};

	getMovesSlide(moves, board, delta, sizeof(delta) / sizeof(delta[0]));
}