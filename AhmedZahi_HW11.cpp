//Zahi Ahmed 21G
//HW11 n queens
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
using namespace std;

bool ok(int q[], int col) { // check if a queen can be placed in that spot
	for (int x = 0; x < col; x++)
		if (q[col] == q[x] || (col - x) == abs(q[col] - q[x])) { // row and diaganol test
			return false;
		}
	return true;
}
int main() {
	int x;
	cout << "This Program will tell you the soluton to each board with # of size untill it hit the max size of q size!" << endl;
	cout << "How many queens are there: "; // ask user for the size of the queen baord problem
	cin >> x;

	for (int i = 1; i <= x; i++) { // for loop goes to size x
		int *q = new int[i]; // make a temp array
		q[0] = 1; // gave q[0] variable of 1
		int count = -1; // set count to -1
		int col = 0; // set column to 0
		bool from_backtrack = false;
		while (true) {
			while (col<i) {
				if (!from_backtrack)
					q[col] = -1; //gave q[c] to -1
				from_backtrack = true; //set variable
				while (q[col]<i) {
					q[col]++; // increase value
					if (q[col] == i) {
						from_backtrack = true;
						col--; // decrease var
						break; // breack out the if
					}
					if (ok(q, col)) {
						from_backtrack = false;//set variable
						col++; // increase variable
						break;
					}
				}
				if (col == -1)break; // break the loop
			}
			count++; // incrase variable by 1
			col--; // decrease column  by 1
			from_backtrack = true;//set variable
			if (col <= -1)break; // break out the while true
		}
		delete[]q; // delete the temp array
		cout << "there are " << count << " solutions to " << i << " Qs Problem." << endl; //output ans
	}
	return 0;
}
