#include <iostream>
using namespace std;
#include <cmath>
#include "Functions.cpp"

string checkNeighbors(int array[10][3], int row, int col);

int main() {
    string name1, name2, result;
    int row, column;

    cout << "Welcome to Two Player Jenga!" << endl <<"Please enter Player 1's name:";
    cin >> name1;
    cout << "Please enter Player 2's name:";
    cin >> name2;

    // Makes an array with a height of 10 and a width of 3
    int array[10][3];

    // Sets all the values in the array to 1
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            array[i][j] = 1;
        }
    }

    // Prints the array
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    // The game begins
    do{
        //Starts with Player 1's turn
        cout << endl << endl;
        cout << name1 << "'s turn! Please input the row of the piece you would like to pull out: ";
        cin >> row;
        row = row - 1;
        cout << "Now input the column of the piece you would like to pull out: ";
        cin >> column;
        column = column - 1;
        // Calls the function to check values around the coordinate
        result = checkNeighbors(array, row, column);
        cout << result << endl;

        // Checks if the tower should fall
        if (result == "success") {
            array[row][column] = 0;
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 3; ++j) {
                    cout << array[i][j] << " ";
                }
                cout << endl;
            }
        }
        else {
            cout << "The tower fell! You lost :(" << endl;
        }

        // Player 2's turn now
        cout << endl << endl;
        cout << name2 << "'s turn! Please input the row of the piece you would like to pull out: ";
        cin >> row;
        row = row - 1;
        cout << "Now input the column of the piece you would like to pull out: ";
        cin >> column;
        column = column - 1;
        // Calls the function to check values around the coordinate
        result = checkNeighbors(array, row, column);
        cout << result << endl;

        // Checks if the tower should fall
        if (result == "success") {
            array[row][column] = 0;
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 3; ++j) {
                    cout << array[i][j] << " ";
                }
                cout << endl;
            }
        }
        else {
            cout << "The tower fell! You lost :(" << endl;
        }
    } while (result != "fail");


}
