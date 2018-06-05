#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

class DateProfile {
    public:
        // range limits
        static const int MIN_ROMANCE = 1;
        static const int MAX_ROMANCE = 10;
        static const int MIN_FINANCE = 1;
        static const int MAX_FINANCE = 10;
        static const int MIN_NAME_LEN = 5;
        static const int MAX_NAME_LEN = 30;
        // default values
        static const char DEFAULT_GEND = 'M';
        static const char DEFAULT_SEARCH_GEND = 'F';
        static const int DEFAULT_ROMANCE = 5;
        static const int DEFAULT_FINANCE = 5;
        static const string DEFAULT_NAME = "Anonymous";
        DateProfile();
        DateProfile(char gender, char searchGender, int romance,
                    int finance, string name);
        char getGender();
        char getSearchGender();
        int getRomance();
        int getFinance();
        string getName();
        void setGender(char gender);
        void setSearchGender(char searchGender);
        void setRomance(int romance);
        void setFinance(int finance);
        void setName(string name);
        
    private:
        char gender;
        char searchGender;
        int romance;
        int finance;
        string name;
};

DateProfile::DateProfile() {
    
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
    }
}

void DateProfile::setSearchGender(char searchGender) {
    searchGender = toupper(searchGender);
    if (searchGender == 'M' || searchGender == 'F') {
        this->searchGender = searchGender;
    }
}

void DateProfile::setRomance(int romance) {
    if (romance >= MIN_ROMANCE && romance <= MAX_ROMANCE) {
        this->romance = romance;
    }
}

void DateProfile::setFinance(int finance) {
    if (finance >= MIN_FINANCE && finance <= MAX_FINANCE) {
        this->finance = finance;
    }
}

void DateProfile::setName(string name) {
    if (name.length() >= MIN_NAME_LEN && name.length() <= MAX_NAME_LEN) {
        this->name = name;
    }
}