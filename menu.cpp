#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include "menu.h"
#include "game.h"

void mainMenu() {
    displayOptions();
    getInput();
}

void displayOptions() {
    std::cout << "Welcome to Tic Tac Toe! Please select an option!\n";
    std::cout << "-=-=-=-=-=-=-=-=-\n";
    std::cout << "Type [P] to play!\n";
    std::cout << "Type anything else to quit!\n";
    std::cout << "-=-=-=-=-=-=-=-=-\n";
}

void getInput() {
    char input;
    std::cin >> input;

    if (tolower(input) == 'p') {
        std::cout << '\n';
        gameExplain();
    }
    else {
        std::cout << "See you next time!\n";
        exit(0);
    }
}

int main()
{
    mainMenu();

    return 0;
}
