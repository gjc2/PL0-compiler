#include<string>
#include<vector>
#include "rule.h"
#include <iostream>
rule::rule(string s1, string s2) {
	r_l = s1;
	r_r = s2;
}
void rule::show() {
	std::cout << r_l << " -> " << r_r << std::endl;
}