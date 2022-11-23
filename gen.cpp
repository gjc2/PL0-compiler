#include "gen.h"
#include <stack>
#include <iostream>
using namespace std;
void gen::show() {
	for (int i = 0; i < state.size(); i++) {
		std::cout << state[i] << " ";
	}
	std::cout << endl;
	for (int i = 0; i < sym.size(); i++) {
		std::cout << sym[i] ;
	}
	std::cout << endl;
	for (int i = 0; i < in.size(); i++) {
		std::cout << in[i];
	}
	std::cout << endl;
}
void gen::g(table t, vector<rule*>origin) {
	state.push_back(0);
	sym.push_back("#");
	sym.push_back("b");
	in.pop_back();
	while (!in.empty()) {
		//∂¡◊¥Ã¨’ª∂•∫Õ ‰»Î’ª∂•
		int len1 = state.size() - 1;
		int len2 = in.size() - 1;
		int len3 = sym.size() - 1;
		if (t.f[{state[len1], in[len2]}].size() == 0) {
			std::cout << "error" << endl;
			return;
		}
		string temp = t.f[{state[len1], in[len2]}][0];
		if (temp == "ACC") { std::cout << "ok" << endl; return; }
		if (temp[0] == 'S') {
			int s;
			if (temp.length() == 3) {
				s = (temp[1] - '0') * 10 + temp[2] - '0';
			}
			else {
				s = temp[1] - '0';
			}
			state.push_back(s);
			string o = in[len2];
			in.pop_back();
			sym.push_back(o);
		}
		else if (temp[0] == 'R') {
			stack<string>u;
			int s;
			if (temp.length() == 3) {
				s = (temp[1] - '0') * 10 + temp[2] - '0';
			}
			else {
				s = temp[1] - '0';
			}
			rule* r = origin[s];
			for (int k = 0; k < r->r_r[0].length(); k++) {
				u.push(sym[len3]);
				len3--;
				len1--;
				sym.pop_back();
				state.pop_back();
			}
			sym.push_back(r->r_l[0]);
			if (t.f[{state[len1], sym[len3]}].size() == 0) {
				std::cout << "error" << endl;
			}
			int ss;
			if (t.f[{state[len1], in[len2]}][0].length() == 2) {
				ss = (t.f[{state[len1], in[len2]}][0][0] - '0') * 10 + t.f[{state[len1], in[len2]}][0][1] - '0';
			}
			else {
				ss = t.f[{state[len1], in[len2]}][0][0] - '0';
			}
			state.push_back(ss);
			std::cout << r->r_l[0] << "->";
			for (int k = 0; k < u.size(); k++) {
				std::cout << u.top();
				u.pop();
			}
			std::cout << endl;

		}
		else {
			int ss;
			if (t.f[{state[len1], in[len2]}][0].length() == 2) {
				ss = (t.f[{state[len1], in[len2]}][0][0] - '0') * 10 + t.f[{state[len1], in[len2]}][0][1] - '0';
			}
			else {
				ss = t.f[{state[len1], in[len2]}][0][0] - '0';
			}
			state.push_back(ss);
			string o = in[len2];
			sym.push_back(o);
			in.pop_back();
			
		}
		show();
	}
}