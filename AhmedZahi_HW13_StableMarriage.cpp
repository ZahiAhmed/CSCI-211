//Zahi Ahmed Lab 21G
//HW15 Stable Marriage Recursion
#include <iostream>
#include <cstdlib>
using namespace std;

bool ok(int q[], int col) {
	int newman = col, // man eqauls col
		newwomen = q[col]; // women equals q[col]
	int manrate[3][3] = {
		{ 0,2,1 }, //man preferences
		{ 0,2,1 },
		{ 1,2,0 } };
	int womanrate[3][3] = {
		{ 2,1,0 }, //women preferences
		{ 0,1,2 },
		{ 2,0,1 } };

	for (int i = 0; i < col; ++i) {
		int cm = i,    // make current man and woman var using i  
			cw = q[i];
		//the next three if statements check if the pair work
		if (cw == newwomen) return false; // if cw (current women) equal newwomen retrun flase
		if ((manrate[cm][newwomen] < manrate[cm][cw]) && (womanrate[newwomen][cm] < womanrate[newwomen][newman])) return false; // using man and women rate array to check if the man and woman love each other
		if ((manrate[newman][cw] < manrate[newman][newwomen]) && (womanrate[cw][newman] < womanrate[cw][cm])) return false; // same as the above code

	}
	return true; // if pass the test return true
}

void print(int q[]) {//when called the array called will be printed out the solution in a chart
	static int count = 1;
	cout << "Solution #" << count++ << endl;
	cout << "Man" << " " << "Woman" << endl;
	for (int i = 0; i<3; i++) {
		cout << i << "     " << q[i];
		cout << endl;
	}
	cout << endl;
}
void next(int q[], int i) {
	if (i == 3) { //if i = 3 print out board
		print(q);
		return;
	}
	for (int x = 0; x < 3; x++) { // used to rotate the numbers
		q[i] = x;
		if (ok(q, i))
			next(q, i + 1);
	}
}
int main() {
	int q[3]; q[0]; //declare var
	next(q, 0); // start the program
}
