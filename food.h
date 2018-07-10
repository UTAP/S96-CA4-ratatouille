#ifndef FOOD_H
#define FOOD_H

#include <string>

class Food{
public:
	enum Type{All, Iranian, Eastern, European};
private:
	int id;
	std::string name;
	int cost;
	Type type;
	static std::string idToString(int);
public:
	Food(int id, std::string name, Type, int cost);
	std::string getDetails() const;
	int getCost() const;
	static std::string typeToString(Type);
	static Type stringToType(std::string);
	int getId() const;
	Type getType() const;
};

#endif