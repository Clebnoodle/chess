#include "board.h"
#include "piece.h"
#include "pawn.h"
#include "empty.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

using namespace std;

Board::Board(ogstream& gout)
{
	this->gout = &gout;
	this->currentMove = 0;
	//Piece board[64];
	for (int i = 8; i < 16; i++)
	{
		board[i] = new Pawn(1, i - 8, true);
	}

	for (int j = 48; j < 56; j++)
	{
		
		board[j] = new Pawn(6, j - 8, false);
	}
	for (int k = 16; k < 48; k++)
	{
		
		board[k] = new Empty();
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