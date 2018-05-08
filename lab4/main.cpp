#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int stamps = 0;
	while (true) {
		cout << "Menu:" << endl;
		cout << "P (Process purchase)" << endl;
		cout << "S (Shut down)" << endl;
		string userInput;
		cin >> userInput;
		cout << "Your choice: " << userInput << endl;
		if (userInput == "p" || userInput == "P") {
			cout << "How many yogurts would you like to buy? ";
			int yogurts;
			cin >> yogurts;
			//int temp;
			//istringstream(userInput) >> temp;
			stamps += yogurts;
			cout << "You just earned " << yogurts << " stamps and have a total of "
				<< stamps << " to use." << endl;  
		} else if (userInput == "s" || userInput == "S") {
			break;
		} else {
			cout << "*** Use P or S, please." << endl;
		}
	}

	return 0;
}
