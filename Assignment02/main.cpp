#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include <jsoncpp/json/json.h>

using namespace std;

int getMenu();
int printList();
int inputPizzaName();

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
	ifstream recipes{ "recipes.json" };
	Json::Reader reader;
    Json::Value obj;
    reader.parse(recipes, obj); 
	
	cout << endl;
	cout << "Pizza list: " << endl;
	for (Json::Value::ArrayIndex i = 0; i != obj.size(); i++)
		if (obj[i].isMember("name"))
			cout << obj[i]["name"].asString() << endl;
	cout << endl;
}
	
// print pizza to buy input function
int inputPizzaName(){
	string pizzaToBuy;
	cout << "Type the name of the pizza to buy:" << endl;
	cin >> pizzaToBuy;
	
	ifstream recipes{ "recipes.json" };
	Json::Reader reader;
    Json::Value obj;
    reader.parse(recipes, obj); 
	
	bool check = false;
	for (Json::Value::ArrayIndex i = 0; i != obj.size(); i++) {
		if (obj[i].isMember("name")) {
			if (obj[i]["name"].asString() == pizzaToBuy) {
				check = true;
				break;
			}
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
