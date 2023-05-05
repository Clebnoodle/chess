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
   Position(string pos);
   void set(int r, int c);

   Position& operator=(Position rhs);
};