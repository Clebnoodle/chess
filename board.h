#pragma once
#include "piece.h"
#include "uiDraw.h"
#include "position.h"
#include "move.h"
#include <cassert>


/***********************************************************************
 * Header File:
 *    BOARD: Chess Board
 *
 * Summary:
 *    Functions as chess board in a game of chess
 ************************************************************************/
class Board
{
private:
   Piece* board[64];
   int currentMove;
   ogstream *gout;

public:
   Board(ogstream & gout);
   int getCurrentMove() { return currentMove; }
   void setCurrentMove(int move) { currentMove = move; }
   bool whiteTurn()
   {
      if (currentMove % 2 == 1)
         return true;
      else
         return false;
   }
   void display(Position posHover, Position posSelect);
   Piece& get(Position pos);
   void move(Move move);
   void swap(Position pos1, Position pos2);
   void kill(Position pos);
   
   Piece& operator[](Position pos) const
   {
      char location = pos.getLocation();
      assert(pos.getRow() >= 0 && pos.getRow() <= 7);
      assert(pos.getColumn() >= 0 && pos.getColumn() <= 7);
      Piece* piece = board[location];
      return *piece;
   }
};


