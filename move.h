#pragma once
#include "position.h"
#include <string>

class Move
{
private:
   Position dest;
   Position source;
   char piece;
   char capture;
   bool enPassant;
   bool castleK;
   bool castleQ;
   bool isWhite;
   char promotion;
   std::string error;

public:
   Move();
   void parse(const std::string& move);
   std::string getText();
   Position getSrc();
   Position getDest();
   void setSrc(Position pos);
   void setDest(Position pos);
   char getPromotion();
   char getCapture();
   bool getEnPassant();
   bool getCastleK();
   bool getCastleQ();
   bool getWhiteMove();
   void setEnPassant();
   void setPromotion() 
   {
      if (isWhite) 
      {
         promotion = 'q';
      }
      else
      {
         promotion = 'Q';
      }
   };
   void setCastle(bool isKing);
   void setCastleQ();
   void setCapture(char piece) { capture = piece; };
   void setWhiteMove(bool isWhite);
   void assign(Move move);
   void assign(std::string move);
   void operator<<(std::string move);
   std::string operator>>(std::string move);
   Move& operator=(std::string& move);
   bool operator<(Move move);
};