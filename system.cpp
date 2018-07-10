#include "system.h"
#include <string>
#include <vector>

#define ERRSTR "ERR\n"

using namespace std;

void System::addCustomer(string name, long id, string location){
	customers.push_back(Customer(name, id, location));
}

void System::addRestaurant(string name, int id, string location, vector <Food> foods){
	vector <Restaurant>::iterator i;
	for(i = restaurants.begin(); i < restaurants.end(); i++)
		if(i->getId() > id)
			break;
	restaurants.insert(i, Restaurant(name, id, location, foods));
}

void System::addFood(int restaurantId, int foodId, string name, Food::Type type, int cost){
	Restaurant *restaurant = findRestaurant(restaurantId);
	if(!restaurant)
		return;
	restaurant->addFood(foodId, name, type, cost);
}

void System::newOrder(long customerId){
	Customer *customer = findCustomer(customerId);
	if(!customer)
		return;
	return customer->newOrder();
}

void System::addToOrder(long customerId, long foodId, int num, string personalizations){
	Customer *customer = findCustomer(customerId);
	Restaurant *restaurant = findRestaurant(foodId / 1000);
	Food *food = restaurant->findFood(foodId % 1000);
	if(!customer || !restaurant)
		return;
	return customer->addToOrder(food, restaurant, num, personalizations);
}

string System::getOrderReport(long customerId){
	Customer *customer = findCustomer(customerId);
	if(!customer)
		return ERRSTR;
	return customer->getOrderReport();
}

string System::getLastBill(long customerId){
	Customer *customer = findCustomer(customerId);
	if(!customer)
		return ERRSTR;
	return customer->getLastBill();
}

string System::getAllBills(long customerId){
	Customer *customer = findCustomer(customerId);
	if(!customer)
		return ERRSTR;
	return customer->getAllBills();
}

bool System::isNear(const Customer &customer, const Restaurant &restaurant){
	return customer.getLocation() == restaurant.getLocation();
}

Customer * System::findCustomer(long id){
	for(int i = 0; i < customers.size(); i++)
		if(customers[i].getId() == id)
			return &customers[i];
	return NULL;
}

Restaurant * System::findRestaurant(int id){
	for(int i = 0; i < restaurants.size(); i++)
		if(restaurants[i].getId() == id)
			return &restaurants[i];
	return NULL;
}

string System::getMenu(int restaurantId){
	Restaurant *restaurant = findRestaurant(restaurantId);
	if(!restaurant)
		return "";
	return restaurant->getMenu();
}

string System::getRestaurantsDetail(long customerId){
	string result = "";
	Customer *customer;
	if(customerId){
		customer = findCustomer(customerId);
	}
	if(customerId && !customer)
		return "";
	for(int i = 0; i < restaurants.size(); i++)
		if(!customerId || isNear(*customer, restaurants[i]))
			result += restaurants[i].getName() + string(" ") + restaurants[i].getLocation() + string(" ") + to_string(restaurants[i].getId()) + string("\n");
	return result;
}

string System::listFoods(long customerId){
	string result = "";
	Customer *customer = findCustomer(customerId);
	if(!customer)
		return "";
	for(int i = 0; i < restaurants.size(); i++)
		if(isNear(*customer, restaurants[i]))
			result += restaurants[i].getListFoods();
	return result;
}

string System::listFoods(Food::Type type){
	string result = "";
	for(int i = 0; i < restaurants.size(); i++)
		result += restaurants[i].getListFoods(type);
	return result;
}
