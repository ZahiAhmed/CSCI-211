//Zahi Ahmed Lab 21G
//HW16 k bishops
#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
bool ok(int q[], int col, int board) { // check to see if the statement is true or not
	for (int x = 0; x<col; x++)
		if (q[x] / board + q[x] % board == q[col] / board + q[col] % board || q[x] / board - q[x] % board == q[col] / board - q[col] % board)
			return false;
	return true;
}
int factorial(int board) { // find the fatorial
	if (board == 1) return board;
	return board*factorial(board - 1);
}
void backtrack(int &col, int count, int board, int q[]) { //declare column by 1
	int bishops = board;
	col--;
	if (col == -1) {// one column is -1 print solution
		cout << "Number of Solutions:  " << count / factorial(board) << endl;
		delete[]q;
		system("pause");
		exit(1); //print out the ans and exits
	}
}
int main() {
	int col = 1, count = 0, board = 0, bishops = 0; // declare variable
	bool from_backtrack = false;
	cout << "Please enter a board size: ";
	cin >> board; // taking in board size
	cout << "Enter the amount of bishops: ";
	cin >> bishops;//take in the amount of bishop
	int* q = new int[bishops];
	q[0] = 0; // used to store the ans

	while (true) {
		while (col<bishops) {
			if (!from_backtrack)
				q[col] = -1; //q[col] set to -1;
			from_backtrack = false;
			while (q[col]<board*board) {
				q[col]++;
				if (q[col] == board*board) { // if statement is met
					backtrack(col, count, bishops, q); // pass parameter into backtrack
					from_backtrack = true;
					continue;
				}
				if (ok(q, col, board)) {
					col++; //column increase by 1
					break; // break if the statement is true
				}
			}
		}
		count++;// count increases by 1
		backtrack(col, count, bishops, q); // backtrack the variable
		from_backtrack = true;
	}
	system("pause");
	return 0;
}
