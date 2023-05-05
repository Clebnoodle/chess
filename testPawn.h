#pragma once
#include "pawn.h"
#include "position.h"
#include "board.h"
#include "uiDraw.h"
#include <set>
#include <cassert>
#include "move.h"
using namespace std;

#define PAWN_JUMP 1
#define ADVANCE   2
#define NOTHING   0

class Pawn;

class TestPawn
{
public:
   void run()
   {
      test_pawn_enPassant();
   }

private:
   /****************************
   * GET MOVES WHITE EN PASSANT
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7         P P P P P   7
   * 6   . P .             6
   * 5   P(p)P             5
   * 4                     4
   * 3                     3
   * 2   p   p p p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_pawn_enPassant()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("b5");
      board.swap(Position("b2"), pos);
      board.swap(Position("a7"), Position("a5"));
      board.swap(Position("b7"), Position("b6"));
      board.swap(Position("c7"), Position("c5"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 2);
   }
};