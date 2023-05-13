#pragma once
#include "pawn.h"
#include "position.h"
#include "board.h"
#include "uiDraw.h"
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
      test_queen_noMoves();

      test_queen_upOnce();
      test_queen_rightUpOnce();
      test_queen_rightOnce();
      test_queen_leftOnce();
      test_queen_leftUpOnce();
      
      test_queen_straightUp();
      test_queen_rightUp();
      test_queen_straightRight();
      test_queen_straightLeft();
      test_queen_leftUp();

      test_queen_downOnce();
      test_queen_downRightOnce();
      test_queen_downLeftOnce();

      test_queen_down();
      test_queen_downRight();
      test_queen_downLeft();

      test_queen_takeUp();
      test_queen_takeDown();

   }

private:
   /****************************
   * GET MOVES NO MOVES
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P P P P P P   7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3                     3
   * 2   p p p p p p p p   2
   * 1   r n b(q)k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_noMoves()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d1");
      //board.swap(Position("b2"), pos);

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 0);
   }  // teardown

   /****************************
   * GET MOVES UP ONCE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P P P P P P   7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3         p           3
   * 2   p p p . p p p p   2
   * 1   r n b(q)k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_upOnce()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d1");
      board.swap(Position("d2"), Position("d3"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 1);
   }  // teardown

   /****************************
   * GET MOVES RIGHT ONCE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P P P P P P   7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3           p         3
   * 2   p p p p k p p p   2
   * 1   r n b(q). b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_rightOnce()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d1");
      board.swap(Position("e2"), Position("e3"));
      board.swap(Position("e1"), Position("e2"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 1);
   }  // teardown

   /****************************
   * GET MOVES LEFT ONCE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P P P P P P   7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3       b             3
   * 2   p p p p p p p p   2
   * 1   r n .(q)k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_leftOnce()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d1"); 
      board.swap(Position("c1"), Position("c3"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 1);
   }  // teardown

   /****************************
   * GET MOVES DIAGONAL RIGHT UP ONCE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P P P P P P   7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3           p p       3
   * 2   p p p p .   p p   2
   * 1   r n b(q)k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_rightUpOnce()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d1");
      board.swap(Position("e2"), Position("e3"));
      board.swap(Position("f2"), Position("f3"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 1);
   }  // teardown

   /****************************
   * GET MOVES DIAGONAL LEFT UP ONCE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P P P P P P   7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3     p p             3
   * 2   p   . p p p p p   2
   * 1   r n b(q)k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_leftUpOnce()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d1");
      board.swap(Position("c2"), Position("c3"));
      board.swap(Position("b2"), Position("b3"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 1);
   }  // teardown

   /****************************
   * GET MOVES DIAGONAL RIGHT UP
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P P P P P P   7
   * 6                     6
   * 5                 .   5
   * 4               .     4
   * 3           p .       3
   * 2   p p p p . p p p   2
   * 1   r n b(q)k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_rightUp()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d1");
      board.swap(Position("e2"), Position("e3"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 4);
   }  // teardown

   /****************************
   * GET MOVES STRAIGHT UP
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P P P P P P   7
   * 6         p           6
   * 5         .           5
   * 4         .           4
   * 3         .           3
   * 2   p p p . p p p p   2
   * 1   r n b(q)k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_straightUp()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d1");
      board.swap(Position("d2"), Position("d6"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 4);
   }  // teardown

   /****************************
   * GET MOVES STRAIGHT LEFT
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P P P P P P   7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3   r n b             3
   * 2   p p p p p p p p   2
   * 1   . . .(q)k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_straightLeft()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d1");
      board.swap(Position("a1"), Position("a3"));
      board.swap(Position("b1"), Position("b3"));
      board.swap(Position("c1"), Position("c3"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 3);
   }  // teardown

   /****************************
   * GET MOVES STRAIGHT RIGHT
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P P P P P P   7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3           k b n r   3
   * 2   p p p p p p p p   2
   * 1   r n b(q). . . .   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_straightRight()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d1");
      board.swap(Position("e1"), Position("e3"));
      board.swap(Position("f1"), Position("f3"));
      board.swap(Position("g1"), Position("g3"));
      board.swap(Position("h1"), Position("h3"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 4);
   }  // teardown

   /****************************
   * GET MOVES DIAGONAL LEFT UP
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7   P P P P P P P P   7
   * 6                     6
   * 5                     5
   * 4   .                 4
   * 3     . p             3
   * 2   p p . p p p p p   2
   * 1   r n b(q)k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_leftUp()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d1");
      board.swap(Position("c2"), Position("c3"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 3);
   }  // teardown

   /****************************
   * GET MOVES DOWN ONCE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B(Q)K B N R   8
   * 7   P P P . P P P P   7
   * 6         P           6
   * 5                     5
   * 4                     4
   * 3                     3
   * 2   p p p p p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_downOnce()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d8");
      board.swap(Position("d7"), Position("d6"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 1);
   }  // teardown

   /****************************
   * GET MOVES DOWN
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B(Q)K B N R   8
   * 7   P P P . P P P P   7
   * 6         .           6
   * 5         .           5
   * 4         .           4
   * 3         P           3
   * 2   p p p p p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_down()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d8");
      board.swap(Position("d7"), Position("d3"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 4);
   }  // teardown

   /****************************
   * GET MOVES DIAGONAL DOWN RIGHT ONCE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B(Q)K B N R   8
   * 7   P P P P .   P P   7
   * 6           P P       6
   * 5                     5
   * 4                     4
   * 3                     3
   * 2   p p p p p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_downRightOnce()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d8");
      board.swap(Position("e7"), Position("e6"));
      board.swap(Position("f7"), Position("f6"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 1);
   }  // teardown

   /****************************
   * GET MOVES DIAGONAL DOWN RIGHT
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B(Q)K B N R   8
   * 7   P P P P . P P P   7
   * 6           P .       6
   * 5               .     5
   * 4                 .   4
   * 3                     3
   * 2   p p p p p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_downRight()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d8");
      board.swap(Position("e7"), Position("e6"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 4);
   }  // teardown

   /****************************
   * GET MOVES DIAGONAL DOWN LEFT ONCE
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B(Q)K B N R   8
   * 7   P   . P P P P P   7
   * 6     P P             6
   * 5                     5
   * 4                     4
   * 3                     3
   * 2   p p p p p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_downLeftOnce()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d8");
      board.swap(Position("c7"), Position("c6"));
      board.swap(Position("b7"), Position("b6"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 1);
   }  // teardown

   /****************************
   * GET MOVES DIAGONAL DOWN LEFT
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B(Q)K B N R   8
   * 7   P P . P P P P P   7
   * 6     . P             6
   * 5   .                 5
   * 4                     4
   * 3                     3
   * 2   p p p p p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_downLeft()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d8");
      board.swap(Position("c7"), Position("c6"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 3);
   }  // teardown

   /****************************
   * GET MOVES TAKE UP
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B Q K B N R   8
   * 7     P P P P P P     7
   * 6       . . .         6
   * 5   P . .(q). . . P   5
   * 4       . . .         4
   * 3     .   .   .       3
   * 2   p p p p p p p p   2
   * 1   r n b   k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_takeUp()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d5");
      board.swap(Position("d1"), pos);
      board.swap(Position("a7"), Position("a5"));
      board.swap(Position("h7"), Position("h5"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 19);

      Move move;

      move = "d5a5p";
      it = moves.find(move);
      assert(it != moves.end());

      move = "d5h5p";
      it = moves.find(move);
      assert(it != moves.end());

      move = "d5d7p";
      it = moves.find(move);
      assert(it != moves.end());

      move = "d5b7p";
      it = moves.find(move);
      assert(it != moves.end());

      move = "d5f7p";
      it = moves.find(move);
      assert(it != moves.end());

   }  // teardown

   /****************************
   * GET MOVES TAKE DOWN
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8   R N B   K B N R   8
   * 7   P P P P P P P P   7
   * 6       . . .         6
   * 5   . . .(Q). . . .   5
   * 4       . . .         4
   * 3     .   .   .       3
   * 2   p p p p p p p p   2
   * 1   r n b q k b n r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ****************************/
   void test_queen_takeDown()
   {
      // setup
      ogstream gout;
      Board board(gout);
      Position pos("d5");
      board.swap(Position("d1"), pos);
      board.swap(Position("a7"), Position("a5"));
      board.swap(Position("h7"), Position("h5"));

      // exercise
      set<Move> moves;
      board[pos].getMoves(moves, board);

      // verify
      set<Move>::iterator it;
      assert(moves.size() == 19);

      Move move;

      move = "d5a2p";
      it = moves.find(move);
      assert(it != moves.end());
   
      move = "d5d2p";
      it = moves.find(move);
      assert(it != moves.end());

      move = "d5g2p";
      it = moves.find(move);
      assert(it != moves.end());
   }  // teardown
};