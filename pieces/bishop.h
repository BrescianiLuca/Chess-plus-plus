#ifndef BISHOP_H
#define BISHOP_H

#include "gamepiece.h"

class Bishop : public GamePiece {
    public:
        Bishop(int x, int y, bool isWhite);
        bool move(int newX, int newY, GamePiece* board[8][8]) override;
        bool isAttacking(int targetX, int targetY, GamePiece* board[8][8]) override;
        bool isPathFree(int x, int y, GamePiece* board[8][8]) override;
        std::string getType() override { return "Bishop"; }
};

#endif