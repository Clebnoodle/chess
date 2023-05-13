#pragma once
#include <string>

class Position
{
private:
   char location;
   double squareWidth;
   double squareHeight;

public:
   Position();
   Position(std::string pos);
   Position(int row, int col) 
   {
      this->location = 8 * row + col;
   };
   int getLocation() { return location; };
   int getRow();
   int getColumn();
   int getX();
   int getY();
   bool isValid();
   void setRow(int row);
   void setCol(int col);
   void set(int row, int col);
   void adjustRow(int dRow);
   void adjustCol(int dCol);
   bool operator==(Position rhs);
   Position& operator=(Position rhs);
   void operator+(Position rhs);
   void operator<<(Position rhs);
   void operator>>(Position rhs);
};