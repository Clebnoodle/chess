#include "queen.h"
#include "position.h"
#include <set>
using namespace std;


void Queen::display(ogstream gout) 
{
	gout.drawQueen(position.getLocation(), isWhite());
}

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