#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "ttt_func.h"

void intro() {
	std::cout << "Welcome to TIC-TAC-TOE!";
	std::cout << "\n";
	std::cout << "This game requires 2 people, or 1 person with multiple personalities (2 recommended).";
	std::cout << "\n";
	std::cout << "To play enter the square that you would like to mark by entering digits 1-9";
	std::cout << "\n";
}

std::string playerNames(std::string pName) {
	std::string name;
	std::cout << "Please enter" << pName << " name: ";
	std::cin >> name;
	pName = pName + name;
	std::cout << "\n";
	return pName;
}

bool isSpaceTaken(int choice ,std::vector<char>& vec) {
	if (vec[choice-1] == '_') {
		return false;
	}
	else {
		return true;
	}
}

void printBoard(std::vector<char>& vec) {
	std::cout << "\n";
	std::cout << vec[0] << "  " << vec[1] << "  " << vec[2] << "\n";
	std::cout << vec[3] << "  " << vec[4] << "  " << vec[5] << "\n";
	std::cout << vec[6] << "  " << vec[7] << "  " << vec[8] << "\n";
	std::cout << "\n";
	std::cout << "Enter Space Number 1-9 to pick a space. Type help for help." << "\n";
}

void help() {
	std::cout << "Space Numbers:" << "\n";
	std::cout << "1  2  3" << "\n" << "4  5  6" << "\n" << "7  8  9" << "\n";
}

//bool for turn order. 0 for O's 1 for X's.
bool checkForWin(std::vector<char>& vec, bool whoseTurn) {
	//setting a variable to determine which character to check for. 
	char playerSymbol = turnIdentifier(whoseTurn);
	//std::cout << "!DEBUG! Checking for Win.";
	//iterating through a if statements to check for all possible winning combos
			/* Top Win
				X X X
				_ _ _
				_ _ _
			*/
			if (vec[0] == playerSymbol && vec[1] == playerSymbol && vec[2] == playerSymbol) {
				std::cout << "\n" << playerSymbol << " Wins!";
				return true;
			}
			/* Mid Win
				_ _ _
				X X X
				_ _ _
			*/
			else if (vec[3] == playerSymbol && vec[4] == playerSymbol && vec[5] == playerSymbol) {
				std::cout << "\n" << playerSymbol << " Wins!";
				return true;
			}

			/*	Bottom Win
			*	_ _ _
			*	_ _ _
			*	X X X
			*/
			else if (vec[6] == playerSymbol && vec[7] == playerSymbol && vec[8] == playerSymbol) {
				std::cout << "\n" << playerSymbol << " Wins!";
				return true;
			}
			/* Diag L-R Win
				X _ _
				_ X _
				_ _ X
			*/
			else if (vec[0] == playerSymbol && vec[4] == playerSymbol && vec[8] == playerSymbol) {
				std::cout << "\n" << playerSymbol << " Wins!";
				return true;
			}

			else if (vec[2] == playerSymbol && vec[4] == playerSymbol && vec[6] == playerSymbol) {
				std::cout << "\n" << playerSymbol << " Wins!";
				return true;
			}


			else if (vec[0] == playerSymbol && vec[3] == playerSymbol && vec[6] == playerSymbol) {
				std::cout << "\n" << playerSymbol << " Wins!";
				return true;
			}
			/* Right Win
			*	_ _ X
			*	_ _ X
			*	_ _ X
			*/
			else if (vec[2] == playerSymbol && vec[5] == playerSymbol && vec[8] == playerSymbol) {
				std::cout << "\n" << playerSymbol << " Wins!";
				return true;
			}
			/* Center Win
			*	_ X _
			*	_ X _
			*	_ X _
			*/
			else if (vec[1] == playerSymbol && vec[4] == playerSymbol && vec[7] == playerSymbol) {
				std::cout << "\n" << playerSymbol << " Wins!";
				return true;
			}
			else {
				//Check for Ties
				std::vector<char> isFilled;
				for (int i = 0; i < vec.size(); i++) {
					if (vec[i] != '_') {
						isFilled.push_back('*');
					}
				}

				if (isFilled.size() == vec.size()) {
					//Tie Game.
					std::cout << "\n" << "\n";
					std::cout << "TIE GAME!";
					return true;
				}
				else {
					//std::cout << "No Win" << isFilled.size();
					if (isFilled.size() > 0) {
						for (int i = isFilled.size(); i > 0; i--) {
							isFilled.pop_back();
						}
					}
					return false;
				}
			}
		}



void userInput(std::string input, std::vector<char>& vec, bool whoseTurn) {
	std::string needHelp = "help";
	if (input == needHelp) {
		help();
		std::cout << "\n" << "Enter Move Here: ";
		std::cin >> input;
		isNumOrString(input, vec, whoseTurn);
	}
	else {
		std::cout << "\n";
		std::cout << "Invalid Input Please try again: ";
		std::cin >> input;
		isNumOrString(input, vec, whoseTurn);
	}
}
//int Overload
void userInput(int input, std::vector<char>& vec, bool whoseTurn) {
	std::string needHelp = "help";
	std::string input2;
	int choice;
	if (input >= 0 && input <= 9) {
		char playerSymbol = turnIdentifier(whoseTurn);
		choice = input;
		if (isSpaceTaken(choice, vec) == true) {
			std::cout << "\n";
			std::cout << "That Space is taken, please try again." << "\n";
			std::cout << "New choice: ";
			std::cin >> input2;
			isNumOrString(input2, vec, whoseTurn);
		}
		else {
			int target = choice - 1;
			vec[target] = playerSymbol;
			//std::cout << "!DEBUG! " << "Vector Slot " << target << "Changed to: " << playerSymbol << ".\n";
			//std::cout << "!DEBUG! " << vec[target];
			std::cout << "\n" << playerSymbol << " captured tile " << choice << ".\n";
		}
	}
	else {
		std::cout << "\n";
		std::cout << "Invalid Input Please try again: ";
		std::cin >> input2;
		isNumOrString(input2, vec, whoseTurn);
	}
}

char turnIdentifier(bool whoseTurn) {
	char playerSymbol;
	if (whoseTurn == 0) {
		playerSymbol = 'O';
	}
	else {
		playerSymbol = 'X';

	}

	return playerSymbol;
}

void isNumOrString(std::string input, std::vector<char>& vec, bool whoseTurn) {
	char playerSymbol = turnIdentifier(whoseTurn);
	std::istringstream iss(input);
	int number;
	char extraChar;
	if (iss >> number && !(iss >> extraChar)) {
		//std::cout << "Number Detected";
		userInput(number, vec, whoseTurn);
	}
	else {
		//std::cout << "String Detected";
		userInput( input, vec, whoseTurn);
	}
}