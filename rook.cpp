#include "rook.h"
#include "position.h"
#include "piece.h"
#include <set>
using namespace std;


void Rook::display(ogstream& gout)
{
	gout.drawRook(position.getLocation(), !isWhite());
}

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