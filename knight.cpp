/***********************************************************************
 * Source File:
 *    Knight
 * Author:
 *    Braeden Pope, Caleb Nuttall
 * Summary:
 *    Represents a single knight piece
 ************************************************************************/

#include "knight.h"
#include "position.h"
#include "piece.h"
#include <set>
using namespace std;

/******************************************
 * KNIGHT : DISPLAY
 * Draws our knight in its location
 ******************************************/
void Knight::display(ogstream& gout)
{
	gout.drawKnight(position.getLocation(), !isWhite());
}

/******************************************
 * KNIGHT : GET MOVES
 * Gets the moves our knight can make
 ******************************************/
void Knight::getMoves(set<Move>& moves, Board& board)
{
	Delta delta[8] =
	{
		      {2, -1},{2,  1},
		 
		{1, -2},            {1, 2},

	   {-1, -2},           {-1, 2},
		
				{-2, -1},{-2, 1}
	};

	getMovesNoSlide(moves, board, delta, sizeof(delta) / sizeof(delta[0]));
}