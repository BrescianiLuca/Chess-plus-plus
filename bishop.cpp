#include "bishop.h"
#include <cmath>
#include <iostream>

using namespace std;

Bishop::Bishop(int x, int y, bool isWhite) : GamePiece(x, y, isWhite) {};

bool Bishop::move(int newX, int newY, GamePiece* board[8][8]) {
    int dx = abs(newX - positionX);
    int dy = abs(newY - positionY);

    // check if there are no pieces in the path
    int stepX = (newX > positionX) ? 1 : -1;
    int stepY = (newY > positionY) ? 1 : -1;

    int currentPositionX = positionX + stepX;
    int currentPositionY = positionY + stepY;

    while (currentPositionX != newX && currentPositionY != newY) {
        if (board[currentPositionY][currentPositionX] != nullptr) {
            return false;
        }
        currentPositionX += stepX;
        currentPositionY += stepY;
    }

    if (dx == dy && dx != 0 && (board[newY][newX] == nullptr || board[newY][newX]->getWhite() != isWhite)) {
        GamePiece::move(newX, newY, board);
        return true;
    }

    cout << "Invalid move for Bishop" << endl;
    return false;

};