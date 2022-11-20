#include <iostream>
#include  <string>
#include <vector>
#include "table.h"


using namespace std;


map<string, int>type;//字符到终结符还是非终结符的映射,0为非终结符，1以后分配给终结符
vector<item*>s;
item* DFA_construct(vector<rule*>m, /*int level, */vector<rule*> add,item* fa);
void set_type();
int level = -1;
vector<item*>dfa;
int main() {
    set_type();
    vector<rule*>x;
    vector<rule*>y;
    x.push_back(new rule("&", "E"));
    x.push_back(new rule("E", "aA"));
    x.push_back(new rule("E", "bB"));
    x.push_back(new rule("A", "cA"));
    x.push_back(new rule("A", "d"));
    x.push_back(new rule("B", "cB"));
    x.push_back(new rule("B", "d"));

    y.push_back(new rule("&", "E"));
    y.push_back(new rule("E", "aA"));
    y.push_back(new rule("E", "bB"));
    y.push_back(new rule("A", "cA"));
    y.push_back(new rule("A", "d"));
    y.push_back(new rule("B", "cB"));
    y.push_back(new rule("B", "d"));
    for (int i = 0; i < 7; i++) {
        x[i]->back_rule();
        x[i]->show();
        y[i]->numm = i;
        cout << endl;
    }
    cout << "test:" << endl;
    vector<rule*> p;
    p.push_back(new rule(x[0]->r_l[0], x[0]->r_r[0]));
    DFA_construct(x,p,0);
    cout << "all:" << endl;
    for (int i = 0; i < dfa.size(); i++) dfa[i]->show_all();
    vector<string>N = { "E","A","B" };
    vector<string>T = { "a","b","c","d","#" };
    table* test = new table(dfa, T, N, y);
    test->show();
}



item* DFA_construct(vector<rule*>m,/*int level,*/ vector<rule*> add,item* fa) {
    item* a = new item();
    for (int j = 0; j < add.size(); j++) {
        a->push_rule(add[j]);
    }
    for (int j = 0; j < a->len; j++) {//遍历该状态的所有规则
        string templ = a->I[j]->r_l[0];//某个规则的左边
        string tempr = a->I[j]->r_r[0];//某个规则的右边
        auto it = find(tempr.begin(), tempr.end(), '.');
        auto itt = it + 1;
        if (itt == tempr.end()) continue;
        it++;
        string str = string(1, * it);
        if (type[str] == 0) {//.后面是非终结符
            //找到S->.M这样的规则
            //加入
            for (int i = 0; i < m.size(); i++) {//遍历所有的规则
                for (int k = 0; k < m[i]->len; k++) {
                    if (m[i]->r_l[k] == str&&m[i]->r_r[k][0]=='.') {
                        a->push_rule(new rule(m[i]->r_l[k], m[i]->r_r[k]));
                    }
                }
            }
        }
        
    }
    int exist = 0;
    int num;
    for (int i = 0; i < dfa.size(); i++) {
        if (*dfa[i] == *a) {
            exist = 1;
            num = i;
            break;
        }
    }
    if (exist) {
        return dfa[num];
    }
    else {
        level++;
        //cout << "I" << level << ":" << endl;
        //a->show();
        a->numm = level;
        dfa.push_back(a);
    }

    //开始dfs
    for (int j = 0; j < a->len; j++) {
        string templ = a->I[j]->r_l[0];
        string tempr = a->I[j]->r_r[0];
        auto it = find(tempr.begin(), tempr.end(), '.');
        it++;
        if (it == tempr.end()) continue;
        string str = string(1, *it);
        if (type[str] == 0) {//是终结符
            vector<rule*> temp;
            if (!a->mp[{a, str}]) {
                for (int i = 0; i < a->len; i++) {
                    string templl = a->I[i]->r_l[0];
                    string temprr = a->I[i]->r_r[0];
                    auto it_2 = find(temprr.begin(), temprr.end(), '.');
                    it_2++;
                    if (it_2 == temprr.end()) {
                        continue;
                    }

                    string str_2 = string(1, *it_2);
                    if (str_2 == str) {
                        it_2--;
                        auto it_l = it_2;
                        it_2++;
                        swap(*it_l, *it_2);
                        temp.push_back(new rule(templl, temprr));
                    }
                }
                
                a->mp[{a, str}] = DFA_construct(m, temp, a);
            }
        }
        else {//是非终结符
            vector<rule*>temp;
            if (!a->mp[{a, str}]) {
                for (int i = 0; i < a->len; i++) {
                    string templl = a->I[i]->r_l[0];
                    string temprr = a->I[i]->r_r[0];
                    auto it_2 = find(temprr.begin(), temprr.end(), '.');
                    it_2++;
                    if (it_2 == temprr.end()) {
                        continue;
                    }

                    string str_2 = string(1, *it_2);
                    if (str_2 == str) {
                        it_2--;
                        auto it_l = it_2;
                        it_2++;
                        swap(*it_l, *it_2);
                        temp.push_back(new rule(templl, temprr));
                    }
                }
                
                a->mp[{a, str}] = DFA_construct(m, temp, a);
            }
        }
    }
    return a;
}

void set_type() {
    for (int i = 0; i <= 25; i++) {
        char temp = 'a' + i;
        char tempp = 'A' + i;
        string str(1, temp);
        string strr(1, tempp);
        type[str] = 1;
        type[strr] = 0;
    }
}

