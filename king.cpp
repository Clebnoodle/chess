#include "king.h"
#include "position.h"
#include "piece.h"
#include <set>
using namespace std;


void King::display(ogstream& gout)
{
	gout.drawKing(position.getLocation(), !isWhite());
}

void King::getMoves(set<Move>& moves, Board& board)
{
	Delta delta[8] =
	{
		{-1,  1}, { 0,  1}, { 1, 1},
		{-1,  0},           { 1,  0},
		{-1, -1}, { 0, -1}, { 1, -1}
	};

	getMovesNoSlide(moves, board, delta, sizeof(delta) / sizeof(delta[0]));

	if (!hasMoved()) 
	{
		Position posSpace = Position(position.getRow(), 5);
		Position posMove = Position(position.getRow(), 6);
		Position posRook = Position(position.getRow(), 7);

		if (board[posSpace].getLetter() == EMPTY && board[posMove].getLetter() == EMPTY &&
			board[posRook].getLetter() == ROOK && !board[posRook].hasMoved())
		{
			Move move;
			move.setSrc(getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			move.setCastle(true);
			moves.insert(move);
		}
	}

	if (!hasMoved())
	{
		Position posSpace1 = Position(position.getRow(), 3);
		Position posMove = Position(position.getRow(), 2);
		Position posSpace2 = Position(position.getRow(), 1);
		Position posRook = Position(position.getRow(), 0);
		

		if (board[posSpace1].getLetter() == EMPTY && board[posSpace2].getLetter() == EMPTY && 
			board[posMove].getLetter() == EMPTY && board[posRook].getLetter() == ROOK && !board[posRook].hasMoved())
		{
			Move move;
			move.setSrc(getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			move.setCastle(false);
			moves.insert(move);
		}
	}
}