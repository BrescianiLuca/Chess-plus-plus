#ifndef KNIGHT_H
#define KNIGHT_H

#include "gamepiece.h"

class Knight : public GamePiece {
    public:
        Knight (int x, int y, bool isWhite);
        bool move (int newX, int newY, GamePiece* board[8][8]) override;
        std::string getType() override {return "Knight"; }
};

#endif