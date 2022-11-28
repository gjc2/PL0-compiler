#include "gen.h"
#include <stack>
#include <iostream>
#include <fstream>
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
	for (int i = in.size()-1; i >=0; i--) {
		std::cout << in[i];
	}
	std::cout << endl;
}
void gen::g(table t, vector<rule*>origin) {
	ofstream a11(lr_table, ios::out);
	ofstream a22(mid_code, ios::out);
	a11.close();
	a22.close();
	midcode->lr_table = lr_table;
	midcode->mid_code = mid_code;
	state.push_back(0);
	sym.push_back("#");
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
		if (temp == "ACC") { 
			std::cout << "ok" << endl; 
			midcode->show();
			return; 
		}
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
			string o2 = in_p[len2];
			in.pop_back();
			in_p.pop_back();
			sym.push_back(o);
			midcode->sta.push_back({ o2 ," "," "," "});
		}
		else if (temp[0] == 'R') {
			
			int s;
			if (temp.length() == 3) {
				s = (temp[1] - '0') * 10 + temp[2] - '0';
			}
			else {
				s = temp[1] - '0';
			}
			rule* r = origin[s];
			if (r->r_r[0] != "@") {
				for (int k = 0; k < r->r_r[0].length(); k++) {
					len3--;
					len1--;
					sym.pop_back();
					state.pop_back();
				}
			}
			sym.push_back(r->r_l[0]);
			len3++;
			if (t.f[{state[len1], sym[len3]}].size() == 0) {
				std::cout << "error" << endl;
			}
			int ss;
			if (t.f[{state[len1], sym[len3]}][0].length() == 2) {
				ss = (t.f[{state[len1], sym[len3]}][0][0] - '0') * 10 + t.f[{state[len1], sym[len3]}][0][1] - '0';
			}
			else {
				ss = t.f[{state[len1], sym[len3]}][0][0] - '0';
			}
			state.push_back(ss);
			r->show();
			(midcode->*mid::func[s])();
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