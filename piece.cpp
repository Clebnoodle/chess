/***********************************************************************
 * Source File:
 *    Piece
 * Author:
 *    Braeden Pope, Caleb Nuttall
 * Summary:
 *    Represents a single piece
 ************************************************************************/

#include "piece.h"
#include "board.h"

/******************************************
 * PIECE : GET MOVES
 * No piece = no moves
 ******************************************/
void Piece::getMoves(std::set<Move>& moves, Board& board)
{

}

/******************************************
 * PIECE : GET MOVES SLIDE
 * Used get the moves for our sliding pieces
 ******************************************/
void Piece::getMovesSlide(std::set<Move>& moves, Board& board, Delta delta[], int size)
{
	for (int i = 0; i < size; i++)
	{
		Delta test = delta[i];
		Position posMove = Position(getPosition());
		posMove.adjustCol(test.col);
		posMove.adjustRow(test.row);
		while (posMove.isValid() && board[posMove].getLetter() == EMPTY)
		{
			Move move;
			move.setSrc(getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			moves.insert(move);
			posMove.adjustCol(delta[i].col);
			posMove.adjustRow(delta[i].row);
		}
		if (posMove.isValid() && (board[posMove].isWhite() != fWhite || board[posMove].getLetter() == EMPTY))
		{
			Move move;
			move.setSrc(getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			if (board[posMove].getLetter() != EMPTY)
			{
				move.setCapture(board[posMove].getLetter());
			}
			moves.insert(move);
		}
	}
}

/******************************************
 * PIECE : GET MOVES SLIDE
 * Used get the moves for our non-sliding pieces
 ******************************************/
void Piece::getMovesNoSlide(std::set<Move>& moves, Board& board, Delta delta[], int size)
{
	for (int i = 0; i < size; i++)
	{
		Delta test = delta[i];
		Position posMove = Position(getPosition());
		posMove.adjustCol(test.col);
		posMove.adjustRow(test.row);
		if (posMove.isValid() && (board[posMove].isWhite() != fWhite || board[posMove].getLetter() == EMPTY))
		{
			Move move;
			move.setSrc(getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			if (board[posMove].getLetter() != EMPTY)
			{
				move.setCapture(board[posMove].getLetter());
			}
			moves.insert(move);
		}

	}
}