#pragma once
#include <string>

class Position
{
private:
   char location;
   double squareWidth;
   double squareHeight;

public:
   Position(): location(0), squareHeight(1), squareWidth(1) {}
   Position(std::string pos)
   {
      int col = pos[0] - 'a';
      int row = pos[1] - '1';
      this->location = 8 * row + col;
      squareHeight = 1;
      squareWidth = 1;
   }
   Position(int row, int col) 
   {
      this->location = 8 * row + col;
      squareHeight = 1;
      squareWidth = 1;
   };
   int getLocation() { return location; };
   int getRow() { return location / 8; };
   int getColumn() { return location % 8; };
   //int getX();
   //int getY();
   bool isValid() { return (location >= 0 && location <= 63); };
   //void setRow(int row);
   //void setCol(int col);
   //void set(int row, int col);
   void adjustRow(int dRow) { location += dRow * 8; };
   void adjustCol(int dCol) { location += dCol; };
   //bool operator==(Position rhs);
   Position& operator=(Position rhs) 
   { 
      location = rhs.location;
      squareHeight = rhs.squareHeight;
      squareWidth = rhs.squareWidth;
      return *this;
   }
   //void operator+(Position rhs);
   //void operator<<(Position rhs);
   //void operator>>(Position rhs);
};