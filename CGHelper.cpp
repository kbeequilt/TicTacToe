#include <iostream>
#include "CGTICTACHEAD.hpp"
using std::cin, std::cout, std::endl;

//grabs any number with a min and a max
int getNumber(int min, int max){
    int number;
    cout << "Input number between " << min << " and " << max << endl;
    cin >> number;

    //data validation
    while(!cin || number < min || number > max){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid number, pick a new number" << endl;
        cin >> number;
    }
    return number;
}

//checks your yes and no answers
bool yesNo(char answer){
    while (true){
        //toupper makes everything capital
        answer = toupper(answer);
        if(answer == 'Y'){
            return true;
        }
        else if (answer == 'N'){
         return false;
        }
        //data validation
        else{
            cin.clear();
            cin.ignore(100, '\n');
            cout << "invalid input, input either Y/N" << endl;
            cin >> answer;
        }

    }

}

