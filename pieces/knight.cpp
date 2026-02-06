#include "knight.h"
#include <iostream>
#include <cmath>

using namespace std;

Knight::Knight(int x, int y, bool isWhite) : GamePiece(x, y, isWhite) {};

bool Knight::move(int newX, int newY, GamePiece* board[8][8]) {
    int dx = abs(newX - positionX);
    int dy = abs(newY - positionY);

    bool valid = board[newY][newX] == nullptr || board[newY][newX]->getWhite() != isWhite;

    if (((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) && valid) {
        GamePiece::move(newX, newY, board);
        return true;
    }

    cout << "Invalid move for Knight" << endl;
    return false;
}