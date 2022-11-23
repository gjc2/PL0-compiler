#include<vector>
#include "quadruple.h"
#include "table.h"
#include <iostream>
using namespace std;
class gen {
public:
	vector<quad>a;
	vector<int>state;
	vector<string>sym;
	vector<string>in;
	gen(){}
	void show();
	void g(table t,vector<rule*>origin);
};