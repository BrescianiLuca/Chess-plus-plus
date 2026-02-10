#include "king.h"
#include <iostream>
#include <cmath>

using namespace std;

King::King(int x, int y, bool isWhite) : GamePiece(x, y, isWhite) {};

bool King::move(int newX, int newY, GamePiece* board[8][8]) {
    int dx = abs(newX - positionX);
    int dy = abs(newY - positionY);


    //TODO change into generic check... check for different pieces to test 
    
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            GamePiece* piece = board[i][j];
            if (piece != nullptr) {
                if (piece->getType() == "Pawn" || piece->getType() == "Rook" || piece->getType() == "Bishop" || piece->getType() == "Knight" ) {
                    if (piece->isAttacking(newX, newY, board) && piece->getWhite() != isWhite) {
                        cout << "Square is controlled" << endl;
                        return false;
                    }
                }
            }
        }
    }

    if (dy > 1 || dx > 1) {
        return false;
    } else if ((board[newY][newX] == nullptr || board[newY][newX]->getWhite() != isWhite)) {
        GamePiece::move(newX, newY, board);
        return true;
    }

    cout << "invalid move for King" << endl;
    return false;
}



