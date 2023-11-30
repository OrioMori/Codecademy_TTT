#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "ttt_func.h"

//Two Players
//3x3 Grid
// for and while loops
// vectors to hold moves in the grid.
// functions should be modular.
/*
	X   X   X

	X   X   X  --Grid Preview

	X   X   X
*/

//Variables
std::string playerXName = "[X] ";
std::string playerOName = "[O] ";
int playerXMove;
int playerOMove;
std::vector<char> xando = { '_', '_', '_', '_', '_', '_', '_', '_', '_' };
bool isXsTurn = true;
bool gameWon = false;
std::string userChoice;

//main
int main() {
	intro();
	playerXName = playerNames(playerXName);
	playerOName = playerNames(playerOName);
	while (gameWon == false) {
		std::cout << "Player X: " << playerXName << " Player O: " << playerOName << "\n";
		printBoard(xando);
		if (isXsTurn == true) {
			std::cout << playerXName << "'s Turn: ";
			std::cin >> userChoice;
			isNumOrString(userChoice, xando, isXsTurn);
			gameWon = checkForWin(xando, isXsTurn);
			isXsTurn = false;

		}
		else {
			std::cout << playerOName << "'s Turn: ";
			std::cin >> userChoice;
			isNumOrString(userChoice, xando, isXsTurn);
			gameWon = checkForWin(xando, isXsTurn);
			isXsTurn = true;
		}
	}
	printBoard(xando);
	return 0;
}