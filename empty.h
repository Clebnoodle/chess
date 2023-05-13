#pragma once
#include "piece.h"
#include "board.h"
class Empty : public Piece
{
public:
	void getMoves(std::set<Move>& moves, Board board)
	{

	}
};

