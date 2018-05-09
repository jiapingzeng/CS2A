#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int CREDITS_PER_REWARD = 7;

int main() {
	string userInput;
	int stamps = 0;
	while (true) {
		cout << "Menu:" << endl;
		cout << "P (Process purchase)" << endl;
		cout << "S (Shut down)" << endl << endl;
		cout << "Your choice: ";
		cin >> userInput;
		cout << endl;
		if (userInput[0] == 'p' || userInput[0] == 'P') {
			if (stamps >= CREDITS_PER_REWARD) {
				// have enough stamps for free yogurt
				cout << "You qualify for a free yogurt. "
					<< "Would you like to use your credits? "
					<< "(Y or N) ";
				cin >> userInput;
				cout << endl;
				if (userInput[0] == 'y' || userInput[0] == 'Y') {
					// use stamps
					stamps -= CREDITS_PER_REWARD;
					cout << "You just used " << CREDITS_PER_REWARD 
						<< " credits and have " << stamps 
						<< " left." << endl;
					cout << "Enjoy your free yogurt." << endl
						<< endl;
					continue;
				}
			}
			cout << "How many yogurts would you like to buy? ";
			cin >> userInput;
			cout << endl;
			int yogurts;
			istringstream(userInput) >> yogurts;
			if (yogurts > 0) {
				// buy yogurts
				stamps += yogurts;
				cout << "You just earned " << yogurts 
					<< " stamps and have a total of "
					<< stamps << " to use." << endl << endl;
			} else {
				// invalid input
				cout << "*** Invalid # yogurts ***" << endl << endl;
			}
		} else if (userInput[0] == 's' || userInput[0] == 'S') {
			// exit program
			break;
		} else {
			cout << "*** Use P or S, please ***" << endl << endl;
		}
	}

	return 0;
}
