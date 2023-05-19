#include "queen.h"
#include "position.h"
#include <set>
using namespace std;

struct Delta
{
	int row;
	int col;
};


void Queen::getMoves(set<Move> &moves, Board &board) 
{
	Delta delta[8] =
	{
		(-1,1), (0,1), (1,1), (-1,0), (1,0), (-1,-1), (0,-1), (1,-1)
	};
	for (int i = 0; i < sizeof(delta) / sizeof(delta[0]); i++)
	{
		
		Position posMove = Position(getPosition());
		posMove.adjustCol(delta[i].col);
		posMove.adjustRow(delta[i].row);
		while (posMove.isValid() && board[posMove].getLetter() == ' ')
		{
			Move move;
			move.setSrc(getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			moves.insert(move);
			posMove.adjustCol(delta[i].col);
			posMove.adjustRow(delta[i].row);
		}
		if (posMove.isValid() && (board[posMove].isWhite() != fWhite || board[posMove].getLetter() == ' ')) 
		{
			Move move;
			move.setSrc(getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			if (board[posMove].getLetter() != ' ')
			{
				move.setCapture(board[posMove].getLetter());
			}
			moves.insert(move);
		}
	}
}