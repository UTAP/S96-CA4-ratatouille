#include "restaurant.h"
#include <string>
#include <vector>

using namespace std;

Restaurant::Restaurant(string _name, int _id, string _location, vector<Food> foods): id(_id), location(_location), name(_name){
	for(int i = 0; i < foods.size(); i++)
		menu.push_back(foods[i]);
}

void Restaurant::addFood(int id, string name, Food::Type type, int cost){
	vector <Food>::iterator i;
	for(i = menu.begin(); i < menu.end(); i++)
		if(i->getId() > id)
			break;
	menu.insert(i, Food (id, name, type, cost));
}

string Restaurant::getMenu() const{
	string result;
	for(int i = 0; i < menu.size(); i++)
		result += to_string(id) + menu[i].getDetails() + string("\n");
	return result;
}

string Restaurant::getLocation() const{
	return location;
}

int Restaurant::getId() const{
	return id;
}

Food *Restaurant::findFood(int id){
	for(int i = 0; i < menu.size(); i++){
		if(menu[i].getId() == id)
			return &menu[i];
	}
	return NULL;
}

string Restaurant::getName() const{
	return name;
}

string Restaurant::getListFoods(Food::Type type) const{
	string result;
	for(int i = 0; i < menu.size(); i++)
		if(type ==  Food::All || menu[i].getType() == type)
			result += to_string(id) + menu[i].getDetails() + string(" ") + getName() + string(" ") + getLocation() + string("\n");
	return result;
}
