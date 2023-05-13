#pragma once

#include "piece.h"
#include "position.h"

class Queen : public Piece
{
public:
	Queen(int row, int col, bool isWhite)
	{
		this->position = Position(row, col);
		this->fWhite = isWhite;
	};
};