#include <iostream>
#include <string.h>
#include <ctype.h>
#include <cmath.h>
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
    DateProfile(DEFAULT_GENDER, DEFAULT_SEARCH_GENDER, DEFAULT_ROMANCE,
                DEFAULT_FINANCE, DEFAULT_NAME);
}

DateProfile::DateProfile(char gender, char searchGender, int romance, 
                            int finance, string name) {
    setGender(gender);
    setSearchGender(searchGender);
    setRomance(romance);
    setFinance(finance);
    setName(name);
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
        this->gender = DEFAULT_GENDER;
    }
}

void DateProfile::setSearchGender(char searchGender) {
    searchGender = toupper(searchGender);
    if (searchGender == 'M' || searchGender == 'F') {
        this->searchGender = searchGender;
    } else {
        this->searchGender = DEFAULT_SEARCH_GENDER;
    }
}

void DateProfile::setRomance(int romance) {
    if (romance >= MIN_ROMANCE && romance <= MAX_ROMANCE) {
        this->romance = romance;
    } else {
        this->romance = DEFAULT_ROMANCE;
    }
}

void DateProfile::setFinance(int finance) {
    if (finance >= MIN_FINANCE && finance <= MAX_FINANCE) {
        this->finance = finance;
    } else {
        this->finance = DEFAULT_FINANCE;
    }
}

void DateProfile::setName(string name) {
    if (name.length() >= MIN_NAME_LEN && name.length() <= MAX_NAME_LEN) {
        this->name = name;
    } else {
        this->name = DEFAULT_NAME;
    }
}

double DateProfile::fitValue(DateProfile partner) {

}

double DateProfile::determineGenderFit(DateProfile partner) {
    return this->gender == partner.getSearchGender() && 
            this->searchGender == partner.getGender();
}

double DateProfile::determineRomanceFit(DateProfile partner) {

}

double DateProfile::determineFinanceFit(DateProfile partner) {

}

int main() {
    cout << "Hello world" << endl;
    return 0;
}