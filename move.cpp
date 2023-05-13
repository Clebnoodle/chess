#include "move.h"
#include "position.h"
using namespace std;


Move& Move::operator=(const char* move)
{
	Position start;
	Position end;
	parse(move);
   return *this;
}

void Move::parse(const string& textMove)
{
   string::const_iterator it = textMove.cbegin();

   // get the source
   int col = *it - 'a';
   it++;
   int row = *it - '1';
   it++;
   source = Position(row, col);

   // get the destination
   col = *it - 'a';
   it++;
   row = *it - '1';
   it++;
   dest = Position(row,col);

   
   for (; it != textMove.end(); ++it)
   {
      switch (*it)
      {
      case 'p':   // capture a pawn
      case 'n':   // capture a knight
      case 'b':   // capture a bishop
      case 'r':   // capture a rook
      case 'q':   // capture a queen
      case 'k':   // !! you can't capture a king you silly!
         capture = tolower(*it);
         break;

      case 'c':  // short castling or king's castle
         castleK = true;
         break;
      case 'C':  // long castling or queen's castle
         castleQ = true;
         break;
      case 'E':  // En-passant
         enPassant = true;
         break;

      case 'Q':  // Promote to Queen
         promotion = *it;
         break;

      }
   }

}

bool Move::operator<(const Move& move) const
{
   if (this->getDest().getLocation() < move.getDest().getLocation()) {
      return true;
   }
   else
   {
      return false;
   }
}