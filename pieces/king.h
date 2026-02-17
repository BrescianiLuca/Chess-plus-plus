#ifndef KING_H
#define KING_H

#include "gamepiece.h"

class King : public GamePiece {
    public : 
        King(int x, int y, bool isWhite);
        bool move (int newX, int newY, GamePiece* board[8][8]) override;
        std::string getType() override {return "King"; }
        bool isAttacking(int targetX, int targetY, GamePiece* board[8][8]) override;
};

#endif