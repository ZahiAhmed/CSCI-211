#include <iostream>
using namespace std;
	
int main() {
	int x, y, w;
	int z=0;
	while (true){ 
		w=z*z;
		x=w%10;
		y=(w/10)%10;
		z++;
		if (x%2!=0 && y%2!=0)
			break;

	}
	cout << w << endl;
	return 0;
}



