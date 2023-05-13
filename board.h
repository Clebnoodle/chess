#pragma once
#include "piece.h"
#include "uiDraw.h"
#include "position.h"
#include "move.h"

class Board
{
private:
   Piece board[64];
   int currentMove;
   ogstream gout;
   void swap(Position pos1, Position pos2);

public:
   Board(ogstream & gout);
   int getCurrentMove();
   bool whiteTUrn();
   void display(Position posHover, Position posSelect);
   Piece get(Position pos);
   void free();
   void reset();
   void move(Move move);
   void assign(Move move);
   void assertBoard();
   Piece& operator[](Position index);

};

