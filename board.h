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
   ogstream *gout;

public:
   //Board();
   Board(ogstream & gout);
   int getCurrentMove() { return currentMove; }
   //bool whiteTurn();
   //void display(Position posHover, Position posSelect);
   Piece get(Position pos);
   //void free();
   //void reset();
   //void move(Move move);
   //void assign(Move move);
   //void assertBoard();
   void swap(Position pos1, Position pos2);
   Piece& operator[](Position pos)
   {
      char location = pos.getLocation();
      return board[location];
   }
};


