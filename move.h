#pragma once

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
   string error;

public:
   Move();
   string getText();
   Position getSrc();
   Position getDest();
   char getPromotion();
   char getCapture();
   bool getEnPassant();
   bool getCastleK();
   bool getCastleQ();
   bool getWhiteMove();
   void setEnPassant();
   void setCastle(bool isKing);
   void setCastleQ();
   void setWhiteMove();
   void assign(Move move);
   void assign(string move);
   void operator<<(string move);
   string operator>>(string move);
};