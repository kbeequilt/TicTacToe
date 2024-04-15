//
// Created by chase on 4/14/2024.
//

#ifndef TICTACTOE_CGTICTACHEAD_HPP
#define TICTACTOE_CGTICTACHEAD_HPP

const int NINE = 9;

void displayInstructions();
void initBoard(int (&myArray)[NINE]);
void showBoard(int const myArray[]);
void getMove(int (&myArray)[NINE], int player);
bool checkWin(int const myArray[]);
bool checkDraw(int const myArray[]);
bool playAgain(char answer);
int getNumber(int min, int max);
bool yesNo(char answer);

#endif //TICTACTOE_CGTICTACHEAD_HPP
