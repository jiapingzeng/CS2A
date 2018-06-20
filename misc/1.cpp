#include <iostream>
#include <math.h>
using namespace std;

int main() {

	cout.precision(18);

	cout << "This is the value of pi from the math.h library:" << endl;
	cout << M_PIl << endl;

	cout << "Here is pi casted as a double:" << endl;
	cout << (double) M_PIl << endl;

	cout << "Here is pi casted as a float:" << endl;
	cout << (float) M_PIl << endl;
		
	return 0;
}
