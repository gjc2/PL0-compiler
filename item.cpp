#include<iostream>
#include "item.h"
#include<algorithm>
using namespace std;

void item::push_rule(rule* r) {
	I.push_back(r);
	len++;
}
void item::push_map(pair<item*,string> a, item* b) {
	mp[a] = b;
}

bool item::operator==(const item b) {
	int flag = 1;
	if (len != b.len) {
		return false;
	}
	for (int i = 0; i < len; i++) {
		int ff = 0;
		for (int j = 0; j < b.len; j++) {
			if (*I[i] == *b.I[j]) {
				ff = 1;
			}
		}
		flag = ff;
		if (flag == 0) break;
	}
	return flag ;
}
void item::show() {
	for (int i = 0; i < len; i++) {
		I[i]->show();
	}
}

void item::show_all() {
	cout <<"I" << numm << ":" << endl;
	for (int i = 0; i < len; i++) {
		I[i]->show();
	}
	for (auto i : mp) {
		cout << i.first.second <<":" <<i.second->numm << endl;
	}
}