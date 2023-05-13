#pragma once
#include "piece.h"
class King :
    public Piece
{
public:
	King(int row, int col, bool isWhite)
	{
		this->position = Position(row, col);
		this->fWhite = isWhite;
	};
};

