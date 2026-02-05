#include "game.h"
#include "pawn.h"
#include "bishop.h"
#include <iostream>


using namespace std;

Game::Game(std::string message) {
    msg = message;
    window = nullptr;
    
    // Initialize board with 0
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            board[i][j] = 0;

    // Set up Pawns
    for(int j=0; j<8; j++) {
        board[1][j] = new Pawn(j, 1, false); // Black Pawn
        board[6][j] = new Pawn(j, 6, true);  // White Pawn
    }
    
    // Set up other pieces (simplified for now, using 2 for others)
    // Black pieces
    board[0][0] = nullptr; board[0][7] = nullptr; // Rooks
    board[0][1] = nullptr; board[0][6] = nullptr; // Knights
    board[0][2] = new Bishop(2, 0, false); board[0][5] = new Bishop(5, 0, false); // Bishops
    board[0][3] = nullptr; // Queen 
    board[0][4] = nullptr; // King
    // White pieces
    board[7][0] = nullptr; board[7][7] = nullptr; // Rooks
    board[7][1] = nullptr; board[7][6] = nullptr; // Knights
    board[7][2] = new Bishop(2, 7, true); board[7][5] = new Bishop(5, 7, true); // Bishops
    board[7][3] = nullptr; // Queen
    board[7][4] = nullptr; // King
}

Game::~Game() {
    if (window) {
        delete window;
    }
}

void Game::test() {
    cout << msg << endl;
}

void Game::start() {
    window = new sf::RenderWindow(sf::VideoMode(800, 800), "Chess Game");
    selectedSquare = sf::Vector2i(-1, -1);

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int x = event.mouseButton.x / TILE_SIZE;
                    int y = event.mouseButton.y / TILE_SIZE;
                    
                    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
                        if (selectedSquare.x == -1) {
                            // Select piece if there is one
                            if (board[y][x] != nullptr) {
                                selectedSquare = sf::Vector2i(x, y);
                            }
                        } else {
                            // Move piece
                            // board[y][x] = board[selectedSquare.y][selectedSquare.x];
                            // board[selectedSquare.y][selectedSquare.x] = 0;
                            // selectedSquare = sf::Vector2i(-1, -1);

                            GamePiece* piece = board[selectedSquare.y][selectedSquare.x];
                            if (piece != nullptr) {
                                if (piece->move(x, y, board)) {
                                    board[y][x] = piece;
                                    board[selectedSquare.y][selectedSquare.x] = nullptr;
                                    selectedSquare = sf::Vector2i(-1, -1);
                                    cout << piece->getPosition().first << ", " << piece->getPosition().second << endl;
                                } else {
                                    // Invalid move, keep selection
                                    cout << "Move invalid, try again." << endl;
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

void Game::drawBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            sf::RectangleShape tile(sf::Vector2f(TILE_SIZE, TILE_SIZE));
            tile.setPosition(j * TILE_SIZE, i * TILE_SIZE);
            
            if ((i + j) % 2 == 0)
                tile.setFillColor(sf::Color(238, 238, 210)); // Light square
            else
                tile.setFillColor(sf::Color(118, 150, 86)); // Dark square
            
            // Highlight selected square
            if (selectedSquare.x == j && selectedSquare.y == i) {
                tile.setFillColor(sf::Color(186, 202, 68));
            }

            window->draw(tile);
        }
    }
}

void Game::drawPieces() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
             GamePiece* piece = board[i][j];
             if (piece != nullptr) {
                 sf::CircleShape shape(TILE_SIZE / 2 - 10);
                 shape.setPosition(j * TILE_SIZE + 10, i * TILE_SIZE + 10);
                 
                 if (piece->getWhite()) {
                     shape.setFillColor(sf::Color::White);
                     shape.setOutlineColor(sf::Color::Black);
                     shape.setOutlineThickness(2);
                 } else {
                     shape.setFillColor(sf::Color::Black);
                     shape.setOutlineColor(sf::Color::White);
                     shape.setOutlineThickness(2);
                 }
                 window->draw(shape);
             }
        }
    }
}

 