#include<iostream>
#include "object.h"
using namespace std;

//mid_code
//sym_table

/*
OPR 1 +
OPR 2 -
OPR 3 *
OPR 4 /

OPR 5 <
OPR 6 <=
OPR 7 ==
OPR 8 >
OPR 9 >=
OPR 10 read
OPR 11 write
OPR 12 jodd
*/
objectcode::objectcode(mid* t) {
	//mid
	//vector<quad*>code 四元组
	//vector<entry*>m	符号表
	vector<quad*>code = t->code;
	vector<entry*>table = t->m;
	int ll = 0;
	int now = 0;//now=-1表示处于主程序中，0,1,2,3,...表示第几个子程序
	int nol = 0;
	int begin = -1;
	int end = -1;
	int push_num = 0;
	int intt = count_data(t,0);
	gen("INT", "0", to_string(3 + intt));
	for (int i = 0; i <= code.size(); i++) {
		need(i);
		if (i == code.size()) break;
		quad* nowmid = code[i];
		if (nowmid->q[0] == "j*") {
			if (lookup(t, now) != -1) {
				gen("JMP", "0", "0");
				begin = all_num;//子程序的起点
				cout << end << endl;
				backto.push_back({ begin-1,stoi(nowmid->q[3]) });
				nol = lookup(t, now);
				end = table[nol]->level;//子程序的终点
				table[nol]->level = begin ;
				gen("INT", "0", to_string(count_data(t, nol+1) + 3));
				//backto.push_back({ all_num,stoi(nowmid->q[3]) });
				now++;
				ll++;
			}//在符号表中找到子程序

		}//表示子程序
		else {
			//gen("#","("+nowmid->q[0] + "," + nowmid->q[1] + "," + nowmid->q[2] + "," + nowmid->q[3]+")","#");
			if (nowmid->q[0] == "+" ||
				nowmid->q[0] == "-" ||
				nowmid->q[0] == "*" ||
				nowmid->q[0] == "/") {
				int s = 0;
				string op1 = nowmid->q[1];
				string op2 = nowmid->q[2];
				string op3 = nowmid->q[3];
				//op1
				if (lookup2(t, op1) != -1) {
					int pos = lookup2(t, op1);
					if (table[pos]->kind == "variable")
						gen("LOD", to_string(ll-table[pos]->level), to_string(pos));
					else if(table[pos]->kind == "constant")
						gen("LIT", "0", table[pos]->var);
				}
				else {
					if (op1 == "-") {
						gen("LIT", "0", "0");
					}
					else {
						gen("LIT", "0", op1);
					}
				}
				//op2
				if (lookup2(t, op2) != -1) {
					int pos = lookup2(t, op2);
					if (table[pos]->kind == "variable" )
						gen("LOD", to_string(ll-table[pos]->level), to_string(pos));
					else if (table[pos]->kind == "constant")
						gen("LIT", "0", table[pos]->var);
				}
				else {
					if (op2 == "-") {
						gen("LIT", "0", "0");
					}
					else {
						gen("LIT", "0", op2);
					}
				}
				//op3
				int pos = lookup2(t, op3);
				if (nowmid->q[0] == "+") {
					gen("OPR","0","1");
				}
				if (nowmid->q[0] == "-") {
					gen("OPR", "0", "2");
				}
				if (nowmid->q[0] == "*") {
					gen("OPR", "0", "3");
				}
				if (nowmid->q[0] == "/") {
					gen("OPR", "0", "4");
				}
				//gen("STO", to_string(table[pos]->level), to_string(pos));
				
			}
			else if (nowmid->q[0] == "=") {
				string op1 = nowmid->q[1];
				string op2 = nowmid->q[2];
				string op3 = nowmid->q[3];
				int pos = lookup2(t, op1);
				/*if (table[pos]->kind == "const") {
					gen("LIT", "0", table[pos]->var);
				}
				else {
					gen("LOD", to_string(table[pos]->level), to_string(pos));
				}*/
				pos = lookup2(t, op3);
				gen("STO", to_string(ll-table[pos]->level), to_string(pos));
			}
			else if (nowmid->q[0] == "j") {
				gen("JMP", "0", "0");
				backto.push_back({ all_num - 1,stoi(nowmid->q[3]) });
			}
			else if (nowmid->q[0] == "j==") {
				string op1 = nowmid->q[1];
				string op2 = nowmid->q[2];
				string op3 = nowmid->q[3];
				//op1
				
				gen("OPR", "0", "7");
				gen("JPC", "0", "0");
				backto.push_back({ all_num - 1,stoi(nowmid->q[3]) });
			}
			else if (nowmid->q[0] == "j<") {
				string op1 = nowmid->q[1];
				string op2 = nowmid->q[2];
				string op3 = nowmid->q[3];
				//op1
				
				gen("OPR", "0", "5");
				gen("JPC", "0", "0");
				backto.push_back({ all_num - 1,stoi(nowmid->q[3]) });
			}
			else if (nowmid->q[0] == "j<=") {
			string op1 = nowmid->q[1];
			string op2 = nowmid->q[2];
			string op3 = nowmid->q[3];
			//op1
			
			gen("OPR", "0", "6");
			gen("JPC", "0", "0");
			backto.push_back({ all_num - 1,stoi(nowmid->q[3]) });
			}
			else if (nowmid->q[0] == "j>") {
			string op1 = nowmid->q[1];
			string op2 = nowmid->q[2];
			string op3 = nowmid->q[3];
			//op1
			
			gen("OPR", "0", "8");
			gen("JPC", "0", "0");
			backto.push_back({ all_num - 1,stoi(nowmid->q[3]) });
			}
			else if (nowmid->q[0] == "j>=") {
			string op1 = nowmid->q[1];
			string op2 = nowmid->q[2];
			string op3 = nowmid->q[3];
			//op1
			
			gen("OPR", "0", "9");
			gen("JPC", "0", "0");
			backto.push_back({ all_num - 1,stoi(nowmid->q[3]) });
			}
			else if (nowmid->q[0] == "read" || nowmid->q[0] == "write") {
				if (nowmid->q[0] == "read") {
					while (push_num != 0) {
						push_num--;
						gen("OPR", "0", "10");
					}
					for (int ii = i - stoi(nowmid->q[3]); ii < i; ii++) {
						quad* nowmid2 = code[ii];
						string op = nowmid2->q[3];
						if (lookup2(t, op) != -1) {
							int pos = lookup2(t, op);
							if (table[pos]->kind == "variable" || table[pos]->kind == "tempvar")
								gen("STO", to_string(ll-table[pos]->level), to_string(pos));
							else
								gen("LIT", "0", table[pos]->var);
						}
					}
				}
				else {
					while (push_num != 0) {
						push_num--;
						gen("OPR", "0", "11");
					}
				}
			}
			else if (nowmid->q[0] == "j_call") {
				string op3=nowmid->q[3];
				int nol;
				for (int i = 0; i < table.size(); i++) {
					if (table[i]->kind == "procedure" || table[i]->name == op3) {
						nol = i;
					}
					else
						continue;
				}
				gen("CAL", "0", to_string(table[nol]->level));
			}
			else if (nowmid->q[0] == "jodd") {
			string op1 = nowmid->q[1];
			string op2 = nowmid->q[2];
			string op3 = nowmid->q[3];
			//op1
			
			gen("OPR", "0", "12");
			gen("JPC", "0", "0");
			backto.push_back({ all_num - 1,stoi(nowmid->q[3]) });
			}
			else if (nowmid->q[0] == "push") {
				push_num++;
				string op = nowmid->q[3];
				if (lookup2(t, op) != -1) {
					int pos = lookup2(t, op);
					if (table[pos]->kind == "variable" || table[pos]->kind == "tempvar")
						gen("LOD", to_string(ll-table[pos]->level), to_string(pos));
					else
						gen("LIT", "0", table[pos]->var);
				}
				else {
					if (op == "-") {
						gen("LIT", "0", "0");
					}
					else {
						gen("LIT", "0", op);
					}
				}
			}
			
		}
		if (i == end) {
			object_code.pop_back();
			//object_code[begin-1]->a = to_string(data_num);
			for (int iii = 0; iii < backto.size(); iii++) {
				if (backto[iii].first == all_num-1) {
					backto[iii].second =- 1;
				}
			}
			all_num--;
			gen("OPR", "0", "0");
			code_num = 0;
			data_num = 0;
			begin = -1;
			end = -1;
			ll--;
		}
	}
};

int objectcode::lookup(mid* t,int nol) {
	vector<entry*>table = t->m;
	int now = 0;
	for (int i = 0; i < table.size(); i++) {
		if (table[i]->kind == "procedure") {
			if (now == nol) {
				return i;
			}
			now++;
		}
	}
	return -1;
}

int objectcode::lookup2(mid* t, string name) {
	vector<entry*>table = t->m;
	for (int i = 0; i < table.size(); i++) {
		if (table[i]->name == name) {
			return i;
		}
	}
	return -1;
}
void objectcode::gen(string op, string l, string a) {
	if (op != "#") {
		object_code.push_back(new pcode(op, l, a));
		if (op == "LIT" || op == "LOD") {
			code_num++;
			data_num++;
		}
		else if (op == "OPR")
			code_num--;
		else if (op == "STO") {
			code_num--;
			data_num++;
		}
		else if (op == "JMP" || op == "JPC")
			;//code_num--;
		else if (op == "CAL") {
			;//call指令
		}
		all_num++;
	}
	else {
		object_code.push_back(new pcode(op, l, a));
	}
}

void objectcode::show() {
	ofstream file("object_code.txt"/*, ios::app*/);
	int s = 0;
	for (int i = 0; i < object_code.size(); i++) {
		if (object_code[i]->op != "#") {
			file << s << ": " << object_code[i]->op << " " << object_code[i]->l << " " << object_code[i]->a << endl;
			s++;
		}
		else {
			file << " " << object_code[i]->op << " " << object_code[i]->l << " " << object_code[i]->a << endl;
		}
	}
	file.close();
	cout << 1 << endl;
}

int objectcode::count_data(mid* t,int s) {
	vector<entry*>table = t->m;
	int ans = 0;
	for (int i = s; i < table.size(); i++) {
		if (table[i]->kind == "constant" || table[i]->kind == "variable") {
			ans++;
		}
		else break;

	}
	return ans;
}

int objectcode::need(int s) {
	for (int i = 0; i < backto.size(); i++) {
		if (backto[i].second == s) {
			object_code[backto[i].first]->a = to_string(all_num);
		}
	}
	return 0;
}