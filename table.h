#include<vector>
#include<string>
#include<map>
#include<iostream>
#include "item.h"
using namespace std;
class table {
public:
	vector<string>action;
	vector<string>Goto;
	vector<int>state;
	map<pair<int,string>, vector<string> > f;
	table(vector<item*>a, vector<string>T, vector<string>N,vector<rule*>origin);
	void show();
};