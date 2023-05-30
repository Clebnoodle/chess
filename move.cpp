/***********************************************************************
 * Source File:
 *    MOVE : Keep track of a single chess move
 * Author:
 *    Br. Helfrich, Braeden Pope, Caleb Nuttall
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "position.h"
#include <iostream>
#include <sstream>
#include <cassert>
#include "board.h"
using namespace std;

/******************************************
 * MOVE ASSIGNMENT OPERATOR
 *       Creates move using smith notation
 ******************************************/
Move& Move::operator=(const char* move)
{
	Position start;
	Position end;
	parse(move);
   return *this;
}

/******************************************
 * MOVE INSERTION OPERATOR
 *       Aint nothing but a glorified getText call...
 ******************************************/
ostream& operator << (ostream& out, Move& rhs)
{
   out << rhs.getText();

   return out;
}

/*************************************
 * MOVE EXTRACTION OPERATOR
 *      Just the assignment operator with a string
 *      on the right-hand-side
 **************************************/
istream& operator >> (istream& in, Move& rhs)
{
   string s;
   if (in >> s)
      rhs = s.c_str(); // assigment operator calling Move::read()

   return in;
}

/**********************************************
 * Move : ASSIGNMENT
 **********************************************/
const Move& Move::operator = (const Move& rhs)
{
   source = rhs.getSrc();
   dest = rhs.getDest();
   piece = rhs.getPromotion();
   capture = rhs.getCapture();
   enPassant = rhs.getEnPassant();
   castleK = rhs.getCastleK();
   castleQ = rhs.getCastleQ();
   isWhite = rhs.getWhiteMove();
   error = rhs.error;
   return *this;
}

/***********************************************
 * MOVE : COMPLETE
 * We have a move that has nothing but a source
 * and a destination. Figure out what it should be
 **********************************************/
void Move::complete(const Board& board)
{
   // set the capture
   capture = board[dest].getLetter();

   // set the color
   isWhite = board[source].isWhite();

   // handle if this is an en-passant
   if (capture == EMPTY && board[source].getLetter() == PAWN)
      enPassant = true;
}

/***********************************************
 * MOVE : LETTER FROM PIECE TYPE
 *        Get the Smith notation letter for a piece from
 *        the Piece Type
 *********************************************/
char Move::letterFromPieceType(PieceType pt) const
{
   switch (pt)
   {
   case EMPTY:
      return ' ';
   case KING:
      return 'k';
   case QUEEN:
      return 'q';
   case ROOK:
      return 'r';
   case BISHOP:
      return 'b';
   case PAWN:
      return 'p';
   }
   assert(false);
   return ' ';
}

/**********************************************
 * MOVE : READ
 * Parse the input text into its components.
 * We will not validate until later...
 **********************************************/
void Move::parse(const string& s)
{
   // clear the move
   *this = Move();

   //
   // from square
   //
   source = s.c_str() + 0;  // start at the start

   //
   // to square
   //
   dest = s.c_str() + 2;   // start two characters in, the destination

   //
   // capture and promotion
   //

   for (int i = 4; i < (int)s.size(); i++)
   {
      switch (s[i])
      {
      case 'p':   // capture a pawn
         capture = PAWN;
         break;
      case 'n':   // capture a knight
         capture = KNIGHT;
         break;
      case 'b':   // capture a bishop
         capture = BISHOP;
         break;
      case 'r':   // capture a rook
         capture = ROOK;
         break;
      case 'q':   // capture a queen
         capture = QUEEN;
         break;
      case 'k':   // !! you can't capture a king you silly!
         capture = KING;
         break;

      case 'c':  // short castling or kings castle
         castleK = true;
         break;
      case 'C':  // long castling or queen castle
         castleQ = true;
         break;
      case 'E':  // En-passant
         enPassant = true;
         break;

      case 'N':  // Promote to knight
         piece = KNIGHT;
         break;
      case 'B':  // Promote to Bishop
         piece = BISHOP;
         break;
      case 'R':  // Promote to Rook
         piece = ROOK;
         break;
      case 'Q':  // Promote to Queen
         piece = QUEEN;
         break;

      default:
         // unknown piece
         error = s;
         throw string("Unknown promotion piece specification");
      }
   }

   // if we made it this far, we are successful
   return;
}

/***********************************************
 * MOVE : GET TEXT
 *        Generate the human-readable text
 *********************************************/
string Move::getText() const
{
   // if there is an error, use it instead
   if (error.length())
      return error;

   // use the string stream so we can use the insertion operators of
   // the position class
   std::ostringstream sout;
   sout << source << dest;

   // handle all the special stuff
   if (enPassant)
      sout << "E";
   if (castleK)
      sout << "c";
   if (castleQ)
      sout << "C";
   if (piece != EMPTY)
      sout << toupper(letterFromPieceType(piece));
   if (capture != EMPTY)
      sout << letterFromPieceType(piece);

   // return the result as a string
   return sout.str();
}

/******************************************
 * MOVE LESS THAN OPERATOR
 *       Compares move destinations.
 *       Needed for use by a set
 ******************************************/
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