#include "util.h"
#include <string>
#include <vector>

using namespace std;

vector <string> parseString(string str, char delimiter){
	vector <string> v;
	int start = 0, end;
	for(int end = 0; end <= str.size(); end++){
		if(end == str.size()|| str[end] == delimiter){
			v.push_back(str.substr(start, end - start));
			start = end + 1;
		}
	}
	return v;
}
