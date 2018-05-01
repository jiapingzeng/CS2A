#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string recipeName;
double totalCalories, totalDietFiber, totalStarch, totalFat, totalProtein;

const string INDENT = "    ";

class Food {
    public:
        string name;
        // per 100g
        double calories, dietFiber, starch, fat, protein;
        Food(string, double, double, double, double, double);
};

Food::Food(string name, double calories, double dietFiber, double starch, double fat, double protein) {
    this->name = name;
    this->calories = calories;
    this->dietFiber = dietFiber;
    this->starch = starch;
    this->fat = fat;
    this->protein = protein;
}

int getUserInput(Food food) {
    string userInputStr;
    int userInputInt;
    cout << "How many grams of " << food.name << "? ";
    getline(cin, userInputStr);
    istringstream(userInputStr) >> userInputInt;
    return userInputInt;
}

int updateNutritions(Food food, int grams) {
    if (grams < 0) {
        cout << "Not sure how to make negative food. Please try again." << endl;
        return 1;
    } else if (grams > 1500) {
        cout << "Too much food! Please try again with less " << food.name << "." << endl;
        return 1;
    }
    totalCalories += grams * (food.calories / 100);
    totalDietFiber += grams * (food.dietFiber / 100);
    totalStarch += grams * (food.starch / 100);
    totalFat += grams * (food.fat / 100);
    totalProtein += grams * (food.protein / 100);
    return 0;
}

int main() {
    int userInput;

    // create food information
    Food food1 ("baked potato", 93.0, 2.2, 17.3, 0.1, 2.5);
    Food food2 ("raw potato", 77.0, 2.2, 15.4, 0.1, 2.0);
    Food food3 ("boiled potato", 87.0, 1.8, 14.2, 0.1, 1.9);
    Food food4 ("canned potato", 62.0, 2.4, 14.7, 0.2, 1.4);
    Food food5 ("fried potato", 150.0, 1.9, 17.4, 4.7, 2.2);

    // print menu
    cout << "---------- List of Possible Ingredients ----------" << endl;
    cout << INDENT << "Food #1: " << food1.name << endl;
    cout << INDENT << "Food #2: " << food2.name << endl;
    cout << INDENT << "Food #3: " << food3.name << endl;
    cout << INDENT << "Food #4: " << food4.name << endl;
    cout << INDENT << "Food #5: " << food5.name << endl;

    // name of recipe
    cout << "What are you calling this recipe? ";
    getline(cin, recipeName);

    // update total nutrition
    if (updateNutritions(food1, getUserInput(food1))) return 1;
    if (updateNutritions(food2, getUserInput(food2))) return 1;
    if (updateNutritions(food3, getUserInput(food3))) return 1;
    if (updateNutritions(food4, getUserInput(food4))) return 1;
    if (updateNutritions(food5, getUserInput(food5))) return 1;

    // report results
    cout << endl << endl;
    cout << "Nutrition for " << recipeName << endl;
    cout << INDENT << "Calories: " << totalCalories << endl;
    cout << INDENT << "Dietary Fiber: " << totalDietFiber << endl;
    cout << INDENT << "Starch: " << totalStarch << endl;
    cout << INDENT << "Fat: " << totalFat << endl;
    cout << INDENT << "Protein: " << totalProtein << endl; 

    return 0;
}