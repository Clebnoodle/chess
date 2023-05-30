#pragma once
#include "position.h"
#include "move.h"
#include "uiDraw.h"
#include <set>
#include <string>
#include "pieceType.h"

class TestPawn;
class Board;


/***********************************************************************
 * Header File:
 *    PIECE: Chess Piece
 *
 * Summary:
 *    Functions as a piece in the game of chess
 ************************************************************************/
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
   
   //Constructors
   Piece() : fWhite(true), nMoves(0), lastMove(-1) {}
   Piece(int row, int col, bool isWhite) : fWhite(isWhite), nMoves(0), lastMove(-1) 
   {
      Position location = Position(row, col);
      this->position = location;
   }

   //Setters
   void assign(Position pos) { this->position = pos; };
   void assign(Piece piece) { 
      this->fWhite = piece.fWhite; 
      this->nMoves = piece.nMoves;
      this->lastMove = lastMove;
   };
   void setPosition(Position pos) {

      position = pos;
   }

   //Getters
   bool isWhite() { return fWhite; };
   bool hasMoved() { return nMoves != 0; }
   int getNMoves() { return nMoves; };
   Position getPosition() { return position; }

   //Modifier
   void move(int currentMove)
   {
      lastMove = currentMove;
      nMoves++;
   }

   //Identifier
   bool justMoved(int currentMove)
   {
      if (lastMove == currentMove - 1) {
         return true;
      }
      else {
         return false;
      }
   };
   
   //Virtual Functions
   virtual PieceType getLetter() { return EMPTY; };
   virtual void display(ogstream &gout) {}
   virtual void getMoves(std::set<Move>& moves, Board &board);

};