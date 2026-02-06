#include "rook.h"
#include <iostream>
#include <cmath>

using namespace std;

Rook::Rook(int x, int y, bool isWhite) : GamePiece(x, y, isWhite) {};

bool Rook::move(int newX, int newY,  GamePiece* board[8][8]) {
    
    int dx = abs(newX - positionX);
    int dy = abs(newY - positionY);

    int stepX;
    if (newX > positionX) {
        stepX = 1;
    } else if (newX < positionX) {
        stepX = -1;
    } else {
        stepX = 0;
    }

    int stepY;
    if (newY > positionY) {
        stepY = 1;
    } else if (newY < positionY) {
        stepY = -1;
    } else {
        stepY = 0;
    }

    int currentPositionX = positionX + stepX;
    int currentPositionY = positionY + stepY;

    // check if there are no pieces in the path
    if (stepX == 0) {
        while (currentPositionY != newY) {
            if (board[currentPositionY][currentPositionX] != nullptr) {
                return false;
            }

            currentPositionY += stepY;
        }
    } else {
        while (currentPositionX != newX) {
            if (board[currentPositionY][currentPositionX] != nullptr) {
                return false;
            }

            currentPositionX += stepX;
        }
    }

    if (((dx != 0 && dy == 0) || (dx == 0 && dy != 0)) 
    && (board[newY][newX] == nullptr || board[newY][newX]->getWhite() != isWhite)) {
        GamePiece::move(newX, newY, board);
        return true;
    }


    cout << "Invalid move for Rook" << endl;
    return false;
}



