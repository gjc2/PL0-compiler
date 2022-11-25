#include "entry.h"
#include <iostream>
entry::entry(string _name, string _kind, int _var, int _level, int _addr) {
	name = _name;
	kind = _kind;
	var = _var;
	level = _level;
	addr = _addr;
}

void entry::show() {
	cout << name << " " << kind << " " << var << " " << level << " " << addr << endl;
}