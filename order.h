#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>

class Customer;
class Food;
class Restaurant;

class SubOrder{
private:
	Food* food;
	Restaurant* restaurant;
	int num;
	std::string personalizations;
public:
	SubOrder(Food *, Restaurant *, int num, std::string personalizations);
	std::string getBill() const;
	int getCost() const;
	bool isNear(const Customer &) const;
};

class Order{
private:
	Customer *customer;
	std::vector <SubOrder> foods;
	bool isNear() const;
public:
	Order(Customer *, std::vector <SubOrder> = std::vector <SubOrder> ());
	void addToOrder(Food *, Restaurant *, int num, std::string personalizations);
	std::string getBill() const;
	int getTotalCost() const;
	int getPureTotalCost() const;
	int getDeliveryCost() const;
};

#endif