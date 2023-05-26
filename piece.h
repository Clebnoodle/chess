#pragma once
#include "position.h"
#include "move.h"
#include <set>
#include <string>

class TestPawn;
class Board;

class Piece
{
   friend TestPawn;
protected:
   Position position;
   bool fWhite;
   int nMoves;
   int lastMove;

   void getMovesSlide(std::set<Move>& moves, Board& board, Delta delta[], int size);
   void getMovesNoSlide(std::set<Move>& moves, Board& board, Delta delta[], int size);

public:
   Piece() : fWhite(true), nMoves(0), lastMove(0) {}
   Piece(int row, int col, bool isWhite) : fWhite(isWhite), nMoves(0), lastMove(0) 
   {
      Position location = Position(row, col);
      this->position = location;
   }
   void assign(Position pos) { this->position = pos; };
   void assign(Piece piece) { 
      this->fWhite = piece.fWhite; 
      this->nMoves = piece.nMoves;
      this->lastMove = lastMove;
   };
   bool isWhite() { return fWhite; };
   bool hasMoved() { return nMoves != 0; }
   int getNMoves() { return nMoves; };
   Position getPosition() { return position; }
   void setPosition(Position pos) {

      position = pos;
   }
   bool justMoved(int currentMove)
   {
      if (lastMove == currentMove) {
         return true;
      }
      else {
         return false;
      }
   };
   virtual char getLetter() { return 'l'; }
   virtual void display(ogstream gout) {}
   virtual void getMoves(std::set<Move>& moves, Board &board);

};