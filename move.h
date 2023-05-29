#pragma once
#include "position.h"
#include "pieceType.h"
#include <string>

class Move
{
private:
   Position dest;
   Position source;
   PieceType piece;
   PieceType capture;
   bool enPassant;
   bool castleK;
   bool castleQ;
   bool isWhite;
   std::string error;

public:
   // constructors
   Move(): piece(EMPTY), capture(EMPTY), enPassant(false), castleK(false), castleQ(false), isWhite(true), error("") {}
   Move(const Move& rhs) { *this = rhs; }
   Move(const char* s) { *this = s; }
   
   void parse(const std::string& move);

   // getters
   const Position& getSrc()  const { return source; }
   const Position& getDest() const { return dest; }
   PieceType getPromotion()   const { return piece; }
   PieceType getCapture()     const { return capture; }
   bool getEnPassant()        const { return enPassant; }
   bool getCastleK()          const { return castleK; }
   bool getCastleQ()          const { return castleQ; }
   bool getWhiteMove()        const { return isWhite; }

   // setters
   void setSrc(Position pos) { source = pos; }
   void setDest(Position pos) { dest = pos; }
   
   
   
   void setEnPassant() { enPassant = true; }
   void setPromotion(PieceType pt) { piece = pt; }

   void setCastle(bool isKing)
   {
      if (isKing)
      {
         castleK = true;
      }
      else 
      {
         castleQ = true;
      }
   }
   void setCapture(PieceType piece) { capture = piece; };
   void setWhiteMove(bool isWhite) { this->isWhite = isWhite; }
   void assign(Move move);
   void assign(std::string move);

   char letterFromPieceType(PieceType pt) const;
   string getText() const;

   void operator<<(std::string move);
   std::string operator>>(std::string move);
   Move& operator=(const char* move);
   const Move& operator=(const Move& rhs);
   bool operator<(const Move& move) const;
};