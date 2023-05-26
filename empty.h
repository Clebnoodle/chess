#pragma once
#include "piece.h"
#include "board.h"
class Empty : public Piece
{
public:
	Empty(char location)
	{
		this->position.setIndex(location);
	}
	void getMoves(std::set<Move>& moves, Board board);

	char getLetter() { return ' '; }
};

