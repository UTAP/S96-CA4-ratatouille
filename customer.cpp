#include "customer.h"
#include <string>
#include <vector>

using namespace std;

Customer::Customer(string _name, long _id, string _location): name(_name), id(_id), location(_location){}

long Customer::getId() const{
	return id;
}

string Customer::getName() const{
	return name;
}

string Customer::getLocation() const{
	return location;
}

string Customer::getLastBill() const{
	if(!orders.size())
		return "\n";
	return getName() + string(" ") + to_string(getId()) + string("\n") + orders.back().getBill();
}

string Customer::getAllBills() const{
	string result = getName() + string(" ") + to_string(getId()) + string("\n");
	for(int i = 0; i < orders.size(); i++)
		result += orders[i].getBill() + string("#\n");
	result += string("total purchase ") + to_string(getTotalPurchase()) + string("\n");
	return result;
}

void Customer::newOrder(){
	orders.push_back(Order(this));
}

void Customer::addToOrder(Food *food, Restaurant *restaurant, int num, string personalizations){
	if(!orders.size())
		return;
	orders.back().addToOrder(food, restaurant, num, personalizations);
}

string Customer::getOrderReport() const{
	if(!orders.size())
		return "\n";
	return getName() + string(" ") + to_string(getId()) + string(" ") + to_string(orders.back().getTotalCost()) + string("\n");
}

int Customer::getTotalPurchase() const{
	int sum = 0;
	for(int i = 0; i < orders.size(); i++)
		sum += orders[i].getTotalCost();
	return sum;
}
