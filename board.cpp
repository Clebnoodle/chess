#include "board.h"
#include "piece.h"
#include "pawn.h"
#include "empty.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <iostream>

using namespace std;

Board::Board(ogstream& gout)
{
	this->gout = &gout;
	this->currentMove = 1;
	//Piece board[64];
	for (int i = 8; i < 16; i++)
	{
		board[i] = new Pawn(1, i - 8, true);
	}

	for (int j = 48; j < 56; j++)
	{
		board[j] = new Pawn(6, j - 48, false);
	}

	for (int k = 16; k < 48; k++)
	{
		board[k] = new Empty(k);
	}
	
	board[0] = new Rook(0, 0, true);
	
	board[1] = new Knight(0, 1, true);
	
	board[2] = new Bishop(0, 2, true);

	board[3] = new Queen(0, 3, true);

	board[4] = new King(0, 4, true);

	board[5] = new Bishop(0, 5, true);

	board[6] = new Knight(0, 6, true);

	board[7] = new Rook(0, 7, true);

	board[56] = new Rook(7, 0, false);

	board[57] = new Knight(7, 1, false);

	board[58] = new Bishop(7, 2, false);

	board[59] = new Queen(7, 3, false);

	board[60] = new King(7, 4, false);

	board[61] = new Bishop(7, 5, false);

	board[62] = new Knight(7, 6, false);

	board[63] = new Rook(7, 7, false);

}

void Board::display(Position posHover, Position posSelect)
{
	gout->drawBoard();
	gout->drawHover(posHover.getLocation());
	gout->drawSelected(posSelect.getLocation());

	if (posSelect.isValid())
	{
		set<Move> possible;
		board[posSelect.getLocation()]->getMoves(possible, *this);
		set<Move>::iterator it = possible.begin();
		for (it; it != possible.end(); it++)
		{
			Move move = *it;
			gout->drawPossible(move.getDest().getLocation());
		}
	}

	for (int i = 0; i < 64; i++)
	{
		board[i]->display(*gout);
	}
}

Piece& Board::get(Position pos) 
{
	char location = pos.getLocation();
	return *board[location];
}

void Board::swap(Position pos1, Position pos2)
{
	char start = pos1.getLocation();
	char end = pos2.getLocation();
	Piece* temp = &this->get(pos1);

	board[start] = &this->get(pos2);
	board[start]->setPosition(pos1);

	board[end] = temp;
	board[end]->setPosition(pos2);
}

void Board::kill(Position pos)
{
	board[pos.getLocation()] = new Empty(pos.getLocation());
}

void Board::move(Move move)
{
	string moveString = move.getText();

	string::const_iterator it = moveString.cbegin();

	// get the source
	Position source = move.getSrc();

	// get the destination
	Position dest = move.getDest();

	swap(source, dest);
	if (move.getEnPassant())
	{
		dest.adjustRow(move.getWhiteMove() ? -1 : 1);
		kill(dest);
	}
	else if (move.getCastleK())
	{
		Position rookPos(dest.getRow(), 7);
		swap(rookPos, Position(rookPos.getRow(), 5));
	}
	else if (move.getCastleQ())
	{
		Position rookPos(dest.getRow(), 0);
		swap(rookPos, Position(rookPos.getRow(), 3));
	}
	else if (move.getCapture() != EMPTY)
	{
		kill(source);
	}

	if (move.getPromotion() != EMPTY)
	{
		board[dest.getLocation()] = new Queen(dest, move.getWhiteMove());
	}

	board[dest.getLocation()]->move(currentMove);
	currentMove++;
	
}