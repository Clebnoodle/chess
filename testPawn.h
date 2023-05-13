#pragma once
#include "pawn.h"
#include "position.h"
#include "board.h"
#include "uiDraw.h"
#include <string>
#include <set>
#include <cassert>
#include "move.h"
using namespace std;

class Pawn;

class TestPawn
{
public:
   void run()
   {
      test_pawn_whiteEnPassant();
      test_pawn_blackEnPassant();

      test_pawn_moveUpOnce();
      test_pawn_moveUpTwice();
      
      test_pawn_moveDownOnce();
      test_pawn_moveDownTwice();
      
      test_pawn_whiteNoMoves();
      test_pawn_blackNoMoves();
      
      test_pawn_whiteTake();
      test_pawn_blackTake();
      
      test_pawn_promotion();
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
   void test_pawn_whiteEnPassant()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("b5");
      board.swap(Position("b2"), pos);
      board.swap(Position("a7"), Position("a5"));
      board.swap(Position("b7"), Position("b6"));
      board.swap(Position("c7"), Position("c5"));
      Position blackPawn1("a5");
      Position blackPawn2("c5");
      board[blackPawn1].lastMove = 1;
      board[blackPawn2].lastMove = 1;

      cout << board[pos].getLetter() << endl;

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 2);

      Move move;

      move = "b5a6E";
      it = moves.find(move);
      assert(it != moves.end());

      move = "b5c6E";
      it = moves.find(move);
      assert(it != moves.end());
      //teardown
   }

   

   /****************************
   * GET MOVES BLACK EN PASSANT
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P P   P P P   7
   * 6                     6
   * 5                     5
   * 4         p(P)p       4
   * 3         . p .       3
   * 2   p p p       p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_pawn_blackEnPassant()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("e4");
      board.swap(Position("e7"), pos);
      board.swap(Position("d2"), Position("d4"));
      board.swap(Position("e2"), Position("e3"));
      board.swap(Position("f2"), Position("f4"));
      Position blackPawn1("d4");
      Position blackPawn2("f4");
      board[blackPawn1].lastMove = 1;
      board[blackPawn2].lastMove = 1;

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 2);

      Move move;

      move = "e4d3E";
      it = moves.find(move);
      assert(it != moves.end());

      move = "e4f3E";
      it = moves.find(move);
      assert(it != moves.end());
      //teardown
   }

   /****************************
   * GET MOVES WHITE UP ONCE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P P P P P P   7
   * 6                     6
   * 5     .               5
   * 4    (p)              4
   * 3                     3
   * 2   p   p p p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_pawn_moveUpOnce()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("b4");
      board.swap(Position("b2"), pos);
      board[pos].lastMove = 1;

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 1);

      // teardown

   }

   /****************************
   * GET MOVES WHITE UP TWICE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P P P P P P   7
   * 6                     6
   * 5                     5
   * 4     .               4
   * 3     .               3
   * 2   p(p)p p p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_pawn_moveUpTwice()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("b2");

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 2);
      // teardown
   }

   /****************************
   * GET MOVES BLACK DOWN ONCE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7     P P P P P P P   7
   * 6                     6
   * 5  (P)                5
   * 4   .                 4
   * 3                     3
   * 2   p p p p p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_pawn_moveDownOnce()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("a5");
      board.swap(Position("a7"), pos);
      board[pos].lastMove = 1;

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 1);
      // teardown
   }

   /****************************
   * GET MOVES BLACK DOWN TWICE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7  (P)P P P P P P P   7
   * 6   .                 6
   * 5   .                 5
   * 4                     4
   * 3                     3
   * 2   p p p p p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_pawn_moveDownTwice()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("a7");

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 2);
      // teardown
   }

   /****************************
   * GET MOVES WHITE NO MOVE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P   P P P P   7
   * 6                     6
   * 5         P           5
   * 4        (p)          4
   * 3                     3
   * 2   p p p   p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_pawn_whiteNoMoves()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d4");
      board.swap(Position("d2"), pos);
      board.swap(Position("d7"), Position("d5"));


      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 0);
      // teardown
   }

   /****************************
   * GET MOVES BLACK NO MOVE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P   P P P P   7
   * 6                     6
   * 5        (P)          5
   * 4         p           4
   * 3                     3
   * 2   p p p   p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_pawn_blackNoMoves()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d5");
      board.swap(Position("d7"), pos);
      board.swap(Position("d2"), Position("d4"));


      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 0);
      // teardown
   }

   /****************************
   * GET MOVES BLACK TAKE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P   P P P P   7
   * 6                     6
   * 5        (P)          5
   * 4       p p p         4
   * 3                     3
   * 2   p p       p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_pawn_blackTake()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d5");
      board.swap(Position("d7"), pos);
      board.swap(Position("d2"), Position("d4"));
      board.swap(Position("c2"), Position("c4"));
      board.swap(Position("e2"), Position("e4"));


      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 2);
      
      Move move;

      move = "d5c4p";
      it = moves.find(move);
      assert(it != moves.end());

      move = "d5e4p";
      it = moves.find(move);
      assert(it != moves.end());
      // teardown

   }

   /****************************
   * GET MOVES WHITE TAKE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P       P P P   7
   * 6                     6
   * 5       P P P         5
   * 4        (p)          4
   * 3                     3
   * 2   p p p   p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_pawn_whiteTake()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d4");
      board.swap(Position("d2"), pos);
      board.swap(Position("d7"), Position("d5"));
      board.swap(Position("c7"), Position("c5"));
      board.swap(Position("e7"), Position("e5"));


      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 2);

      Move move;

      move = "d4c5p";
      it = moves.find(move);
      assert(it != moves.end());

      move = "d4e5p";
      it = moves.find(move);
      assert(it != moves.end());
      // teardown
   }

   /****************************
   * GET MOVES PAWN PROMOTION
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N   .   B N R   8
   * 7   P P P(p)P P P P   7
   * 6       B Q K         6
   * 5                     5
   * 4                     4
   * 3                     3
   * 2   p p p P p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_pawn_promotion()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d7");
      board.swap(Position("d2"), pos);
      board.swap(Position("d8"), Position("d6"));
      board.swap(Position("c8"), Position("c6"));
      board.swap(Position("e8"), Position("e6"));


      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 1);

      Move move;

      move = "d7d8Q";
      it = moves.find(move);
      assert(it != moves.end());
      // teardown
   }

};