#ifndef QUEEN_H
#define QUEEN_H

#include "gamepiece.h"

class Queen : public GamePiece {
    public:
        Queen (int x, int y, bool isWhite);
        bool move (int newX, int newY, GamePiece* board[8][8]) override;
        std::string getType() override { return "Queen"; }
};

#endif