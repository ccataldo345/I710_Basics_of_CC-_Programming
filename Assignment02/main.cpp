#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

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
	menu = getMenu();
	}
}

// print list function
int printList(){
	ifstream recipes{ "recipes.json" };
	
	string name;
	string ingredients;
	
	cout << endl;
	cout << "List of pizzas: " << endl;
	while (recipes >> name >> ingredients){
		cout << name << ingredients << endl;
		}
	cout << endl;
}
	
// menu function
int getMenu(){
	int choice;
	cout << "1 - print list of pizzas" << endl;
	cout << "2 - aaaa" << endl;
	cout << "3 - aaaa" << endl;
	cout << "4 - exit program" << endl;
	
	cin >> choice;
	return choice;
	}
