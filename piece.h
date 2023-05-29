#pragma once
#include "position.h"
#include "move.h"
#include "uiDraw.h"
#include <set>
#include <string>
#include "pieceType.h"

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
   Piece() : fWhite(true), nMoves(0), lastMove(-1) {}
   Piece(int row, int col, bool isWhite) : fWhite(isWhite), nMoves(0), lastMove(-1) 
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
      if (lastMove == currentMove - 1) {
         return true;
      }
      else {
         return false;
      }
   };
   virtual PieceType getLetter() { return EMPTY; };
   virtual void display(ogstream gout) {}
   virtual void getMoves(std::set<Move>& moves, Board &board);

};