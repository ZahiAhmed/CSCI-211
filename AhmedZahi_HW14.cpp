//Zahi Ahmed Lab 21G
//HW14 Tower of Hanoi
#include<iostream>
#include<vector>
#include <stdlib.h>
using namespace std;
int main() {
	vector<int> t[3];
	int n;
	cout << "Please enter the number of rings to move: ";
	cin >> n; 
	cout << endl;
	
	//The initial value of to depends on whether n is odd or even
	int from = 0, to, candidate = 1, move = 0;
	
	//Initialize the towers
	for (int x = n + 1; x >= 1; x--)
		t[0].push_back(x);
	t[1].push_back(n + 1);
	t[2].push_back(n + 1);

	if ((n % 2) == 1) to = 1; //check to see if input put is a odd or even number depending on that to will be set to 1 or 2
	else to = 2;
	while (t[1].size()<n + 1) { //while t[1] does not contain all of the rings
		t[to].push_back(t[from].back());
		t[from].pop_back();
		
		//Move the ring from the "from tower" to the "to tower" (first copy it, then delete it from the "from tower")
		cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from + 65) << " to tower " << char(to + 65) << endl;
		
		if (n % 2 == 1) { //if the number is odd
			if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back()) { //get next ?from tower?
				from = (to + 1) % 3;
			}
			else
			{
				from = (to + 2) % 3;
			}// get next to tower
			if (t[(from)].back() < t[(from + 1) % 3].back()) {
				to = (from + 1) % 3;
			} //get next ring
			else
			{
				to = (from + 2) % 3;
			}
			candidate = (t[from].back()); // current tower
		}
		else // if the number is even
		{
			if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back()) {
				from = (to + 1) % 3;
			}
			else
			{
				from = (to + 2) % 3;
			}// get next tower
			if (t[(from)].back() < t[(from + 2) % 3].back()) {
				to = (from + 2) % 3;
			}
			else
			{
				to = (from + 1) % 3;
			}// get next ring

			candidate = (t[from].back()); // get current tower
		}
	}
	return 0;

}
