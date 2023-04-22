#include "interpreter.h"
using namespace std;
//DL
//SL
//RA
interpreter::interpreter(vector<pcode*>c) {
	std::cout << "** start **" << std::endl;
	code = c;
	s.push_back(0);
	s.push_back(0);
	s.push_back(0);
	t = t + 2;
	while (1) {
		//cout << p << endl;
		/*cout << "**" << endl;
		
		for (int i = s.size()-1; i >=0; i--) {
			cout << s[i] << endl;
		}
		cout << "**" << endl;*/
		if (p >= code.size()) break;
		instruction = *code[p];
		//cout << instruction.op << endl;
		if (instruction.op == "LIT") {
			s.push_back(stoi(instruction.a));
			t++;
			p++;
		}
		else if (instruction.op == "LOD") {
			if (instruction.l == "0") {
				int pos = b + stoi(instruction.a) + 3;
				s.push_back(s[pos]);
				t++;
				p++;
			}
			else if (instruction.l == "1") {
				int last = s[b + 1];//SL
				s.push_back(s[last + 3 + stoi(instruction.a)]);
				t++;
				p++;
			}
			else if (instruction.l == "2") {
				int last1 = s[b + 1];
				int last2 = s[last1 + 1];
				s.push_back(s[last2 + 3 + stoi(instruction.a)]);
				t++;
				p++;
			}
		}
		else if (instruction.op == "STO") {
			int value = s[t];
			if (instruction.l == "0") {
				s[b + 3 + stoi(instruction.a)] = value;
				p++;
			}
			else if (instruction.l == "1") {
				int last = s[b + 1];
				s[last + 3 + stoi(instruction.a)] = value;
				p++;
			}
			else if (instruction.l == "2") {
				int last1 = s[b + 1];
				int last2 = s[last1 + 1];
				s[last2 + 3 + stoi(instruction.a)] = value;
				p++;
			}
			s.pop_back();
			t--;
		}
		else if (instruction.op == "CAL") {
			int ra = 0;
			int sl = 0;
			int dl = 0;
			ra = p + 1;
			sl = 0;
			dl = b;
			s.push_back(ra);
			s.push_back(sl);
			s.push_back(dl);
			t = t + 3;
			p = stoi(instruction.a);
			b = t - 2;

		}
		else if (instruction.op == "INT") {
			int num = stoi(instruction.a)-3;
			for (int i = 0; i < num; i++) {
				s.push_back(0);
				t++;
			}
			p++;
		}
		else if (instruction.op == "JMP") {
			p = stoi(instruction.a);
		}
		else if (instruction.op == "JPC") {
			if (s[t] == 1) {
				p = stoi(instruction.a);
			}
			else if (s[t] == 0) {
				p++;
			}
		}
		else if (instruction.op == "OPR") {
			if (instruction.a == "0") {
				int dl = s[b + 2];
				int ra = s[b];
				while (s.size() > b) {
					s.pop_back();
					t--;
				}
				b = dl;
				p = ra;
				p--;
				//cout << b << " " << p << endl;
			}
			else if (instruction.a == "1") {
				int value1 = s[t];
				int value2 = s[t - 1];
				int ans = value1 + value2;
				
				s.pop_back();
				t--;
				s.pop_back();
				t--;
				s.push_back(ans);
				t++;
			}
			else if (instruction.a == "2") {
				int value1 = s[t];
				int value2 = s[t - 1];
				int ans = value1 - value2;
				s.pop_back();
				t--;
				s.pop_back();
				t--;
				s.push_back(ans);
				t++;
			}
			else if (instruction.a == "3") {
				int value1 = s[t];
				int value2 = s[t - 1];
				int ans = value1 * value2;
				s.pop_back();
				t--;
				s.pop_back();
				t--;
				s.push_back(ans);
				t++;
			}
			else if (instruction.a == "4") {
				int value1 = s[t];
				int value2 = s[t - 1];
				int ans = value1 / value2;
				//cout << ans << endl;
				s.pop_back();
				t--;
				s.pop_back();
				t--;
				s.push_back(ans);
				t++;
			}
			else if (instruction.a == "5") {
				int value1 = s[t];
				int value2 = s[t - 1];
				int ans = 0;
				if (value2 < value1) ans = 1;
				else ans = 0;
				s.pop_back();
				t--;
				s.pop_back();
				t--;
				s.push_back(ans);
				t++;
			}
			else if (instruction.a == "6") {
				int value1 = s[t];
				int value2 = s[t - 1];
				int ans = 0;
				if (value2 <= value1) ans = 1;
				else ans = 0;
				s.pop_back();
				t--;
				s.pop_back();
				t--;
				s.push_back(ans);
				t++;
			}
			else if (instruction.a == "7") {
				int value1 = s[t];
				int value2 = s[t - 1];
				int ans = 0;
				if (value2 == value1) ans = 1;
				else ans = 0;
				s.pop_back();
				t--;
				s.pop_back();
				t--;
				s.push_back(ans);
				t++;
			}
			else if (instruction.a == "8") {
				int value1 = s[t];
				int value2 = s[t - 1];
				int ans = 0;
				if (value2 > value1) ans = 1;
				else ans = 0;
				s.pop_back();
				t--;
				s.pop_back();
				t--;
				s.push_back(ans);
				t++;
			}
			else if (instruction.a == "9") {
				int value1 = s[t];
				int value2 = s[t - 1];
				int ans = 0;
				if (value2 >= value1) ans = 1;
				else ans = 0;
				s.pop_back();
				t--;
				s.pop_back();
				t--;
				s.push_back(ans);
				t++;
			}
			else if (instruction.a == "10") {//read
				int temp;
				std::cout << "ÊäÈë:" << std::endl;
				std::cin >> temp;
				s.push_back(temp);
				t++;
			}
			else if (instruction.a == "11") {//write
				std::cout << "Êä³ö:" << endl;
				std::cout << s[t] << endl;
				s.pop_back();
				t--;
			}
			else if (instruction.a == "12") {
				int value1 = s[t];
				int value2 = s[t - 1];
				int ans = 0;
				if ((value2 & value1) == 1) ans = 1;
				else ans = 0;
				s.pop_back();
				t--;
				s.pop_back();
				t--;
				s.push_back(ans);
				t++;
			}
			else if (instruction.a == "13") {
			int value1 = s[t];
			int value2 = s[t - 1];
			int ans = 0;
			if (value2 != value1) ans = 1;
			else ans = 0;
			s.pop_back();
			t--;
			s.pop_back();
			t--;
			s.push_back(ans);
			t++;
			}
			p++;
		}
	}
	std::cout << "** end **" << std::endl;
}
