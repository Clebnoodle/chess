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
   virtual void getMoves(std::set<Move> & moves, Board board);
};