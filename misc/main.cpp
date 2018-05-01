#include <iostream>
using namespace std;

int main() {
	string userInput;
	cout << "Hello! What is your major? ";
	cin >> userInput;
	cout << "Cool!";
	// a single if statement is sufficient here because we only want
	// to respond if this specific condition is met
	if (userInput == "CS") {
		cout << " Me too!";
	}
	cout << endl << "Please enter \"continue\" to continue: ";
	cin >> userInput;
	// an if-else statement works better here because we want to 
	// display a message even if the user enters something wrong, and 
	// since we don't know what the user is going to enter, the else 
	// statement helps a lot
	if (userInput == "continue") {
		cout << "Performing secret action" << endl;
	} else {
		cout << "Wrong response. Exiting." << endl;
	}
	return 0;
}
