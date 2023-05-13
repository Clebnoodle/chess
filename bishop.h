#pragma once
#include "piece.h"
class Bishop :
    public Piece
{
public:
	Bishop(int row, int col, bool isWhite)
	{
		this->position = Position(row, col);
		this->fWhite = isWhite;
	};
};

