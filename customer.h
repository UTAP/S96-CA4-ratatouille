#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <string>
#include "order.h"

class Customer{
private:
	std::string name;
	long id;
	std::vector <Order> orders;
	std::string location;
public:
	Customer(std::string name, long id, std::string location);
	long getId() const;
	std::string getName() const;
	std::string getLocation() const;
	std::string getLastBill() const;
	std::string getAllBills() const;
	void newOrder();
	void addToOrder(Food *, Restaurant *, int num, std::string personalizations);
	std::string getOrderReport() const;
	int getTotalPurchase() const;
};

#endif