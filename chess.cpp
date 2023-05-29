// chess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "testPawn.h"
#include "testQueen.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include <set>


void callback(Interface ui, Board& board)
{
   if (!Position(ui.getPreviousPosition()).isValid() && !ui.getSelectPosition().isValid())
   {
      if (board[ui.getSelectPosition()].getLetter() == ' ')
      {
         ui.clearSelectPosition();
      }
      else if (board[ui.getSelectPosition()].isWhite() == board.whiteTurn())
      {
         ui.clearSelectPosition();
      }
   }

   if (ui.getPreviousPosition().isValid() && ui.getSelectPosition().isValid())
   {
      Move move;
      move.setSrc(ui.getPreviousPosition());
      move.setDest(ui.getSelectPosition());
      //move.complete(board);
      set<Move> possible;
      board[ui.getPreviousPosition()].getMoves(possible, board);

      set<Move>::iterator it;
      it = possible.find(move);
      if (it != possible.end())
      {
         board.move(*it);
      }
      ui.clearSelectPosition();
      ui.clearPreviousPosition();
      
   }

   board.display(ui.getHoverPosition(), ui.getSelectPosition());
}

int main()
{
   Interface ui("Chess");
   ogstream gout;
   ui.run(callback);
   TestPawn().run();
   TestQueen().run();
   std::cout << "Tests Passed!\n";
}

