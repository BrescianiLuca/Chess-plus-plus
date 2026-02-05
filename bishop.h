#ifndef BISHOP_H
#define BISHOP_H

#include "gamepiece.h"

class Bishop : public GamePiece {
    public:
        Bishop(int x, int y, bool isWhite);
        bool move(int newX, int newY, GamePiece* board[8][8]) override;
};

#endif