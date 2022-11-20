#include "table.h"
#include <iomanip>
using namespace std;
table::table(vector<item*>a,vector<string>T,vector<string>N,vector<rule*>origin) {
	for (int i = 0; i < a.size(); i++) {
		state.push_back(a[i]->numm);
	}
	for (int i = 0; i < T.size(); i++) {
		action.push_back(T[i]);
	}
	for (int i = 0; i < N.size(); i++) {
		Goto.push_back(N[i]);
	}
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < action.size(); j++)
			f[{state[i], action[j]}].push_back("  ");
		for(int j=0;j<Goto.size();j++)
			f[{state[i], Goto[j]}].push_back("  ");
	}
	//���ת��
	for (int i = 0; i < a.size(); i++) {
		for (auto j : a[i]->mp) {
			if (j.first.second >= "A"&& j.first.second <= "Z") {//Ҫ�ģ��ĳ��ж����ս�����Ƿ��ս��
				f[{a[i]->numm, j.first.second}].pop_back();
				f[{a[i]->numm, j.first.second}].push_back(to_string(j.second->numm));
			}
			else {
				f[{a[i]->numm, j.first.second}].pop_back();
				f[{a[i]->numm, j.first.second}].push_back("S" + to_string(j.second->numm));
			}
				
		}
	}
	//��ӹ�Լ
	for (int i = 0; i < a.size(); i++) {
		if (a[i]->numm == 1) continue;
		for (int j = 0; j < a[i]->I.size(); j++) {
			auto it = find(a[i]->I[j]->r_r[0].begin(), a[i]->I[j]->r_r[0].end(), '.');
			it++;
			if (it == a[i]->I[j]->r_r[0].end()) {//����A->BC.
				string templ = a[i]->I[j]->r_l[0];
				string tempr = a[i]->I[j]->r_r[0];
				tempr.pop_back();//���A->BC
				rule* temp = new rule(templ, tempr);
				for (int k = 0; k < origin.size(); k++) {
					if (*origin[k] == *temp) {
						int num = origin[k]->numm;
						for (int u = 0; u < T.size(); u++) {
							f[{a[i]->numm, T[u]}].pop_back();
							f[{a[i]->numm, T[u]}].push_back("R" + to_string(num));
						
						}
					}
				}
			}
		}
	}
	f[{1, "#"}].pop_back();
	f[{1, "#"}].push_back("ACC");
}

void table::show() {
	cout <<setw(8) << "       ";
	for (int j = 0; j < action.size(); j++) {
		cout << action[j] << "      ";
	}
	for (int j = 0; j < Goto.size(); j++) {
		cout << Goto[j] << "      ";
	}
	cout << endl;
	for (int i = 0; i < state.size(); i++) {
		cout << setw(2) << state[i] << "      ";
		for (int j = 0; j < action.size(); j++) {
			
			for (int k = 0; k < f[{state[i], action[j]}].size(); k++) {
					cout << f[{state[i], action[j]}][k] << "     ";
			}
		}
		for (int j = 0; j < Goto.size(); j++) {
			for(int k=0;k<f[{state[i], Goto[j]}].size();k++)
			cout << f[{state[i],Goto[j]}][k] << "     ";
		}
		cout << endl;
	}
}