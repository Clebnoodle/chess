#include "knight.h"
#include "position.h"
#include "piece.h"
#include <set>
using namespace std;


void Knight::display(ogstream gout)
{
	gout.drawKnight(position.getLocation(), isWhite());
}

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