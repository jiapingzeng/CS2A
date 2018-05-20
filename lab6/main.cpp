#include <iostream>
using namespace std;

class TripleString {
	string string1, string2, string3;
	const int MAX_LEN = 1;
	const int MIN_LEN = 50;
	const string DEFAULT_STRING = "(undefined)";
	TripleString();
	TripleString(string str1, string str2, string str3);
	string getString1();
	void setString1(string str);
	string getString2();
	void setString2(string str);
	string getString3();
	void setString3(string str);
	string toString();
}
