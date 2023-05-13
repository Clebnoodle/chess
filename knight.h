#pragma once
#include "piece.h"
class Knight :
    public Piece
{
public:
	Knight(int row, int col, bool isWhite)
	{
		this->position = Position(row, col);
		this->fWhite = isWhite;
	};
};

