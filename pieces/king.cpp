#include "king.h"
#include <iostream>
#include <cmath>

using namespace std;

King::King(int x, int y, bool isWhite) : GamePiece(x, y, isWhite) {};

bool King::move(int newX, int newY, GamePiece *board[8][8])
{
    int dx = abs(newX - positionX);
    int dy = abs(newY - positionY);

    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            GamePiece *piece = board[i][j];
            if (piece != nullptr)
            {
                if (piece->isAttacking(newX, newY, board) && piece->getWhite() != isWhite)
                {
                    cout << "Square is controlled" << endl;
                    return false;
                }
            }
        }
    }

    // Castling (TODO : check if the squares are attacked);

    if (!hasMoved() && dy == 0 && dx == 2) {
        int rookX = (newX == 6) ? 7 : 0;
        GamePiece *rook = board[positionY][rookX];

        if (rook != nullptr && rook->getType() == "Rook" && !rook->hasMoved()) {
            bool pathClear = true;
            if (newX == 6) { // Kingside
                for (int x = positionX + 1; x < 7; x++) {
                    if (board[positionY][x] != nullptr) pathClear = false;
                }
            } else { // Queenside
                for (int x = positionX - 1; x > 0; x--) {
                    if (board[positionY][x] != nullptr) pathClear = false;
                }
            }

            if (!pathClear) {
                cout << "Cannot castle, path is not clear" << endl;
                return false;
            }

            // TODO check if the squares are attacked

            // Make move for castling
            int step = (newX == 6) ? 1 : -1;
            int targetRookX = positionX + step;
            
            // Move King (GamePiece::move updates positionX/Y)
            GamePiece::move(newX, newY, board);
            
            // Move Rook
            board[positionY][targetRookX] = rook;
            board[positionY][rookX] = nullptr;
            rook->move(targetRookX, positionY, board);

            has_moved = true;
            return true;
        }
    }

    if (dy > 1 || dx > 1)
    {
        return false;
    }
    else if ((board[newY][newX] == nullptr || board[newY][newX]->getWhite() != isWhite))
    {
        GamePiece::move(newX, newY, board);
        has_moved = true;
        return true;
    }

    cout << "invalid move for King" << endl;
    return false;
}

bool King::isAttacking(int targetX, int targetY, GamePiece *board[8][8])
{
    int dx = abs(targetX - positionX);
    int dy = abs(targetY - positionY);

    if (dx <= 1 && dy <= 1) {
        return true;
    }

    return false;
}
