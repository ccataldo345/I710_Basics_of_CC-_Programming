#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include <jsoncpp/json/json.h>
#include "json.hpp"

using namespace std;

int getMenu();
int printList();

int main(){

	int menu = getMenu();
	
	while (menu != 4) {
		switch (menu) {
			case 1:
				printList();
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
	
	string name;
	//string namep = simpleJson["name"];
	string ingredients;
	std::vector<std::string> values;
	
	cout << endl;
	cout << "List of pizzas: " << endl;
	for (Json::Value::ArrayIndex i = 0; i != obj.size(); i++)
    if (obj[i].isMember("name"))
        cout << obj[i]["name"].asString() << endl;
	
	//while (simpleJson >> name >> ingredients){
		//cout << obj["name"].asString()  << endl;
	//}
	cout << endl;
}
	
// menu function
int getMenu(){
	cout << "MENU: " << endl;
	int choice;
	cout << "1 - print list of pizzas" << endl;
	cout << "2 - type the name of the pizza to buy" << endl;
	cout << "3 - aaaa" << endl;
	cout << "4 - exit program" << endl;
	
	cin >> choice;
	return choice;
	}
