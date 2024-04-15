//
// Created by chase on 4/14/2024.
//
#include <iostream>
#include "CGTICTACHEAD.hpp"
using std::cout, std::cin, std::endl;

void displayInstructions(){
    //this static bool's job is to be false the first time this function plays and then always be true afterward
    static bool simple = false;
    if (!simple) {
        cout << "Welcome to TicTacToe!" << endl << endl
             <<"------------------------------------------------------------------------" << endl
             << "How To Play TicTacToe" << endl
             << "On a players turn they choose a square to play either X or O" << endl
             << "you choose from 1 - 9, each corrisponding with a square" << endl
             << "Three in a row and you win!" << endl
             <<"------------------------------------------------------------------------" << endl << endl;
        simple = true;
    }else{
        cout << endl << endl <<"Three in a row to win!" << endl << endl;
    }

}

//sets everything in the board to 0
void initBoard(int (&myArray)[NINE]){
    for(int i = 0; i <= 8; i++){
        myArray[i] = 0;
    }

}

void showBoard(int const myArray[NINE]){
    //this array is the array that makes the board look like the board
    char boardArray[NINE] = {};
    //I make the int array into a char array depending on what the reference is.
    for(int i = 0; i <= 8; i++){
        if (myArray[i] == 0){
            boardArray[i] = ' ';
        }else if(myArray[i] == 1){
            boardArray[i] = 'X';
        }else if(myArray[i] == 2){
            boardArray[i] = 'O';
        }
    }
    //this outputs everything
    cout << "[" << boardArray[0] << "]" << "[" << boardArray[1] << "]" <<"[" << boardArray[2] << "]" << endl;
    cout << "[" << boardArray[3] << "]" << "[" << boardArray[4] << "]" <<"[" << boardArray[5] << "]" << endl;
    cout << "[" << boardArray[6] << "]" << "[" << boardArray[7] << "]" <<"[" << boardArray[8] << "]" << endl;
}

//this grabs moves, checks if valid, and changes the array to match the move
void getMove(int (&myArray)[NINE], int player){
    int move;
    bool loop = false;
    while (!loop) {
        move = getNumber(1, 9) - 1;
        if (player == 1 && myArray[move] == 0) {
            myArray[move] = 1;
            loop = true;
        } else if (player == 2 && myArray[move] == 0) {
            myArray[move] = 2;
            loop = true;
        }else{
            cout << "Invalid Move, space already taken " << endl;
        }
    }
}

//hard coded every win condition.
bool checkWin(int const myArray[]){
    bool isOver = false;
    //horizontal
    if((myArray[0] != 0 && myArray[1] != 0 && myArray[2] != 0) && (myArray[0] == myArray[1] && myArray[0] == myArray[2])) {
        isOver = true;
        return isOver;
    }
    if((myArray[3] != 0 && myArray[4] != 0 && myArray[5] != 0) && (myArray[3] == myArray[4] && myArray[3] == myArray[5])) {
        isOver = true;
        return isOver;
    }
    if((myArray[6] != 0 && myArray[7] != 0 && myArray[8] != 0) && (myArray[6] == myArray[7] && myArray[6] == myArray[8])) {
        isOver = true;
        return isOver;
    }
    //vertical
    if((myArray[0] != 0 && myArray[3] != 0 && myArray[6] != 0) && (myArray[0] == myArray[3] && myArray[0] == myArray[6])) {
        isOver = true;
        return isOver;
    }
    if((myArray[1] != 0 && myArray[4] != 0 && myArray[7] != 0) && (myArray[1] == myArray[4] && myArray[1] == myArray[7])) {
        isOver = true;
        return isOver;
    }
    if((myArray[2] != 0 && myArray[5] != 0 && myArray[8] != 0) && (myArray[2] == myArray[5] && myArray[2] == myArray[8])) {
        isOver = true;
        return isOver;
    }
    //diagonal
    if((myArray[0] != 0 && myArray[4] != 0 && myArray[8] != 0) && (myArray[0] == myArray[4] && myArray[0] == myArray[8])) {
        isOver = true;
        return isOver;
    }
    if((myArray[2] != 0 && myArray[4] != 0 && myArray[6] != 0) && (myArray[2] == myArray[4] && myArray[2] == myArray[6])) {
        isOver = true;
        return isOver;
    }
    return isOver;
}

//if any space has a zero in it, it cannot be a draw
bool checkDraw(int const myArray[]){
    for(int i = 0; i <= 8; i++){
        if(myArray[i] == 0){
            return false;
        }
    }
    return true;
}

//
bool playAgain(char answer){
    return yesNo(answer);
}
