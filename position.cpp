#include "position.h"
#include <iostream>

/******************************************
 * POSITION INSERTION OPERATOR
 ******************************************/
ostream& operator << (ostream& out, const Position& rhs)
{
   if (rhs.isValid())
      out << (char)(rhs.getColumn() + 'a')
      << (char)(rhs.getRow() + '1');
   else
      out << "error";
   return out;
}

/**********************************************
 * POSITION : ASSIGNMENT
 **********************************************/
const Position& Position::operator = (const char* rhs)
{
   if (rhs == NULL)
      location = -1;

   else if (rhs[0] < 'a' || rhs[0] > 'h' ||
      rhs[1] < '1' || rhs[1] > '8')
      location = -1;

   else
      set(rhs[1] - '1', rhs[0] - 'a');

   return *this;
}