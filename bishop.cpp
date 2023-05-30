/***********************************************************************
 * Source File:
 *    Bishop
 * Author:
 *    Braeden Pope, Caleb Nuttall
 * Summary:
 *    Represents a single bishop piece
 ************************************************************************/

#include "bishop.h"
#include "position.h"
#include "piece.h"
#include <set>
using namespace std;

/******************************************
 * BISHOP : DISPLAY
 * Draws our bishop in its location
 ******************************************/
void Bishop::display(ogstream& gout)
{
	gout.drawBishop(position.getLocation(), !isWhite());
}

/******************************************
 * BISHOP : GET MOVES
 * Gets the moves our bishop can make
 ******************************************/
void Bishop::getMoves(set<Move>& moves, Board& board)
{
	Delta delta[4] =
	{
		{-1,  1},           { 1, 1},
	
		{-1, -1},           { 1, -1}
	};

	getMovesSlide(moves, board, delta, sizeof(delta) / sizeof(delta[0]));
}