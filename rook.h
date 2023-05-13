#pragma once
#include "piece.h"
#include "position.h"
class Rook :
    public Piece
{
public:
	Rook(int row, int col, bool isWhite)
	{
		this->position = Position(row, col);
		this->fWhite = isWhite;
	};
};

