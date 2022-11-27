#include <iostream>
#include  <string>
#include <vector>
#include "gen.h"

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
    x.push_back(new rule("&", "A"));//我们把。看成.为了和后继规则中的.区分
    x.push_back(new rule("A", "B!"));
    x.push_back(new rule("B", "FIKH"));
    x.push_back(new rule("F", "C"));
    x.push_back(new rule("F", "@"));
    x.push_back(new rule("I", "D"));
    x.push_back(new rule("I", "@"));
    x.push_back(new rule("K", "E"));
    x.push_back(new rule("K", "@"));
    x.push_back(new rule("C", "aG0;"));
    x.push_back(new rule("0", ",G0"));
    x.push_back(new rule("0", "@"));
    x.push_back(new rule("G", "p=o"));
    x.push_back(new rule("D", "bp1;"));
    x.push_back(new rule("1", ",p1"));
    x.push_back(new rule("1", "@"));
    x.push_back(new rule("E", "LB;J"));
    x.push_back(new rule("J", "EJ"));
    x.push_back(new rule("J", "@"));
    x.push_back(new rule("L", "cp;"));
    x.push_back(new rule("M", "N"));
    x.push_back(new rule("M", "O"));
    x.push_back(new rule("M", "P"));
    x.push_back(new rule("M", "Q"));
    x.push_back(new rule("M", "R"));
    x.push_back(new rule("M", "S"));
    x.push_back(new rule("M", "T"));
    x.push_back(new rule("M", "@"));
    x.push_back(new rule("N", "pdV"));
    x.push_back(new rule("T", "eH2f"));
    x.push_back(new rule("2", ";H2"));
    x.push_back(new rule("2", "@"));
    x.push_back(new rule("W", "VsV"));
    x.push_back(new rule("W", "gV"));
    x.push_back(new rule("V", "3YU"));
    x.push_back(new rule("3", "q"));
    x.push_back(new rule("3", "@"));
    x.push_back(new rule("U", "qYU"));
    x.push_back(new rule("U", "@"));
    x.push_back(new rule("Y", "ZX"));
    x.push_back(new rule("X", "rZX"));
    x.push_back(new rule("X", "@"));
    x.push_back(new rule("Z", "p"));
    x.push_back(new rule("Z", "o"));
    x.push_back(new rule("Z", "(V)"));
    x.push_back(new rule("O", "h5iH"));
    x.push_back(new rule("Q", "jp"));
    x.push_back(new rule("P", "k5lH"));
    x.push_back(new rule("R", "m(p1)"));
    x.push_back(new rule("S", "n(p1)"));
    x.push_back(new rule("H", "4M"));
    x.push_back(new rule("4", "@"));
    x.push_back(new rule("5", "6W"));
    x.push_back(new rule("6", "@"));


    y.push_back(new rule("&", "A"));
    y.push_back(new rule("A", "B!"));
    y.push_back(new rule("B", "FIKH"));
    y.push_back(new rule("F", "C"));
    y.push_back(new rule("F", "@"));
    y.push_back(new rule("I", "D"));
    y.push_back(new rule("I", "@"));
    y.push_back(new rule("K", "E"));
    y.push_back(new rule("K", "@"));
    y.push_back(new rule("C", "aG0;"));
    y.push_back(new rule("0", ",G0"));
    y.push_back(new rule("0", "@"));
    y.push_back(new rule("G", "p=o"));
    y.push_back(new rule("D", "bp1;"));
    y.push_back(new rule("1", ",p1"));
    y.push_back(new rule("1", "@"));
    y.push_back(new rule("E", "LB;J"));
    y.push_back(new rule("J", "EJ"));
    y.push_back(new rule("J", "@"));
    y.push_back(new rule("L", "cp;"));
    y.push_back(new rule("M", "N"));
    y.push_back(new rule("M", "O"));
    y.push_back(new rule("M", "P"));
    y.push_back(new rule("M", "Q"));
    y.push_back(new rule("M", "R"));
    y.push_back(new rule("M", "S"));
    y.push_back(new rule("M", "T"));
    y.push_back(new rule("M", "@"));
    y.push_back(new rule("N", "pdV"));
    y.push_back(new rule("T", "eH2f"));
    y.push_back(new rule("2", ";H2"));
    y.push_back(new rule("2", "@"));
    y.push_back(new rule("W", "VsV"));
    y.push_back(new rule("W", "gV"));
    y.push_back(new rule("V", "3YU"));
    y.push_back(new rule("3", "q"));
    y.push_back(new rule("3", "@"));
    y.push_back(new rule("U", "qYU"));
    y.push_back(new rule("U", "@"));
    y.push_back(new rule("Y", "ZX"));
    y.push_back(new rule("X", "rZX"));
    y.push_back(new rule("X", "@"));
    y.push_back(new rule("Z", "p"));
    y.push_back(new rule("Z", "o"));
    y.push_back(new rule("Z", "(V)"));
    y.push_back(new rule("O", "h5iH"));
    y.push_back(new rule("Q", "jp"));
    y.push_back(new rule("P", "k5lH"));
    y.push_back(new rule("R", "m(p1)"));
    y.push_back(new rule("S", "n(p1)"));
    y.push_back(new rule("H", "4M"));
    y.push_back(new rule("4", "@"));
    y.push_back(new rule("5", "6W"));
    y.push_back(new rule("6", "@"));

    for (int i = 0; i < 54; i++) {
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
    vector<string>N = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3","4","5","6"};
    vector<string>T = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","#",",",";","(",")","!","="};
    table* test = new table(dfa, T, N, y);
    test->show();
    vector<string>xxx = 
    { "a","p","=","o",";","b","p",",",
        "p",",","p",";","c","p",";",
        "b","p",";","e","p","d","p","r","o",
        ";","p","d","p","r","o",";","h","p","s",
        "p","i","p","d","p","q","p","f",";","e","m",
        "(","p",",","p",")",";","n","(","p",",","p",",","p",")",
        ";","j","p",";","k","g","p","l","p","d","q","p","q","o","f",
        "!","#"
    };
    vector<string>xxx_n =
    {
        "const","a","=","10",";","var","d",
        ",","e",",","f",";","procedure","p",
        ";","var","g",";","begin","d",":=","a",
        "*","2",";","e",":=","a","/","3",";","if",
        "d","<=","e","then","f",":=","d","+","e","end",";",
        "begin","read","(","e",",","f",")",";","write","(","e",",",
        "f",",","d",")",";","call","p",";","while","odd","d","do","e",":=",
        "-","e","+","1","end",
        "!","#"
    };
    reverse(xxx.begin(), xxx.end());
    reverse(xxx_n.begin(), xxx_n.end());
    gen* g = new gen();
    g->in =xxx;
    g->in_p = xxx_n;
    g->g(*test, y);

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
        auto itt=find(tempr.begin(), tempr.end(), '.');
        it++;
        if (it == tempr.end()) continue;
        string str = string(1, * it);
        if (type[str] == 0) {//.后面是非终结符
            //找到S->.M这样的规则
            //加入
            for (int i = 0; i < m.size(); i++) {//遍历所有的规则
                for (int k = 0; k < m[i]->len; k++) {
                    //if (m[i]->r_l[k] == str && m[i]->r_r[k] == ".") {
                    //    swap(*it, *itt);
                    //    a->push_rule(new rule(m[i]->r_l[k], tempr));
                    //    //swap(*it, *itt);
                    //}
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
    type["0"] = 0;
    type["1"] = 0;
    type["2"] = 0;
    type["3"] = 0;
    type["4"] = 0;
    type["6"] = 0;
    type["5"] = 0;
}

