#ifndef GAMEPIECE_H
#define GAMEPIECE_H

#include <utility>
#include <string>

class GamePiece {
    protected:
        int positionX;
        int positionY;
        bool isWhite;
        bool has_moved = false;
    
    public:
        GamePiece(int x, int y, bool isWhite);
        virtual ~GamePiece();
        std::pair<int, int> getPosition();
        virtual bool move(int newX, int newY, GamePiece* board[8][8]);
        virtual bool isAttacking(int targetX, int targetY, GamePiece* board[8][8]) {return false; };
        virtual bool isPathFree(int x, int y, GamePiece* board[8][8]) {return false; };
        virtual std::string getType() { return "Generic"; };
        bool getWhite() const { return isWhite; }
        bool hasMoved() const { return has_moved; }
};

#endif