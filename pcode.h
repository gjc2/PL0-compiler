#include<iostream>
#include<string>
using namespace std;

class pcode {
public:
	string op;
	string l;
	string a;
	pcode(string _op, string _l, string _a) {
		op = _op;
		l = _l;
		a = _a;
	}
	pcode(){}
};