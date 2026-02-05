#include "queen.h"
#include <iostream>
#include <cmath>

using namespace std;

Queen::Queen(int x, int y, bool isWhite) : GamePiece (x, y, isWhite) {};

bool Queen::move(int newX, int newY, GamePiece* board[8][8]) {
    int dx = (newX - positionX);
    int dy = (newY - positionY);

    int stepX, stepY, currentPositionX, currentPositionY;

    if (dx != 0 && dy != 0) {
        // check diagonals
        stepX = (newX > positionX) ? 1 : -1;
        stepY = (newY > positionY) ? 1 : -1;

        currentPositionX = positionX + stepX;
        currentPositionY = positionY + stepY;

        while (currentPositionX != newX && currentPositionY != newY) {
            if (board[currentPositionY][currentPositionX] != nullptr) {
                cout << "invalid move for Queen" << endl;
                return false;
            }
            currentPositionX += stepX;
            currentPositionY += stepY;
        }
    } else {

        if (newX > positionX) {
            stepX = 1;
        } else if (newX < positionX) {
            stepX = -1;
        } else {
            stepX = 0;
        }

        if (newY > positionY) {
            stepY = 1;
        } else if (newY < positionY) {
            stepY = -1;
        } else {
            stepY = 0;
        }

        currentPositionX = positionX + stepX;
        currentPositionY = positionY + stepY;

        // check horizontal and vertical
        if (stepX == 0) {
            while (currentPositionY != newY) {
                if (board[currentPositionY][currentPositionX] != nullptr) {
                    cout << "invalid move for Queen" << endl;
                    return false;
                }

                currentPositionY += stepY;
            }
        } else {
            while (currentPositionX != newX) {
                if (board[currentPositionY][currentPositionX] != nullptr) {
                    cout << "invalid move for Queen" << endl;
                    return false;
                }

                currentPositionX += stepX;
            }
        }
    }

    if (board[newY][newX] == nullptr || board[newY][newX]->getWhite() != isWhite) {
        GamePiece::move(newX, newY, board);
        return true;
    }
    
    return false;
}


