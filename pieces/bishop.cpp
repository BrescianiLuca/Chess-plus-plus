#include "bishop.h"
#include <cmath>
#include <iostream>

using namespace std;

Bishop::Bishop(int x, int y, bool isWhite) : GamePiece(x, y, isWhite) {};

bool Bishop::isPathFree(int x, int y, GamePiece* board[8][8]) {
    // check if there are no pieces in the path
    int stepX = (x > positionX) ? 1 : -1;
    int stepY = (y > positionY) ? 1 : -1;

    int currentPositionX = positionX + stepX;
    int currentPositionY = positionY + stepY;

    while (currentPositionX != x && currentPositionY != y) {
        if (board[currentPositionY][currentPositionX] != nullptr && board[currentPositionY][currentPositionX]->getType() == "King") {
            return true;
        }
        if (board[currentPositionY][currentPositionX] != nullptr) {
            //cout << "invalid" << endl;
            return false;
        }
        currentPositionX += stepX;
        currentPositionY += stepY;
    }

    return true;
}

bool Bishop::move(int newX, int newY, GamePiece* board[8][8]) {
    int dx = abs(newX - positionX);
    int dy = abs(newY - positionY);

    if (!isPathFree(newX, newY, board)) return false;

    if (dx == dy && (board[newY][newX] == nullptr || board[newY][newX]->getWhite() != isWhite)) {
        GamePiece::move(newX, newY, board);
        return true;
    }

    cout << "Invalid move for Bishop" << endl;
    return false;

}

bool Bishop::isAttacking(int targetX, int targetY, GamePiece* board[8][8]) {
    int dx = abs(targetX - positionX);
    int dy = abs(targetY - positionY);

    if (dx == dy) {
        return isPathFree(targetX, targetY, board);
    }

    return false;
} 