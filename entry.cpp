#include "entry.h"
#include <iostream>
#include <fstream>
entry::entry(string _name, string _kind, string _var, int _level, int _addr) {
	name = _name;
	kind = _kind;
	var = _var;
	level = _level;
	addr = _addr;
}

void entry::show() {
	ofstream file(lr_table, ios::app);
	file << name << " " << kind << " " << var << " " << level << " " << addr << endl;
	file.close();
}