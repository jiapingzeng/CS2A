#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// class Student prototype -----------------------
class Student
{
  private:
    string lastName;
    string firstName;
    int totalPoints;
    static int sortKey;

  public:
    static const string DEFAULT_NAME;
    static const int DEFAULT_POINTS = 0;
    static const int MAX_POINTS = 1000;
    static const int SORT_BY_FIRST = 88;
    static const int SORT_BY_LAST = 98;
    static const int SORT_BY_POINTS = 108;

  public:
    Student(string lst = DEFAULT_NAME, string fst = DEFAULT_NAME,
            int pts = DEFAULT_POINTS);

    // accessors and mutators
    string getLastName() { return lastName; }
    string getFirstName() { return firstName; }
    int getTotalPoints() { return totalPoints; }
    static int getSortKey() { return sortKey; }

    bool setLastName(string last);
    bool setFirstName(string first);
    bool setPoints(int pts);
    static bool setSortKey(int key);

    static int compareTwoStudents(Student firstStud, Student secondStud);
    string toString();

  private:
    static bool validString(string testStr);
    static bool validPoints(int testPoints);

}; // end of class Student prototype --------------

// class StudentArrayUtilities prototype -----------------------
class StudentArrayUtilities
{
  public:
    static const int MAX_STUDENTS = 20;

  private:
    Student theArray[MAX_STUDENTS];
    int numStudents = 0;

  public:
    string toString(string title);
    void arraySort();
    double getMedianDestructive();
    bool addStudent(Student stud);
    Student removeStudent();

  private:
    bool floatLargestToTop(Student data[], int top);
    static void mySwap(Student &a, Student &b);
};

// static initializations that can't be done in-line
int Student::sortKey = SORT_BY_LAST;
const string Student::DEFAULT_NAME = "zz-error";

int main()
{
    int k;
    Student myClass[] =
    {
        Student("smith", "fred", 95), Student("bauer", "jack", 123),
        Student("jacobs", "carrie", 195), Student("renquist", "abe", 148),
        Student("3ackson", "trevor", 108), Student("perry", "fred", 225),
        Student("loceff", "fred", 44), Student("stollings", "pamela", 452),
        Student("charters", "rodney", 295), Student("cassar", "john", 321),
        Student("d2", "r2", 242), Student("bye", "hi", 289),
        Student("chicken", "fried", 724), Student("srfg31", "rrrr", 222),
        Student("ctgb", "rfrw", 224), Student("cyhjear", "jyw", 241)
    };

    Student student;
    int arraySize = sizeof(myClass) / sizeof(myClass[0]);

    // instantiate an SAU object
    StudentArrayUtilities myStuds;

    // we can add stdunts manually and individually
    myStuds.addStudent(Student("bartman", "petra", 102));
    myStuds.addStudent(Student("charters", "rodney", 295));

    // if we happen to have an array available, we can add students in loop.
    for (k = 0; k < arraySize; k++)
        myStuds.addStudent(myClass[k]);

    cout << myStuds.toString("Before: ");

    myStuds.arraySort();
    cout << myStuds.toString("After default sort: ");

    Student::setSortKey(Student::SORT_BY_FIRST);
    myStuds.arraySort();
    cout << myStuds.toString("After sort by first: ");

    // test median
    cout << "Median of evenClass = "
         << myStuds.getMedianDestructive()
         << endl;

    // various tests of removing and adding too many students
    for (k = 0; k < 100; k++)
    {
        student = myStuds.removeStudent();
        if (Student::compareTwoStudents(student, Student()))
            cout << "Removed " << student.toString();
        else
        {
            cout << "Empty after " << k << " removes." << endl;
            break;
        }
    }

    for (k = 0; k < 100; k++)
    {
        if (!myStuds.addStudent(Student("first", "last", 22)))
        {
            cout << "Full after " << k << " adds." << endl;
            break;
        }
    }
}

// beginning of Student method definitions -------------

// constructor requires parameters - no default supplied
Student::Student(string last, string first, int points)
{
    if (!setLastName(last))
        lastName = DEFAULT_NAME;
    if (!setFirstName(first))
        firstName = DEFAULT_NAME;
    if (!setPoints(points))
        totalPoints = DEFAULT_POINTS;
}

bool Student::setLastName(string last)
{
    if (!validString(last))
        return false;
    lastName = last;
    return true;
}

bool Student::setFirstName(string first)
{
    if (!validString(first))
        return false;
    firstName = first;
    return true;
}

bool Student::setPoints(int pts)
{
    if (!validPoints(pts))
        return false;
    totalPoints = pts;
    return true;
}

bool Student::setSortKey(int key)
{
    if (key == SORT_BY_FIRST || key == SORT_BY_LAST || key == SORT_BY_POINTS)
    {
        sortKey = key;
        return true;
    }
    return false;
}

// could be an instance method and, if so, would take one parameter
int Student::compareTwoStudents(Student firstStud, Student secondStud)
{
    switch (sortKey)
    {
    case SORT_BY_FIRST:
        return firstStud.firstName.compare(secondStud.firstName);
    case SORT_BY_LAST:
        return firstStud.lastName.compare(secondStud.lastName);
    case SORT_BY_POINTS:
        return firstStud.totalPoints - secondStud.totalPoints;
    default:
        // this part shouldn't execute since sortKey always
        // has valid value
        cout << "Something went wrong" << endl;
        return -1;
    }
}

string Student::toString()
{
    string resultString;
    ostringstream cnvrtFirst, cnvrtLast, cnvrtPoints;

    cnvrtFirst << firstName;
    cnvrtLast << lastName;
    cnvrtPoints << totalPoints;

    resultString = " " + cnvrtLast.str() + ", " + cnvrtFirst.str() + " points: " + cnvrtPoints.str() + "\n";
    return resultString;
}

bool Student::validString(string testStr)
{
    if (testStr.length() > 0 && isalpha(testStr[0]))
        return true;
    return false;
}

bool Student::validPoints(int testPoints)
{
    if (testPoints >= 0 && testPoints <= MAX_POINTS)
        return true;
    return false;
}
// end of Student method definitions  --------------

// beginning of StudentArrayUtilities method definitions -------------

// print the array with string as a title for the message box
// this is somewhat controversial - we may or may not want an I/O
// methods in this class.  we'll accept it today
string StudentArrayUtilities::toString(string title)
{
    string output = "";

    output += title + "\n";

    // build the output string from the individual Students:
    for (int k = 0; k < numStudents; k++)
        output += " " + theArray[k].toString();

    return output;
}

void StudentArrayUtilities::arraySort()
{
    for (int k = 0; k < numStudents; k++)
        // compare with method def to see where inner loop stops
        if (!floatLargestToTop(theArray, numStudents - 1 - k))
            return;
}

double StudentArrayUtilities::getMedianDestructive()
{
    int saved = Student::getSortKey();
    Student::setSortKey(Student::SORT_BY_POINTS);
    arraySort();
    // calculate result
    double result;
    if (numStudents == 0)
        result = 0;
    else if (numStudents == 1)
        result = theArray[0].getTotalPoints();
    else if (numStudents % 2 == 0)
    {
        // size is even
        int mid = numStudents / 2;
        result = (theArray[mid - 1].getTotalPoints() + theArray[mid].getTotalPoints()) / 2.0;
    }
    else
    {
        // size is odd
        result = theArray[numStudents / 2].getTotalPoints();
    }
    Student::setSortKey(saved);
    return result;
}

bool StudentArrayUtilities::addStudent(Student stud)
{
    // push new student
    if (MAX_STUDENTS > numStudents)
    {
        theArray[numStudents] = stud;
        numStudents++;
        return true;
    }
    else
        return false;
}

Student StudentArrayUtilities::removeStudent()
{
    // pop first student
    if (numStudents > 0)
        return theArray[--numStudents];
    else
        return Student();
}

// returns true if a modification was made to the array
bool StudentArrayUtilities::floatLargestToTop(Student data[], int top)
{
    bool changed = false;

    // compare with client call to see where the loop stops
    for (int k = 0; k < top; k++)
        if (Student::compareTwoStudents(data[k], data[k + 1]) > 0)
        {
            mySwap(data[k], data[k + 1]);
            changed = true;
        }
    return changed;
}

void StudentArrayUtilities::mySwap(Student &a, Student &b)
{
    Student temp("", "", 0);

    temp = a;
    a = b;
    b = temp;
}

// end of StudentArrayUtilities method definitions  --------------