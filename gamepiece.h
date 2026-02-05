#ifndef GAMEPIECE_H
#define GAMEPIECE_H

#include <utility>
#include <string>

class GamePiece {
    protected:
        int positionX;
        int positionY;
        bool isWhite;;
    
    public:
        GamePiece(int x, int y, bool isWhite);
        virtual ~GamePiece();
        std::pair<int, int> getPosition();
        virtual bool move(int newX, int newY, GamePiece* board[8][8]);
        virtual std::string getType() { return "Generic"; }
        bool getWhite() const { return isWhite; }
};

#endif