#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

class Student {
    private:
        string lastName;
        string firstName;
        int totalPoints;
    public:
        static const string DEFAULT_NAME;
        static const int DEFAULT_POINTS = 0;
        static const int MAX_POINTS = 1000;
    public:
        Student(string lastName = DEFAULT_NAME,
                string firstName = DEFAULT_NAME,
                int totalPoints = DEFAULT_POINTS);
        string getLastName() { return lastName; }
        string getFirstName() { return firstName; }
        int getTotalPoints() { return totalPoints; }
        bool setLastName(string last);
        bool setFirstName(string first);
        bool setPoints(int points);
        static int compareTwoStudents(Student first, Student second);
        string toString();
    private:
        static bool validString(string testString);
        static bool validPoints(int testPoints);
};

const string Student::DEFAULT_NAME = "zz-error";

class StudentArrayUtilities {
    public:
        static void printArray(string title, Student data[], int arraySize);
        static void arraySort(Student array[], int arraySize);
    private:
        static bool floatLargestToTop(Student data[], int top);
        static void mySwap(Student &a, Student &b);
};

int main() {
    return 0;
}

// Student class method definitions

Student::Student(string last, string first, int points) {
    if (!setLastName(last)) lastName = DEFAULT_NAME;
    if (!setFirstName(first)) firstName = DEFAULT_NAME;
    if (!setPoints(points)) totalPoints = DEFAULT_POINTS;
}

bool Student::setLastName(string last) {
    if (!validString(last)) return false;
    lastName = last;
    return true;
}

bool Student::setFirstName(string first) {
    if (!validString(first)) return false;
    firstName = first;
    return true;
}

bool Student::setPoints(int points) {
    if (!validPoints(points)) return false;
    totalPoints = points;
    return true;
}

int Student::compareTwoStudents(Student first, Student second) {
    return first.getLastName().compare(second.getLastName());
}

string Student::toString() {
    string resultString;
    ostringstream convertFirst, convertLast, convertPoints;
    convertFirst << firstName;
    convertLast << lastName;
    convertPoints << totalPoints;
    resultString = " " + convertLast.str() + ", " + convertFirst.str()
                    + " points: " + convertPoints.str() + "\n";
    return resultString;
}

bool Student::validString(string testString) {
    if (testString.length() > 0 && isalpha(testString[0])) return true;
    return false;
}

bool Student::validPoints(int testPoints) {
    if (testPoints >= 0 && testPoints <= MAX_POINTS) return true;
    return false;
}

// StudentArrayUtilities class method definitions

void StudentArrayUtilities::printArray(String title, Student data[], int arraySize) {
    string output = "";
    cout << title << endl;
    for (int k = 0; k < arraySize; k++) {
        output += " " + data[k].toString();
    }
    cout << output << endl;
}

void StudentArrayUtilities::arraySort(Student array[], int arraySize) {
    for (int k = 0; k < arraySize; k++) {
        if (!floatLargestToTop(array, arraySize - k - 1)) return;
    }
}

bool StudentArrayUtilities::floatLargestToTop(Student data[], int top) {
    bool changed = false;
    for (int k = 0; k < top; k++) {
        if (Student::compareTwoStudents(data[k], data[k+1] > 0)) {
            mySwap(data[k], data[k+1]);
            changed = true;
        }
    }
    return changed;
}

void StudentArrayUtilities::mySwap(Student &a, Student &b) {
    Student temp("", "", 0);
    temp = a;
    a = b;
    b = temp;
}