#include "gamepiece.h"

using namespace std;

GamePiece::GamePiece(int x, int y, bool isWhite) : positionX(x), positionY(y), isWhite(isWhite) {}

pair<int, int> GamePiece::getPosition() {
    return {positionX, positionY};
}

bool GamePiece::move(int newX, int newY,  GamePiece* board[8][8]) {
    // make the validation checks in subclasses
    positionX = newX;
    positionY = newY;
    return true;
}

GamePiece::~GamePiece() {}



