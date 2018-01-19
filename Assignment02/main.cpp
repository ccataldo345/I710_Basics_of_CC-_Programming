#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include "./json.hpp"

using namespace std;

int getMenu();
int printList();
int inputPizzaName();
int vector01();


struct Recipe
{
  string name;
  vector<string> ingredients;
};

void from_json(nlohmann::json const& json, Recipe& rec)
{
    rec.name = json.at("name").get<string>();
    rec.ingredients = json.at("ingredients").get<vector<string>>();
}

int vector01(){
	ifstream simpleDataFile{ "recipes.json" };
    nlohmann::json simpleJson;
    simpleDataFile >> simpleJson;
    simpleDataFile.close();

    //vector<Recipe> recs = simpleJson;
	}


int main(){

	int menu = getMenu();
	
	while (menu != 4) {
		switch (menu) {
			case 1:
				printList();
				break;
			case 2:
				inputPizzaName();
				break;
		}
	cout << endl;
	menu = getMenu();
	}
}

// print list function
int printList(){
	// print ingredients
	ifstream simpleDataFile{ "recipes.json" };
    nlohmann::json simpleJson;
    simpleDataFile >> simpleJson;
    simpleDataFile.close();

    vector<Recipe> recs = simpleJson;
    
    cout << endl;
    cout << "Pizza list: " << endl;
	
	for (auto i : recs) { 
		cout << "- " << i.name << ": ";
		for (auto& j : i.ingredients) 
			cout << j << ", ";
	cout << endl;
	}
}
	
// print pizza to buy input function
int inputPizzaName(){
	string pizzaToBuy;
	cout << endl;
	cout << "Type the name of the pizza to buy:" << endl;
	cin >> pizzaToBuy;
	pizzaToBuy[0] = toupper(pizzaToBuy[0]);	//first letter capital
	cout << "You typed: " << pizzaToBuy << endl;
	
	ifstream simpleDataFile{ "recipes.json" };
    nlohmann::json simpleJson;
    simpleDataFile >> simpleJson;
    simpleDataFile.close();

    vector<Recipe> recs = simpleJson;

	bool check = false;
	for (auto i : recs) { 
		if (i.name == pizzaToBuy) {
				check = true;
				break;
		}
	}

	if (check == false)
		cout << "This pizza is not in the list, please try again";
	else 
		cout << "You want to buy a pizza " << pizzaToBuy << endl;
	cout << endl;
}

// menu function
int getMenu(){
	cout << "MENU: " << endl;
	int choice;
	cout << "1 - print pizza list" << endl;
	cout << "2 - Buy pizza" << endl;
	cout << "3 - aaaa" << endl;
	cout << "4 - exit program" << endl;
	
	cin >> choice;
	return choice;
}
