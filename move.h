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
   Move(): piece(' '), capture(' '), enPassant(false), castleK(false), castleQ(false), isWhite(true), promotion(' '), error("") {}
   void parse(const std::string& move);
   std::string getText();
   Position getSrc();
   Position getDest() const { return dest; }
   void setSrc(Position pos) { source = pos; }
   void setDest(Position pos) { dest = pos; }
   char getPromotion();
   char getCapture();
   bool getEnPassant();
   bool getCastleK();
   bool getCastleQ();
   bool getWhiteMove();
   void setEnPassant() { enPassant = true; }
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
   void setWhiteMove(bool isWhite) { this->isWhite = isWhite; }
   void assign(Move move);
   void assign(std::string move);
   void operator<<(std::string move);
   std::string operator>>(std::string move);
   Move& operator=(const char* move);
   bool operator<(const Move& move) const;
};