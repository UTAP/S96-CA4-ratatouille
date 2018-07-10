#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "system.h"
#include "util.h"

#define NEW_SUPER -1
#define ERRSTR "ERR"

using namespace std;

void readDatabase(System &system, string customersFileName, string restaurantsFileName){
	string line;
	ifstream restaurantsFileStr(restaurantsFileName, ifstream::in);
	int restaurantId = NEW_SUPER;
	while(getline(restaurantsFileStr, line)){
		if(line == ""){
			restaurantId = NEW_SUPER;
		}
		else{
			vector <string> inputParameters = parseString(line, ',');
			if(restaurantId == NEW_SUPER){
				restaurantId = atoi(inputParameters[1].c_str());
				system.addRestaurant(inputParameters[0], restaurantId, inputParameters[2]);
			}
			else{
				system.addFood(restaurantId, atoi(inputParameters[0].c_str()), inputParameters[1], Food::stringToType(inputParameters[2]), atoi(inputParameters[3].c_str()));
			}
		}
	}
	restaurantsFileStr.close();

	ifstream customersFileStr(customersFileName, ifstream::in);
	while(getline(customersFileStr, line)){
		while(getline(customersFileStr, line)){
			vector <string> inputParameters = parseString(line, ',');
			system.addCustomer(inputParameters[0], atol(inputParameters[1].c_str()), inputParameters.size() > 2 ? inputParameters[2] : "");
		}
	}
	customersFileStr.close();
}

void systemIo(istream &istr, ostream &ostr, System &system){
	string line;
	while(getline(istr, line)){
		vector <string> inputParameters = parseString(line, ' ');
		if(inputParameters[0] == "menu"){
			ostr << system.getMenu(atoi(inputParameters[1].c_str()));
		}
		else if(inputParameters[0] == "restaurants"){
			ostr << system.getRestaurantsDetail(inputParameters.size() > 1 ? atol(inputParameters[2].c_str()) : 0);
		}
		else if(inputParameters[0] == "list"){
			if(inputParameters[1] == "near"){
				ostr << system.listFoods(atol(inputParameters[2].c_str()));
			}
			else if(inputParameters[1] == "type"){
				ostr << system.listFoods(Food::stringToType(inputParameters[2]));
			}
			else ostr << ERRSTR << endl;
		}
		else if(inputParameters[0] == "order"){
			long customerId = atol(inputParameters[1].c_str());
			system.newOrder(customerId);
			while(getline(istr, line) && line != "$"){
				inputParameters = parseString(line, ' ');
				string personalizations = "";
				for(int i = 2; i < inputParameters.size(); i++){
					if(i > 2)
						personalizations += string(" ");
					personalizations += inputParameters[i];
				}
				system.addToOrder(customerId, atol(inputParameters[0].c_str()), atoi(inputParameters[1].c_str()), personalizations);
			}
			ostr << system.getOrderReport(customerId);
		}
		else if(inputParameters[0] == "bill"){
			if(inputParameters[1] == "all"){
				ostr << system.getAllBills(atol(inputParameters[2].c_str()));
			}
			else{
				ostr << system.getLastBill(atol(inputParameters[1].c_str()));
			}
		}
		else
			ostr << ERRSTR << endl;
		// ostr << endl;
	}
}

int main(){
	System system;

	readDatabase(system, "customers.txt", "restaurants.txt");
	systemIo(cin, cout, system);

	return 0;
}