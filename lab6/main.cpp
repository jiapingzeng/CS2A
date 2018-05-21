#include <iostream>
using namespace std;

class TripleString {
	public:
		string string1, string2, string3;
		const int MAX_LEN = 50;
		const int MIN_LEN = 1;
		const string DEFAULT_STRING = "(undefined)";
		TripleString();
		TripleString(string str1, string str2, string str3);
		string getString1();
		bool setString1(string str);
		string getString2();
		bool setString2(string str);
		string getString3();
		bool setString3(string str);
		string toString();
	private:
		bool validString(string str);
		bool setString(string &str, string val);
};

int main() {
	TripleString ts1, ts2, ts3;
	TripleString ts4 ("1", "2", "3");
	TripleString ts5 ("a", "b", "c");
	ts1.setString1("fdas");
	cout << ts1.toString() << endl;
	cout << ts2.toString() << endl;
	cout << ts3.toString() << endl;
	cout << ts4.toString() << endl;
	cout << ts5.toString() << endl;
}

TripleString::TripleString() {
	string1 = DEFAULT_STRING;
	string2 = DEFAULT_STRING;
	string3 = DEFAULT_STRING;
}

TripleString::TripleString(string str1, string str2, string str3) {
	string1 = validString(str1) ? str1 : DEFAULT_STRING;
	string2 = validString(str2) ? str2 : DEFAULT_STRING;
	string3 = validString(str3) ? str3 : DEFAULT_STRING;
}

string TripleString::getString1() {
	return string1;
}

bool TripleString::setString1(string str) {
	return setString(string1, str);
}

string TripleString::getString2() {
	return string2;
}

bool TripleString::setString2(string str) {
	return setString(string2, str);
}

string TripleString::getString3() {
	return string3;
}

bool TripleString::setString3(string str) {
	return setString(string3, str);
}

string TripleString::toString() {
	return string1 + ", " + string2 + ", " + string3;
}

bool TripleString::setString(string &str, string val) {
	if (validString(val)) {
		str = val;
		return true;
	}
	return false;
}

bool TripleString::validString(string str) {
	return str.length() >= MIN_LEN && str.length() <= MAX_LEN;
}