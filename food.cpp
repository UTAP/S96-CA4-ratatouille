#include "food.h"
#include <string>

using namespace std;

Food::Food(int _id, string _name, Type _type, int _cost): id(_id), name(_name), type(_type), cost(_cost){}

string Food::getDetails() const{
	return idToString(id) + " " + name + " " + typeToString(type) + " " + to_string(cost);
}

int Food::getCost() const{
	return cost;
}

string Food::typeToString(Type type){
	switch(type){
		case Iranian:
			return "Iranian";
		case Eastern:
			return "Eastern";
		case European:
			return "European";
		default:
			return "";
	}
}

string Food::idToString(int id){
	return (id >= 100 ? string("") : (string("0") + (id >= 10 ? string("") : string("0")))) + to_string(id);
}

int Food::getId() const{
	return id;
}

Food::Type Food::stringToType(string str){
	if(str == "Iranian")
		return Iranian;
	else if(str == "Eastern")
		return Eastern;
	else if(str == "European")
		return European;
	else
		return All; // default
}

Food::Type Food::getType() const{
	return type;
}
