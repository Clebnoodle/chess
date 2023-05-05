#pragma once
#include "piece.h"
#include "uiDraw.h"
#include "position.h"

class Board
{
private:
   Piece board[64];
   int currentMove;
   ogstream gout;

public:
   Board(ogstream & gout);
   void swap(Position pos1, Position pos2);
   Piece& operator[](Position index);

};

