#include <iostream>
#include <string.h>
#include <ctype.h>
#include <cmath>
using namespace std;

class DateProfile {
    public:
        // range limits
        static const int MIN_ROMANCE, MAX_ROMANCE, MIN_FINANCE,
                        MAX_FINANCE, MIN_NAME_LEN, MAX_NAME_LEN;
        // default values
        static const char DEFAULT_GENDER, DEFAULT_SEARCH_GENDER;
        static const int DEFAULT_ROMANCE, DEFAULT_FINANCE;
        static const string DEFAULT_NAME;
        // default constructor
        DateProfile();
        // parametereized constructor
        DateProfile(char gender, char searchGender, int romance,
                    int finance, string name);
        // accessors
        char getGender();
        char getSearchGender();
        int getRomance();
        int getFinance();
        string getName();
        // mutators
        void setGender(char gender);
        void setSearchGender(char searchGender);
        void setRomance(int romance);
        void setFinance(int finance);
        void setName(string name);
        // other functions
        void setAll(char gender, char searchGender, int romance,
                    int finance, string name);
        void setDefaults();
        double fitValue(DateProfile partner);
        double determineGenderFit(DateProfile partner);
        double determineRomanceFit(DateProfile partner);
        double determineFinanceFit(DateProfile partner);
    private:
        // instance variables
        char gender, searchGender;
        int romance, finance;
        string name;
};

const string LINE = "------------------------------------------";

void printFit(DateProfile dp1, DateProfile dp2) {
    cout << "Fit between " << dp1.getName() << " and " << dp2.getName()
        << ": " << dp1.fitValue(dp2) << endl;
}

int main() {
    cout.precision(3);
    DateProfile dp1 ('m', 'f', 9, 3, "dude 1");
    DateProfile dp2 ('m', 'f', 7, 2, "dude 2");
    DateProfile dp3 ('f', 'm', 1, 8, "gal 1");
    DateProfile dp4 ('f', 'f', 4, 4, "gal 2");

    // testing accessors and mutators
    cout << LINE << endl;
    cout << "Testing accessors and mutators" << endl;
    cout << LINE << endl;
    cout << "Finance of " << dp2.getName() << " is: "
            << dp2.getFinance() << endl;
    cout << "Romance of " << dp3.getName() << " is: "
            << dp3.getRomance() << endl;
    cout << "Modifying values..." << endl;
    dp2.setName("?");
    dp2.setFinance(10);
    dp3.setRomance(6);
    cout << "Finance of " << dp2.getName() << " is now: "
            << dp2.getFinance() << endl;
    cout << "Romance of " << dp3.getName() << " is now: "
            << dp3.getRomance() << endl;
    cout << LINE << endl;
    // undo name change
    dp2.setName("dude 2");

    // matching
    cout << LINE << endl;
    cout << "Fit values for profile 1: " << endl;
    cout << LINE << endl;
    printFit(dp1, dp1);
    printFit(dp1, dp2);
    printFit(dp1, dp3);
    printFit(dp1, dp4);

    cout << LINE << endl;
    cout << "Fit values for profile 2: " << endl;
    cout << LINE << endl;
    printFit(dp2, dp1);
    printFit(dp2, dp2);
    printFit(dp2, dp3);
    printFit(dp2, dp4);

    cout << LINE << endl;
    cout << "Fit values for profile 3: " << endl;
    cout << LINE << endl;
    printFit(dp3, dp1);
    printFit(dp3, dp2);
    printFit(dp3, dp3);
    printFit(dp3, dp4);

    cout << LINE << endl;
    cout << "Fit values for profile 4: " << endl;
    cout << LINE << endl;
    printFit(dp3, dp1);
    printFit(dp3, dp2);
    printFit(dp3, dp3);
    printFit(dp3, dp4);

    return 0;
}

// initialize static member
const int DateProfile::MIN_ROMANCE = 1;
const int DateProfile::MAX_ROMANCE = 10;
const int DateProfile::MIN_FINANCE = 1;
const int DateProfile::MAX_FINANCE = 10;
const int DateProfile::MIN_NAME_LEN = 5;
const int DateProfile::MAX_NAME_LEN = 30;
const char DateProfile::DEFAULT_GENDER = 'M';
const char DateProfile::DEFAULT_SEARCH_GENDER = 'F';
const int DateProfile::DEFAULT_ROMANCE = 5;
const int DateProfile::DEFAULT_FINANCE = 5;
const string DateProfile::DEFAULT_NAME = "Anonymous";

DateProfile::DateProfile() {
    setDefaults();
}

DateProfile::DateProfile(char gender, char searchGender, int romance, 
                            int finance, string name) {
    setAll(gender, searchGender, romance, finance, name);
}

char DateProfile::getGender() {
    return gender;
}

char DateProfile::getSearchGender() {
    return searchGender;
}

int DateProfile::getRomance() {
    return romance;
}

int DateProfile::getFinance() {
    return finance;
}

string DateProfile::getName() {
    return name;
}

void DateProfile::setGender(char gender) {
    gender = toupper(gender);
    if (gender == 'M' || gender == 'F') {
        this->gender = gender;
    } else {
        cout << "Invalid gender \"" << gender << "\"" << endl;
        this->gender = DEFAULT_GENDER;
    }
}

void DateProfile::setSearchGender(char searchGender) {
    searchGender = toupper(searchGender);
    if (searchGender == 'M' || searchGender == 'F') {
        this->searchGender = searchGender;
    } else {
        cout << "Invalid search gender \"" << searchGender << "\"" << endl;
        this->searchGender = DEFAULT_SEARCH_GENDER;
    }
}

void DateProfile::setRomance(int romance) {
    if (romance >= MIN_ROMANCE && romance <= MAX_ROMANCE) {
        this->romance = romance;
    } else {
        cout << "Invalid romance \"" << romance << "\"" << endl;
        this->romance = DEFAULT_ROMANCE;
    }
}

void DateProfile::setFinance(int finance) {
    if (finance >= MIN_FINANCE && finance <= MAX_FINANCE) {
        this->finance = finance;
    } else {
        cout << "Invalid finance \"" << finance << "\"" << endl;
        this->finance = DEFAULT_FINANCE;
    }
}

void DateProfile::setName(string name) {
    if (name.length() >= MIN_NAME_LEN && name.length() <= MAX_NAME_LEN) {
        this->name = name;
    } else {
        cout << "Invalid name \"" << name << "\". Please make sure "
                << "your name is between " << MIN_NAME_LEN << " and " 
                << MAX_NAME_LEN << " characters." << endl;
        this->name = DEFAULT_NAME;
    }
}

void DateProfile::setAll(char gender, char searchGender, int romance,
                            int finance, string name) {
    setGender(gender);
    setSearchGender(searchGender);
    setRomance(romance);
    setFinance(finance);
    setName(name);
}

void DateProfile::setDefaults() {
    setAll(DEFAULT_GENDER, DEFAULT_SEARCH_GENDER, DEFAULT_ROMANCE,
            DEFAULT_FINANCE, DEFAULT_NAME);
}

double DateProfile::fitValue(DateProfile partner) {
    if (determineGenderFit(partner)) {
        return (determineRomanceFit(partner) 
                + determineFinanceFit(partner)) / 2.0;
    } else {
        return 0;
    }
}

double DateProfile::determineGenderFit(DateProfile partner) {
    // return true (1) if gender matches partner's search gender
    // and vice versa, false (0) if match fails
    return this->gender == partner.getSearchGender() && 
            this->searchGender == partner.getGender();
}

double DateProfile::determineRomanceFit(DateProfile partner) {
    // linear scale
    return 1 - abs(this->romance - partner.getRomance()) / 10.0;
}

double DateProfile::determineFinanceFit(DateProfile partner) {
    // linear scale
    return 1 - abs(this->finance - partner.getFinance()) / 10.0;
}