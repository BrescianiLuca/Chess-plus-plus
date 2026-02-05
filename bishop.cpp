#include "bishop.h"
#include <cmath>
#include <iostream>

using namespace std;

Bishop::Bishop(int x, int y, bool isWhite) : GamePiece(x, y, isWhite) {}

bool Bishop::move(int newX, int newY, GamePiece* board[8][8]) {
    int dx = abs(newX - positionX);
    int dy = abs(newY - positionY);

    if (dx == dy && dx != 0) {
        GamePiece::move(newX, newY, board);
        return true;
    }

    cout << "Invalid move for Bishop" << endl;
    return false;

};