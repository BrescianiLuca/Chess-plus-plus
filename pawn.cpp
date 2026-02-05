#include "pawn.h"
#include <cmath>
#include <iostream>

using namespace std;

Pawn::Pawn(int x, int y, bool isWhite) : GamePiece(x, y, isWhite) {}

bool Pawn::move(int newX, int newY, GamePiece* board[8][8]) {
    int dx = abs(newX - positionX);
    int dy = newY - positionY;

    int direction = isWhite ? -1 : 1;
    int startRow = isWhite ? 6 : 1;

    // Normal move: 1 step forward, same column
    if (dx == 0 && dy == direction) {
        GamePiece::move(newX, newY,board);
        return true;
    }

    // Double move: 2 steps forward, same column, valid only from starting rank
    if (dx == 0 && dy == 2 * direction && positionY == startRow) {
        GamePiece::move(newX, newY, board);
        return true;
    }

    // Capture move geometry: 1 step forward, 1 step sideways
    if (dx == 1 && dy == direction) {
        GamePiece::move(newX, newY, board);
        return true;
    }

    cout << "Invalid move for Pawn" << endl;
    return false;
}
