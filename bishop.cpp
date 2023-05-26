#include "bishop.h"
#include "position.h"
#include "piece.h"
#include <set>
using namespace std;


void Bishop::display(ogstream gout)
{
	gout.drawBishop(position.getLocation(),isWhite());
}

void Bishop::getMoves(set<Move>& moves, Board& board)
{
	Delta delta[4] =
	{
		{-1,  1},           { 1, 1},
	
		{-1, -1},           { 1, -1}
	};

	getMovesSlide(moves, board, delta, sizeof(delta) / sizeof(delta[0]));
}