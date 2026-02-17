#include "rook.h"
#include <iostream>
#include <cmath>

using namespace std;

Rook::Rook(int x, int y, bool isWhite) : GamePiece(x, y, isWhite) {};

bool Rook::isPathFree(int x, int y, GamePiece* board[8][8]) {
    
    int stepX;
    if (x > positionX) {
        stepX = 1;
    } else if (x < positionX) {
        stepX = -1;
    } else {
        stepX = 0;
    }

    int stepY;
    if (y > positionY) {
        stepY = 1;
    } else if (y < positionY) {
        stepY = -1;
    } else {
        stepY = 0;
    }

    int currentPositionX = positionX + stepX;
    int currentPositionY = positionY + stepY;

    // check if there are no pieces in the path
    if (stepX == 0) {
        while (currentPositionY != y) {
            if (board[currentPositionY][currentPositionX] != nullptr &&
                board[currentPositionY][currentPositionX]->getType() == "King" &&
                board[currentPositionY][currentPositionX]->getWhite() != isWhite) {
                return true;
            }
            if (board[currentPositionY][currentPositionX] != nullptr) {
                return false;
            }

            currentPositionY += stepY;
        }
    } else {
        while (currentPositionX != x) {
            if (board[currentPositionY][currentPositionX] != nullptr && 
                board[currentPositionY][currentPositionX]->getType() == "King" &&
                board[currentPositionY][currentPositionX]->getWhite() != isWhite) {
                return true;
            }
            if (board[currentPositionY][currentPositionX] != nullptr) {
                return false;
            }

            currentPositionX += stepX;
        }
    }

    return true;
}

bool Rook::move(int newX, int newY,  GamePiece* board[8][8]) {
    
    int dx = abs(newX - positionX);
    int dy = abs(newY - positionY);

    if (!isPathFree(newX, newY, board)) return false;

    if (((dx != 0 && dy == 0) || (dx == 0 && dy != 0)) 
    && (board[newY][newX] == nullptr || board[newY][newX]->getWhite() != isWhite)) {
        GamePiece::move(newX, newY, board);
        has_moved = true;
        return true;
    }


    cout << "Invalid move for Rook" << endl;
    return false;
}

bool Rook::isAttacking(int targetX, int targetY, GamePiece* board[8][8]) {
    //check if the target is in the same row or column and is not blocked by other pieces
    int dx = abs(targetX - positionX);
    int dy = abs(targetY - positionY);

    if ((dx != 0 && dy == 0) || (dx == 0 && dy != 0)) {
        return isPathFree(targetX, targetY, board);
    }
    
    return false;
}



