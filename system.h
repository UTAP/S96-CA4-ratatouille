#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <string>
#include "customer.h"
#include "restaurant.h"

class System{
private:
	std::vector <Customer> customers;
	std::vector <Restaurant> restaurants;
	Customer * findCustomer(long id);
	Restaurant * findRestaurant(int id);
public:
	void addCustomer(std::string name, long id, std::string location);
	void addRestaurant(std::string name, int id, std::string location, std::vector <Food> = std::vector <Food>());
	void addFood(int restaurantId, int foodId, std::string name, Food::Type, int cost);
	void newOrder(long customerId);
	void addToOrder(long customerId, long foodId, int num, std::string personalizations);
	std::string getOrderReport(long customerId);
	std::string getLastBill(long customerId);
	std::string getAllBills(long customerId);
	static bool isNear(const Customer &, const Restaurant &);
	std::string getMenu(int restaurantId);
	std::string getRestaurantsDetail(long customerId = 0);
	std::string listFoods(long customerId);
	std::string listFoods(Food::Type);
};

#endif