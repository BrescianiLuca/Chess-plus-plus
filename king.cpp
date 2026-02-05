#include "king.h"
#include <iostream>
#include <cmath>

using namespace std;

King::King(int x, int y, bool isWhite) : GamePiece(x, y, isWhite) {};

bool King::move(int newX, int newY, GamePiece* board[8][8]) {
    int dx = abs(newX - positionX);
    int dy = abs(newY - positionY);

    if (dy > 1 || dx > 1) {
        return false;
    } else if ((board[newY][newX] == nullptr || board[newY][newX]->getWhite() != isWhite)) {
        GamePiece::move(newX, newY, board);
        return true;
    }

    cout << "invalid move for King" << endl;
    return false;
}



