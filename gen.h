#include<vector>
#include "table.h"
#include <iostream>
#include "interpreter.h"
using namespace std;
class gen {
public:
	vector<quad>a;
	vector<int>state;
	vector<string>sym;
	vector<string>in;
	vector<string>in_p;
	mid* midcode=new mid();
	string lr_table;
	string mid_code;
	gen(){}
	void show();
	void g(table t,vector<rule*>origin);
};