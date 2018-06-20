#include <iostream>
using namespace std;

int main() {
	double myId = 20275238;
	double numLetters = 4;
	int intResult;
	double doubleResult;
	
	cout.precision(16);

	cout << "My Foothill student ID is " << myId << endl;
	cout << "My last name is Zeng and it has " << numLetters 
		<< " letters" << endl;

	// Expression 1
	intResult = (int) myId % 17;
	cout << myId << " % 17 = " << intResult << endl;

	// Expression 2
	intResult = (int) (numLetters + 17) % 11;
	cout << "(" << numLetters << " + 17) % 11 = " 
		<< intResult << endl;

	// Expression 3
	doubleResult = myId / (numLetters + 800);
	cout << myId << " / (" << numLetters << " + 800) = " 
		<< doubleResult << endl;

	// Expression 4
	intResult = 0;
	for (int i = 1; i < numLetters; i++) {		
		intResult += i;
		cout << i << " + ";
	}
	intResult += (int) numLetters;
	cout << numLetters << " = " << intResult << endl;

	// Expression 5
	doubleResult = 15000 / (80 + (myId - 123456) 
		/ ((numLetters + 20) * (numLetters + 20)));
	cout << "15000 / (80 + (" << myId << " - 123456) / (" 
		<< numLetters << " + 20)^2) = " << doubleResult << endl;

	return 0;
}
