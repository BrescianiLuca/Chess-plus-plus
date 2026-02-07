#ifndef ROOK_H
#define ROOK_H

#include "gamepiece.h"

class Rook : public GamePiece {
    public:
        Rook(int x, int y, bool isWhite);
        bool move(int newX, int newY, GamePiece* board[8][8]) override;
        bool isAttacking(int targetX, int targetY, GamePiece* board[8][8]) override;
        bool isPathFree(int x, int y, GamePiece* board[8][8]) override;
        std::string getType() override {return "Rook"; }
};

#endif