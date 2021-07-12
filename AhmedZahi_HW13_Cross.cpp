//Zahi Ahmed Lab 21G
//HW15 Cross Recursion
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
	int cheatsheet[8][5] = {
		{ -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 1, 2, -1 },   // the spot my program with check when given a number
		{ 0, 1, 3, -1 },
		{ 1, 4, -1 },
		{ 2, 3, 4, -1 },
		{ 3, 4, 5, 6, -1 }, };
	for (int x = 0; x < c; x++) if (q[c] == q[x]) return false; // row test and also to make use the number has not been used before
	for (int y = 0; cheatsheet[c][y] != -1; y++) {
		if (1 == abs(q[c] - q[cheatsheet[c][y]])) return false; /* adjacent test, see if the number have a different of 1 if they
																do that mean they are adjacent*/
	}
	return true; // if it pass both test and return true
}
void print(int q[]) {
	static int count = 0;
	cout << "Solution #" << ++count << ": "; cout << endl;
	cout << "  " << q[0] << " " << q[1] << " " << endl;
	cout << q[2] << " " << q[3] << " " << q[4] << " " << q[5] << " " << endl; //print out the solution along with solution number
	cout << "  " << q[6] << " " << q[7] << " " << endl;
}
void next(int q[], int c) {
   if (c == 8)
      print(q);
   else for (q[c] = 1; q[c] < 9; ++q[c])
      if (ok(q, c))
         next(q, c+1);
}

int main() {
   int q[8];
   next(q, 0);
   return 0;
}
