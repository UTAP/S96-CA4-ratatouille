#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <vector>
#include "food.h"

class Restaurant{
private:
	int id;
	std::string name;
	std::string location;
	std::vector <Food> menu;
public: 
	Restaurant(std::string name, int id, std::string location, std::vector <Food> = std::vector <Food> ());
	void addFood(int id, std::string name, Food::Type, int cost);
	std::string getMenu() const;
	std::string getListFoods(Food::Type = Food::All) const;
	int getId() const;
	std::string getName() const;
	Food *findFood(int id);
	std::string getLocation() const;	
};

#endif