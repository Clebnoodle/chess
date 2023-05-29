#include "position.h"
#include "pawn.h"
#include "board.h"


using namespace std;

void Pawn::display(ogstream& gout)
{
	gout.drawPawn(position.getLocation(), !isWhite());
}

void Pawn::getMoves(set<Move>& moves, Board &board) 
{

	Position posMove = getPosition();
	posMove.adjustRow(isWhite() ? 1 : -1);
	Move move;

	if (posMove.isValid() && board[posMove].getLetter() == EMPTY)
	{
		move.setSrc(getPosition());
		move.setDest(posMove);
		move.setWhiteMove(isWhite());

		if (posMove.getRow() == 7 || posMove.getRow() == 0)
		{
			move.setPromotion(QUEEN);
		}
		moves.insert(move);
	}
	if (!this->hasMoved())
	{
		posMove = Position(isWhite() ? 3 : 4, getPosition().getColumn());
		Position posCheck = Position(isWhite() ? 2 : 5, getPosition().getColumn());

		if (board[posMove].getLetter() == EMPTY && board[posCheck].getLetter() == EMPTY)
		{
			move.setSrc(getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			moves.insert(move);
		}
	}

	for (int col = -1; col <= 1; col += 2) 
	{
		posMove = Position(position.getRow() + (isWhite() ? 1 : -1), position.getColumn() + col);
		if (posMove.isValid() && board[posMove].getLetter() != EMPTY && board[posMove].isWhite() != isWhite())
		{
			move.setSrc(this->getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			move.setCapture(board[posMove].getLetter());
			if (posMove.getRow() == 7 || posMove.getRow() == 0)
			{
				move.setPromotion(QUEEN);
			}
			moves.insert(move);
		}
	}

	for (int col = -1; col <= 1; col += 2)
	{
		posMove = Position(position.getRow() + (isWhite() ? 1 : -1), position.getColumn() + col);
		Position posKill = Position(position.getRow(), position.getColumn() + col);
		if (posMove.isValid() &&
			position.getRow() == (isWhite() ? 4 : 3) &&
			board[posMove].getLetter() == EMPTY &&
			board[posKill].getLetter() == PAWN &&
			board[posKill].isWhite() != isWhite() &&
			board[posKill].getNMoves() == 1 &&
			board[posKill].justMoved(board.getCurrentMove())) 
		{
			move.setSrc(this->getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			move.setCapture(board[posMove].getLetter());
			move.setEnPassant();
			moves.insert(move);
		}
	}
}