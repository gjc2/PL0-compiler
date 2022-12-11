#include<iostream>
#include<string>
#include<vector>
#include "pcode.h"
#include "mid.h"
using namespace std;

class objectcode {
	vector<pcode>object_code;
	mid* midcode = new mid();
	objectcode(mid* t);
};