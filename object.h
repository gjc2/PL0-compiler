#include<iostream>
#include<string>
#include<vector>
#include "pcode.h"
#include "mid.h"
#include<fstream>
using namespace std;

class objectcode {
public:
	int all_num = 0;
	int code_num = 0;//’ª…Ó∂»
	int data_num = 0;
	vector<pcode*>object_code;
	vector<pair<int, int> >backto;
	mid* midcode = new mid();
	objectcode(mid* t);
	objectcode(){}
	void gen(string op, string l, string a);
	int lookup(mid* t,int nol);
	int lookup2(mid* t, string name);
	void show();
	int count_data(mid* t, int s);
	int need(int s);
};