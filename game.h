#ifndef GAME_H
#define GAME_H

#include <string>
#include <SFML/Graphics.hpp>
#include "gamepiece.h"
#include <map>

class Game {
    private: 
        GamePiece* board[8][8];  
        sf::RenderWindow* window;
        const int TILE_SIZE = 100;
        sf::Vector2i selectedSquare;
        std::map<std::string, sf::Texture> textures;
        void loadTextures();

    public:
        Game();
        ~Game();
        void test();
        void start();
        void drawBoard();
        void drawPieces();

};

#endif