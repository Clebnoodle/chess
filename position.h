#pragma once
#include <string>
using std::string;
using std::ostream;
using std::istream;


/***********************************************************************
 * Structure:
 *    DELTA: Delta for the movement of pieces
 *
 * Summary:
 *    Contains the information about the horizontal (column) and 
 *    vertical (row) adjustments for moving pieces
 ************************************************************************/
struct Delta
{
   int row;
   int col;
};


/***********************************************************************
 * Header File:
 *    POSITION: Position of a piece in a chess game.
 *
 * Summary:
 *    Stores the location of a chess piece on a chess board.
 ************************************************************************/
class Position
{
private:
   char location;
   double squareWidth;
   double squareHeight;

public:

   //Constructors
   Position(): location(0), squareHeight(1), squareWidth(1) {}
   Position(std::string pos)
   {
      int col = pos[0] - 'a';
      int row = pos[1] - '1';
      this->location = 8 * row + col;
      squareHeight = 1;
      squareWidth = 1;
   }
   Position(int index): location(index), squareHeight(1), squareWidth(1) {}
   Position(int row, int col) 
   {
      this->location = 8 * row + col;
      squareHeight = 1;
      squareWidth = 1;
   };


   //Getters
   int getLocation() const { return location; };
   int getRow() const { return location / 8; };
   int getColumn() const { return location % 8; };

   //Checkers
   bool isInvalid() const { return location < 0 || location >= 64; }
   bool isValid()   const { return !isInvalid(); }
   
   //Setters
   void setRow(int r)
   {
      if (r >= 0 && r < 8 && isValid())
      {
         char c = getColumn();
         location = (char)r * 8 + c;
      }
      else
         location = -1;
   }
   void setCol(int c)
   {
      if (c >= 0 && c < 8 && isValid())
      {
         char r = getRow();
         location = r * 8 + (char)c;
      }
      else
         location = -1;
   }
   void set(int r, int c) { location = 0; setRow(r); setCol(c); }
   void setIndex(char location) 
   {
      this->location = location;
   }

   //Modifiers
   void adjustRow(int dRow) { location += dRow * 8; };
   void adjustCol(int dCol) 
   { 
      int col = getColumn();
      col += dCol;
      if (col >= 0 && col <= 7) 
      {
        location = 8 * getRow() + col;
      }
      else 
      {
         location = -1;
      }
   }

   //Operators
   const Position& operator=(const Position& rhs) 
   { 
      location = rhs.location;
      squareHeight = rhs.squareHeight;
      squareWidth = rhs.squareWidth;
      return *this;
   }
   const Position& operator =  (const char* rhs);
};

ostream& operator << (ostream& out, const Position& pos);