#include "order.h"
#include "food.h"
#include "restaurant.h"
#include "system.h"
#include <string>
#include <vector>

using namespace std;

SubOrder::SubOrder(Food *_food, Restaurant *_restaurant, int _num, string _personalizations)
	: food(_food), num(_num), personalizations(_personalizations), restaurant(_restaurant){}

string SubOrder::getBill() const{
	return to_string(restaurant->getId()) + food->getDetails() + string(" ") + to_string(num) 
		+ string(" ") + to_string(num * food->getCost()) + ((personalizations != "") ? string(" ") + personalizations : string("")) + string("\n");
}

int SubOrder::getCost() const{
	return food->getCost() * num;
};

bool SubOrder::isNear(const Customer &customer) const{
	return System::isNear(customer, *(restaurant));
};

int Order::getPureTotalCost() const{
	int sum = 0;
	for(int i = 0; i < foods.size(); i++)
		sum += foods[i].getCost();
	return sum;
}

int Order::getTotalCost() const{
	return getPureTotalCost() + getDeliveryCost();
}

int Order::getDeliveryCost() const{
	return (getPureTotalCost() > 100000 || isNear()) ? 0 : 5000;
}

Order::Order(Customer *_customer, std::vector <SubOrder> _foods): customer(_customer){
	for(int i = 0; i < _foods.size(); i++)
		foods.push_back(_foods[i]);
}

void Order::addToOrder(Food *food, Restaurant *restaurant, int num, std::string personalizations){
	foods.push_back(SubOrder(food, restaurant, num, personalizations));
}

string Order::getBill() const{
	string result;
	for(int i = 0; i < foods.size(); i++)
		result += foods[i].getBill();
	result += "delivery cost " + to_string(getDeliveryCost()) + string("\n");
	result += "total cost " + to_string(getTotalCost()) + string("\n");
	return result;
}

bool Order::isNear() const{
	for(int i = 0; i < foods.size(); i++)
		if(!foods[i].isNear(*(customer)))
			return false;
	return true;
}
