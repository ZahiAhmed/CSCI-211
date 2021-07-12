#include<iostream>
using namespace std;


const int NUM_ROWS = 5;
const int NUM_COLS = 6;
int path[] = { 6 };

//Returns the cost of the shortest path from the left to the square in the row i, column j.
int calculateCost(int i, int j) { 
	int weight[NUM_ROWS][NUM_COLS] = {
		{3,4,1,2,8,6},
		{6,1,8,2,7,4},	
		{5,9,3,9,9,5},
		{8,4,1,3,2,6},
		{3,7,2,8,6,4}};
	
	static int memo[NUM_ROWS][NUM_COLS] = {
		{3,0,0,0,0,0},
		{6,0,0,0,0,0},
		{5,0,0,0,0,0},
		{8,0,0,0,0,0},
		{3,0,0,0,0,0}};

	//Recursive part
	if (j == 0)
		return memo[i][0];
	
	if (memo[i][j] != 0)
		return memo[i][j];
	
	//Calculate the costs of teh 3 adjacent squares by calling the function recursively.
	int up = weight[i][j] + calculateCost(i - 1 >= 0 ? i - 1 : NUM_ROWS - 1, j - 1);
	int left = weight[i][j] + calculateCost(i, j - 1);
	int down = weight[i][j] + calculateCost(i + 1 <= NUM_ROWS - 1 ? i + 1 : 0, j - 1);

	int minCost = left; 
	
	if (up < minCost)
		minCost = up;
	
	if (down < minCost)
		minCost = down;
	return memo[i][j] = minCost;
}

int main() {
	int ex[NUM_ROWS];
	for (int i = 0; i<NUM_ROWS; i++)
		ex[i] = calculateCost(i, NUM_COLS - 1);
	int minRow = ex[0];
	for (int i = 1; i<NUM_ROWS; i++)
		if (ex[i] < minRow)
			minRow = ex[i];
	cout << "The length of the shortest path is " << minRow << "." << endl;
	return 0;
}
