/*
Lab # 1
Name: Chase Greenhalgh
Date: 4/14/2024
IDE: Clion
Version: 1.0
Description: For this exercise, you will create a Tic-Tac-Toe game for two players.
An optional enhancement would be to create a computer opponent.
While this program is an introduction to arrays, it will also be a quick review of functions and input validation.

*/

#include <iostream>
#include "CGTICTACHEAD.hpp"
using std::cout, std::cin, std::endl;

int main() {
    // outer repeat loop
    int board[NINE] = {};
    int player;
    bool win;
    bool tie;
    char playAgainAnswer;
    do {
        //setting the player to player 1
        player = 1;
        tie = false;
        // display instruction
        displayInstructions();

        // set up game
        initBoard(board);
        // inner game loop
        do {
            // display board
            showBoard(board);
            // get next move and update board
            getMove(board, player);
            // check for win
            win = checkWin(board);
            // check for tie
            if(!win){
                tie = checkDraw(board);
            }
            // if game not over, swap player
            if (!win && !tie){
                player = (player == 1)?2:1;
            }
        } while (!win && !tie);

        // display final board and congratulate winner
        showBoard(board);
        if(win){
            cout << "Player " << player << " won! Do you want to play again?(Y/N)" << endl;
        }else{
            cout << "Tie game... Do you want to play again?(Y/N)" << endl;
        }
        cin >> playAgainAnswer;
        playAgainAnswer = playAgain(playAgainAnswer);

    } while (playAgainAnswer);

    return 0;

}
