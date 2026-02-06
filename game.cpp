#include "game.h"
#include "pieces/pawn.h"
#include "pieces/bishop.h"
#include "pieces/rook.h"
#include "pieces/king.h"
#include "pieces/queen.h"
#include "pieces/knight.h"
#include <iostream>

using namespace std;

Game::Game()
{
    window = nullptr;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j ++) {
            board[i][j] = nullptr;
        }
    }

    loadTextures();

    // Set up Pawns
    for (int j = 0; j < 8; j++)
    {
        board[1][j] = new Pawn(j, 1, false); 
        board[6][j] = new Pawn(j, 6, true);  
    }

    // Black pieces
    board[0][0] = new Rook(0, 0, false);
    board[0][7] = new Rook(7, 0, false);
    board[0][1] = new Knight(1, 0, false);
    board[0][6] = new Knight(6, 0, false);
    board[0][2] = new Bishop(2, 0, false);
    board[0][5] = new Bishop(5, 0, false); 
    board[0][3] = new Queen(3, 0, false);                 
    board[0][4] = new King(4, 0, false);                
    // White pieces
    board[7][0] = new Rook(0, 7, true);
    board[7][7] = new Rook(7, 7, true);
    board[7][1] = new Knight(1, 7, true);
    board[7][6] = new Knight(6, 7, true);
    board[7][2] = new Bishop(2, 7, true);
    board[7][5] = new Bishop(5, 7, true); 
    board[7][3] = new Queen(3, 7, true);                
    board[7][4] = new King(4, 7, true);                
}

Game::~Game()
{
    if (window)
    {
        delete window;
    }
}

void Game::loadTextures()
{
    textures["wP"].loadFromFile("assets/wP.png");
    textures["bP"].loadFromFile("assets/bP.png");
    textures["wB"].loadFromFile("assets/wB.png");
    textures["bB"].loadFromFile("assets/bB.png");
    textures["wR"].loadFromFile("assets/wR.png");
    textures["bR"].loadFromFile("assets/bR.png");
    textures["wK"].loadFromFile("assets/wK.png");
    textures["bK"].loadFromFile("assets/bK.png");
    textures["wQ"].loadFromFile("assets/wQ.png");
    textures["bQ"].loadFromFile("assets/bQ.png");
    textures["wN"].loadFromFile("assets/wN.png");
    textures["bN"].loadFromFile("assets/bN.png");
}

void Game::start()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 800), "Chess Game");
    selectedSquare = sf::Vector2i(-1, -1);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x = event.mouseButton.x / TILE_SIZE;
                    int y = event.mouseButton.y / TILE_SIZE;

                    if (x >= 0 && x < 8 && y >= 0 && y < 8)
                    {
                        if (selectedSquare.x == -1)
                        {
                            // Select piece if there is one
                            if (board[y][x] != nullptr)
                            {
                                selectedSquare = sf::Vector2i(x, y);
                            }
                        }
                        else
                        {

                            GamePiece *piece = board[selectedSquare.y][selectedSquare.x];
                            if (piece != nullptr)
                            {
                                if (piece->move(x, y, board))
                                {
                                    board[y][x] = piece;
                                    board[selectedSquare.y][selectedSquare.x] = nullptr;
                                    selectedSquare = sf::Vector2i(-1, -1);
                                    //cout << piece->getPosition().first << ", " << piece->getPosition().second << endl;
                                }
                                else
                                {
                                    // Invalid move
                                    selectedSquare = sf::Vector2i(-1, -1);
                                    //cout << "Move invalid, try again." << endl;
                                }
                            }
                        }
                    }
                }
            }
        }

        window->clear(sf::Color::White);
        drawBoard();
        drawPieces();
        window->display();
    }
}

void Game::drawBoard()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            sf::RectangleShape tile(sf::Vector2f(TILE_SIZE, TILE_SIZE));
            tile.setPosition(j * TILE_SIZE, i * TILE_SIZE);

            if ((i + j) % 2 == 0)
                tile.setFillColor(sf::Color(238, 238, 210)); // Light square
            else
                tile.setFillColor(sf::Color(118, 150, 86)); // Dark square

            // Highlight selected square
            if (selectedSquare.x == j && selectedSquare.y == i)
            {
                tile.setFillColor(sf::Color(186, 202, 68));
            }

            window->draw(tile);
        }
    }
}

void Game::drawPieces()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            GamePiece *piece = board[i][j];
            if (piece != nullptr)
            {
                std::string type = piece->getType();
                std::string key = (piece->getWhite() ? "w" : "b");

                if (type == "Pawn")
                    key += "P";
                else if (type == "Bishop")
                    key += "B";
                else if (type == "Rook")
                    key += "R"; 
                else if (type == "King") 
                    key += "K";
                else if (type == "Queen") 
                    key += "Q";
                else if (type == "Knight")
                    key += "N";
                else
                    key = ""; // Fallback

                if (key != "" && textures.count(key))
                {
                    sf::Sprite sprite;
                    sprite.setTexture(textures[key]);

                    float scaleX = (float)TILE_SIZE / sprite.getLocalBounds().width;
                    float scaleY = (float)TILE_SIZE / sprite.getLocalBounds().height;
                    sprite.setScale(scaleX, scaleY);

                    sprite.setPosition(j * TILE_SIZE, i * TILE_SIZE);
                    window->draw(sprite);
                }
                else
                {
                    // Fallback to circle
                    sf::CircleShape shape(TILE_SIZE / 2 - 10);
                    shape.setPosition(j * TILE_SIZE + 10, i * TILE_SIZE + 10);

                    if (piece->getWhite())
                    {
                        shape.setFillColor(sf::Color::White);
                        shape.setOutlineColor(sf::Color::Black);
                        shape.setOutlineThickness(2);
                    }
                    else
                    {
                        shape.setFillColor(sf::Color::Black);
                        shape.setOutlineColor(sf::Color::White);
                        shape.setOutlineThickness(2);
                    }
                    window->draw(shape);
                }
            }
        }
    }
}
