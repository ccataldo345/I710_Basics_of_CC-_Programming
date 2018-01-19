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

// main
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
	
	ifstream simpleDataFileR{ "recipes.json" };
    nlohmann::json simpleJsonR;
    simpleDataFileR >> simpleJsonR;
    simpleDataFileR.close();

    vector<Recipe> recs = simpleJsonR;

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
	
	
	//print price
	ifstream simpleDataFileI{ "ingredients.json" };
    nlohmann::json simpleJsonI;
    simpleDataFileI >> simpleJsonI;
    simpleDataFileI.close();
    
    ifstream simpleDataFileP{ "prices.json" };
    nlohmann::json simpleJsonP;
    simpleDataFileP >> simpleJsonP;
    simpleDataFileP.close();

    vector<Ingredients> ings = simpleJsonI;

    vector<Prices> prices = simpleJsonP;
	
	double totalPrice;
	for (auto i : recs)  
		if (i.name == pizzaToBuy) 
			//cout << i.name << endl;
			for (auto& j : i.ingredients)
				//cout << j << endl;
				for (auto k : ings)
					if (k.name == j)
						//cout << k.priceType << endl;
						for (auto l : prices)
							if (l.id == k.priceType)
								totalPrice += l.price;
	cout << "Total price: " << totalPrice << endl;
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
