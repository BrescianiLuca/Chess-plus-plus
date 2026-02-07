#ifndef PAWN_H
#define PAWN_H

#include "gamepiece.h"

class Pawn : public GamePiece {
    public:
        Pawn(int x, int y, bool isWhite);
        bool move(int newX, int newY, GamePiece* board[8][8]) override;
        bool isAttacking(int targetX, int targetY, GamePiece *board[8][8]) override;
        std::string getType() override { return "Pawn"; }
};

#endif
