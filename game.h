#ifndef GAME_H
#define GAME_H

#include <string>
#include <SFML/Graphics.hpp>
#include "gamepiece.h"

class Game {
    private:
        std::string msg;  
        GamePiece* board[8][8];  
        sf::RenderWindow* window;
        const int TILE_SIZE = 100;
        sf::Vector2i selectedSquare;

    public:
        Game(std::string message);
        ~Game();
        void test();
        void start();
        void drawBoard();
        void drawPieces();

};

#endif