#pragma once
void intro();
void help();
std::string playerNames(std::string pName);
//void pickASquare();
bool isSpaceTaken(int choice, std::vector<char>& vec);
bool checkForWin(std::vector<char>& vec, bool whoseTurn);
void printBoard(std::vector<char>& vec);
template <typename T>
void userInput(T input, std::vector<char>& vec, bool whoseTurn);
char turnIdentifier(bool whoseTurn);
void isNumOrString(std::string input, std::vector<char>& vec, bool whoseTurn);
