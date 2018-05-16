#include <iostream>
using namespace std;

const char MASK = '*';
const int MIN_CHARS = 4;
const int MAX_CHARS = 500;

char getKeyCharacter() {
    while (true) {
        cout << "Please enter a SINGLE character to act as key: ";
        string userInput;
        getline(cin, userInput);
        if (userInput.length() == 1) {
            return userInput[0];
        } else {
            cout << "Invalid input. Please try again." << endl;
        }
    }
}

string getString() {
    while (true) {
        cout << "Please enter a phrase or " 
            << "sentence >= 4 and <= 500 characters: ";
        string userInput;
        getline(cin, userInput);
        if (userInput.length() < MIN_CHARS) {
            cout << "Invalid input. Please include more characters." << endl;
        } else if (userInput.length() > MAX_CHARS) {
            cout << "Invalid input. Please use more characters." << endl;
        } else {
            return userInput;
        }
    }
}

string maskCharacter(string theString, char keyCharacter) {
    string newString = "";
    for (int i = 0; i < theString.length(); i++) {
        if (theString[i] == keyCharacter) {
            newString += MASK;
        } else {
            newString += theString[i];
        }
    }
    return newString;
}

string removeCharacter(string theString, char keyCharacter) {
    string newString = "";
    for (int i = 0; i < theString.length(); i++) {
        if (theString[i] != keyCharacter) {
            newString += theString[i];
        }
    }
    return newString;
}

int countKey(string theString, char keyCharacter) {
    int count = 0;
    for (int i = 0; i < theString.length(); i++) {
        if (theString[i] == keyCharacter) {
            count++;
        }
    }
    return count;
}

int main() {
    // get user inputs
    char keyCharacter = getKeyCharacter();
    string theString = getString();
    cout << endl;
    
    // mask character in string
    cout << "String with key character, '" << keyCharacter 
        << "' masked: " << endl;
    cout << maskCharacter(theString, keyCharacter) << endl << endl;

    // remove character in string
    cout << "String with '" << keyCharacter << "' removed: " << endl;
    cout << removeCharacter(theString, keyCharacter) << endl << endl;
    
    // count character in string
    cout << "# of occurences of key character, '" << keyCharacter 
        << "': ";
    cout << countKey(theString, keyCharacter) << endl;
    
    return 0;
}
