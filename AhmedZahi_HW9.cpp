//Zahi Ahmed Lab 21G
//HW9 Fancy
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdlib.h>
using namespace std;
bool ok(int q[], int col) { // return true or flase depending on the if statement
	for (int i = 0; i < col; i++) {
		if (q[i] == q[col] || (col - i) == (abs(q[col] - q[i]))) {
			return false; // all the test to check if thier is a queen thier, check the diagonal and row
		}
	}
	return true;
}
void backtrack(int &col) {
	col--; // col down by 1 vaule
	if (col == -1) {// if col is -1 exit program
		exit(1);
	}
}

void print(int q[]) {
	static int sol = 1; //delcare a var
	typedef char box[5][7]; // set limit of box which became a type beucase of type def
	box bb, wb, *board[8][8]; //set up 3 boards
	char ws = char(219);
	cout << "Solution " << sol++ << endl << endl; // print solution
	box blackqueen =
	{
		ws, ws, ws, ws, ws, ws, ws,
		ws, ' ', ws, ' ', ws, ' ', ws,
		ws, ' ', ' ', ' ', ' ', ' ', ws,
		ws, ws, ws, ' ', ws, ws, ws,
		ws, ' ', ' ', ' ', ' ', ' ', ws
	};// make the the black queen icon

	box whitequeen =
	{
		' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ws, ' ', ws, ' ', ws, ' ',
		' ', ws, ws, ws, ws, ws, ' ',
		' ', ' ', ' ', ws, ' ', ' ', ' ',
		' ', ws, ws, ws, ws, ws, ' '
	};//make the white queen icon
	for (int x = 0; x<5; x++)
		for (int j = 0; j<7; j++)
		{
			wb[x][j] = ' ';
			bb[x][j] = char(219); // create the black boxes using nested for loops
		}
	for (int x = 0; x<8; x++)
		for (int j = 0; j<8; j++)
			if ((x + j) % 2 == 0) {
				if (q[x] == j) {
					board[x][j] = &whitequeen; //print the whitequeen
				}
				else {
					board[x][j] = &wb;// print space white
				}
			}
			else {
				if (q[x] == j) {
					board[x][j] = &blackqueen; //print the blackqueen 
				}
				else {
					board[x][j] = &bb; // print space black
				}// make the board with black and white title and place the color queen in the the spot were they belong
			}
			cout << " ";
			for (int x = 0; x < 7 * 8; x++) {
				cout << '_'; //print upper boarder
			}
			cout << endl;
			for (int i = 0; i<8; i++)
				for (int k = 0; k<5; k++) // print the whole baord
				{
					cout << " " << char(179); //print left border
					for (int j = 0; j<8; j++)
						for (int l = 0; l<7; l++)
							cout << (*board[i][j])[k][l];
					cout << char(179) << endl; // at end of line print bar and then newline
				}
			cout << " ";
			for (int i = 0; i<7 * 8; i++)
				cout << char(196); //lower boarder
			cout << endl;
}
int main() {
	int q[8]; q[0] = 0; int col = 1; // declare the vaule of the board and queen 
	bool from_backtrack = false; //declare var bracktrack equal false
	while (true) { // start loop
		while (col < 8) { // another loop
			if (!from_backtrack) //if not flase
				q[col] = -1; //set q col to -1
			from_backtrack = false; // set backtrack to flase again
			while (q[col] < 8) { // another while loop
				q[col]++; // increase vaule by 1
				while (q[col] == 8) {// if col equal 8 does the task in {}
					backtrack(col); // send col vaule to backtrack function
					q[col]++;
				}
				if (ok(q, col)) break; // break statement if it true
			}
			col++;
		}
		print(q); // print board
		backtrack(col); // send col vaule to backtrack
		from_backtrack = true;// set backtrack to true
	}
}
