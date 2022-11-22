#include<string>
#include<vector>
#include "rule.h"
#include <iostream>
#include <algorithm>
rule::rule(string s1, string s2) {
	r_l.push_back(s1);
	r_r.push_back(s2);
	len++;
}
void rule::show() {
	for (int i = 0; i < len; i++) {
		std::cout << r_l[i] << " -> " << r_r[i] << std::endl;
	}
}

void rule::back_rule() {
	if (len == 1) {
		string templ = r_l[0];
		string tempr = r_r[0];
		r_l.pop_back();
		r_r.pop_back();
		len--;
		if (tempr =="@") {
			r_l.push_back(templ);
			r_r.push_back(".");
			len++;
			return;
		}
		else {
			for (int i = 0; i <= tempr.length(); i++) {
				string temp_l;
				string temp_r;
				for (int j = 0; j < i; j++) {
					temp_l.push_back(tempr[j]);
				}
				for (int j = i; j < tempr.length(); j++) {
					temp_r.push_back(tempr[j]);
				}
				string a = temp_l + "." + temp_r;
				r_l.push_back(templ);
				r_r.push_back(a);
				len++;
			}
		}
	}
}

bool rule::operator==(const rule b) {
	int flag = 1;
	if (len != b.len) {
		return false;
	}
	for (int i = 0; i < len; i++) {
		string templ = r_l[i];
		string tempr = r_r[i];
		auto it_l = find(b.r_l.begin(), b.r_l.end(), templ);
		auto it_r = find(b.r_r.begin(), b.r_r.end(), tempr);
		if (it_l == b.r_l.end() || it_r==b.r_r.end()) {
			flag = 0;
			break;
		}
	}
	return flag == 1 ? 1 : 0;
}