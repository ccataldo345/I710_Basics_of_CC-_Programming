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


// structs
struct Recipe
{
  string name;
  vector<string> ingredients;
};

struct Ingredients
{
  string name;
  int quantity;
  int priceType;
};

struct Prices
{
  int id;
  double price;
};


// nlohmann::json
void from_json(nlohmann::json const& json, Recipe& rec)
{
    rec.name = json.at("name").get<string>();
    rec.ingredients = json.at("ingredients").get<vector<string>>();
}

void from_json(nlohmann::json const& json, Ingredients& ing)
{
    ing.name = json.at("name").get<string>();
    ing.quantity = json.at("quantity").get<int>();
    ing.priceType = json.at("priceType").get<int>();
}

void from_json(nlohmann::json const& json, Prices& pri)
{
    pri.id = json.at("id").get<int>();
    pri.price = json.at("price").get<double>();
}

/*
// read json files
void recipes(){
	ifstream simpleDataFile{ "recipes.json" };
    nlohmann::json simpleJson;
    simpleDataFile >> simpleJson;
    simpleDataFile.close();
}

void ingredients(){
	ifstream simpleDataFile{ "ingredients.json" };
    nlohmann::json simpleJson;
    simpleDataFile >> simpleJson;
    simpleDataFile.close();
}

void prices(){
	ifstream simpleDataFile{ "prices.json" };
    nlohmann::json simpleJson;
    simpleDataFile >> simpleJson;
    simpleDataFile.close();
}
*/
double totalPrice;

// create vectors from json files
vector<Recipe> recs;

vector<Ingredients> ings;

vector<Prices> prices;
    
// main
int main(){
	// read json files
	ifstream simpleDataFileR{ "recipes.json" };
    nlohmann::json simpleJsonR;
    simpleDataFileR >> simpleJsonR;
    simpleDataFileR.close();
    
    ifstream simpleDataFileI{ "ingredients.json" };
    nlohmann::json simpleJsonI;
    simpleDataFileI >> simpleJsonI;
    simpleDataFileI.close();
    
    ifstream simpleDataFileP{ "prices.json" };
    nlohmann::json simpleJsonP;
    simpleDataFileP >> simpleJsonP;
    simpleDataFileP.close();
    
    
    vector<Recipe> recs2 = simpleJsonR;
    vector<Ingredients> ings2 = simpleJsonI;
	vector<Prices> prices2 = simpleJsonP;
	
	recs = recs2;
	ings = ings2;
	prices = prices2;

    int menu = getMenu();
	
	while (menu != 3) {
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
	cout << endl << "Good bye!";
}

// print list function
int printList(){
	
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
	cout << endl;
	cout << "You typed: " << pizzaToBuy << endl;
	cout << endl;

	// check if pizza name input is in pizza list
	bool check = false;
	for (auto i : recs) { 
		if (i.name == pizzaToBuy) {
				check = true;
				break;
		}
	}
	
	if (check == false) {
		cout << "This pizza is not in the list, please try again." << endl;
		return 0;
	}
	else
		cout << "Ok, you want to buy a pizza " << pizzaToBuy << ", which is in our pizza list!" << endl;
	cout << endl;

	// check if all ingredients are available in the list 
	bool checkIng = true;
	for (auto i : recs) 
		if (i.name == pizzaToBuy) 
			//cout << i.name << endl;
			for (auto& j : i.ingredients)
				//cout << j << endl;
				for (auto k : ings)
					if (k.name == j) 
						if (k.quantity <= 0) {
						checkIng = false;
						cout << "Unfortunately the ingredient '" << k.name << "' is not availabe :-(" << endl;
						cout << endl;
						break;
					}
	if (checkIng == false) {
		cout << "Sorry, this pizza can not be bought! Try again or exit." << endl;
	}
	
	else {

		//print price
		double subtotal = 0.0;
		
		for (auto i : recs)  
			if (i.name == pizzaToBuy) 
				//cout << i.name << endl;	// print name of pizza
				for (auto& j : i.ingredients)
					//cout << j << endl;	// print name of ingredients
					for (auto k : ings)
						if (k.name == j)
							//cout << k.priceType << endl;	// print price type
							for (auto l : prices)
								if (l.id == k.priceType) {
									subtotal += l.price; // sum prices of each ingredient
									totalPrice += l.price;	
								}
		cout << "Pizza price: " << subtotal << endl;
		cout << "Total bill amount: " << totalPrice << endl;
		cout << endl;
		
		
		// remove ingredients from list
		cout << "Remaining ingredients: " << endl;
		
		for (auto i : recs)
			if (i.name == pizzaToBuy)
				for (auto& j : i.ingredients)
					for (vector<Ingredients> ::iterator it = ings.begin(); it != ings.end(); ++it)
						if ((*it ).name == j) {
							(*it).quantity -= 1;
							//int q = k.quantity;
							//removeIngredients(k.quantity);
							cout << (*it).name << ": " << (*it).quantity << endl;
						}
					
	} 	// else {
} 	// inputPizzaName(){

// menu function
int getMenu(){
    
	cout << endl << "MENU: " << endl;
	int choice;
	cout << "1 - Print pizza list" << endl;
	cout << "2 - Buy pizza" << endl;
	cout << "3 - Exit the program" << endl;
	
	cin >> choice;
	return choice;
	
}
