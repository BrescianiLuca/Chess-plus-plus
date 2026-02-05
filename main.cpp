#include "game.h"
#include <iostream>

int main() {
    // Ask for message input from the user
    std::cout << "Enter a message: ";
    std::string user_message;
    std::cin >> user_message;
    Game game(user_message);
    // game.test();
    game.start();

    return 0;
}