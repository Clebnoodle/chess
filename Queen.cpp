/***********************************************************************
 * Source File:
 *    Queen
 * Author:
 *    Braeden Pope, Caleb Nuttall
 * Summary:
 *    Represents a single queen piece
 ************************************************************************/

#include "queen.h"
#include "position.h"
#include <set>
using namespace std;

/******************************************
 * QUEEN : DISPLAY
 * Draws our queen in its location
 ******************************************/
void Queen::display(ogstream& gout) 
{
	gout.drawQueen(position.getLocation(), !isWhite());
}

/******************************************
 * QUEEN : GET MOVES
 * Gets the moves our queen can make
 ******************************************/
void Queen::getMoves(set<Move> &moves, Board &board) 
{
	Delta delta[8] =
	{
		{-1,  1}, { 0,  1}, { 1, 1}, 
		{-1,  0},           { 1,  0}, 
		{-1, -1}, { 0, -1}, { 1, -1}
	};

	getMovesSlide(moves, board, delta, sizeof(delta) / sizeof(delta[0]));
}