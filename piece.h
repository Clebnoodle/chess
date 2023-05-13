#pragma once
#include "position.h"
#include "board.h"
#include <set>
#include <string>

class TestPawn;

class Piece
{
   friend TestPawn;
protected:
   Position position;
   bool fWhite;
   int nMoves;
   int lastMove;

public:
   Piece(int row, int col, bool isWhite);
   void assign(Position pos);
   void assign(Piece piece) { 
      this->fWhite = piece.fWhite; 
      this->nMoves = piece.nMoves;
      this->lastMove = lastMove;
   };
   bool isWhite() { return fWhite; };
   bool isMove();
   int getNMoves() { return nMoves; };
   Position getPosition() { return position; };
   bool justMoved()
   {
      if (lastMove != 0) {
         return true;
      }
      else {
         return false;
      }
   };
   virtual char getLetter();
   virtual void display();
   virtual void getMoves(std::set<Move> & moves, Board board);

};