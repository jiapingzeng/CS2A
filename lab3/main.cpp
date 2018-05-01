#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string recipename;
double totalSolFiber, totalCals;

// food #1 constants
const string FOOD_1_NAME = "avacado";
const int FOOD_1_CALORIES_P100G = 160;
const double FOOD_1_SOL_FIBER_P100G = 1.75;

// food #2 constants
const string FOOD_2_NAME = "tomato";
const int FOOD_2_CALORIES_P100G = 18;
const double FOOD_2_SOL_FIBER_P100G = 0.12;

// food #3 constants
const string FOOD_3_NAME = "buffalo mozzarella";
const int FOOD_3_CALORIES_P100G = 282;
const double FOOD_3_SOL_FIBER_P100G = 0;

const string INDENT = "   ";

int main() {

	string recipeName, userInputStr;

	// initialize accumulator variables
	totalSolFiber = 0;
	totalCals = 0;

	// print menu
	cout << "---------- List of Possible Ingredients ----------" << endl;
	cout << INDENT << "Food #1: " << FOOD_1_NAME << endl;
	cout << INDENT << "Food #2: " << FOOD_2_NAME << endl;
	cout << INDENT << "Food #3: " << FOOD_3_NAME << endl;

	// name of recipe
	cout << "What are you calling this recipe? ";
	getline(cin, recipeName);

	// food #1
	cout << "How many grams of " << FOOD_1_NAME << "? " << endl;
	getline(cin, userInputStr);
	updateNutritions(userInputStr, FOOD_1_CALORIES_P100G, FOOD_1_SOL_FIBER_P100G);

	// food #2
	cout << "How many grams of " << FOOD_2_NAME << "? " << endl;
	getline(cin, userInputStr);
	updateNutritions(userInputStr, FOOD_2_CALORIES_P100G, FOOD_2_SOL_FIBER_P100G);

	// food #3
	cout << "How many grams of " << FOOD_3_NAME << "? " << endl;
	getline(cin, userInputStr);
	updateNutritions(userInputStr, FOOD_3_CALORIES_P100G, FOOD_3_SOL_FIBER_P100G);

	// report results
	cout << "Nutrition for " << recipeName << "----------" << endl;
	cout << INDENT << "Calories: " << totalCals << endl;
	cout << INDENT << "Soluble Fiber: " << totalSolFiber << " grams\n";

	return 0;
}

void updateNutritions(string userInputStr, double foodCals, double foodSolFiber) {
	int userInputInt;
	istringstream(userInputStr) >> userInputInt;
	if (userInputInt < 0 || userInputInt > 1500) return;
	totalCals += userInputInt * (foodCals / 100);
	totalSolFiber += userInputInt * (foodSolFiber / 100);
}