#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

int main() {
	string userInput;
	double userNumber;
	cout << "Please enter a number: ";
	cin >> userInput;
	istringstream(userInput) >> userNumber;
	cout << "Here is the square root of " << userNumber << ": ";
	cout << sqrt(userNumber) << endl;
	return 0;
}
