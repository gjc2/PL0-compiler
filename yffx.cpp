#include <iostream>
#include  <string>
#include <vector>
#include "tools.h"
using namespace std;

int main() {
    //读取规则
    vector<rule*>back_rule=read_rule().first;
    vector<rule*>the_rule= read_rule().second;
    //建立DFA和分析表
    table* lr=dfs_dfa(back_rule,the_rule);
   //读取实例
    pair<vector<string>,vector<string>>word=read_instance("output.txt");
    vector<string>sym=word.first;
    vector<string>name=word.second;
    std::reverse(sym.begin(), sym.end());
    std::reverse(name.begin(), name.end());
    //归约与中间代码生成
    generate(sym, name, the_rule, lr);

}



//item* DFA_construct(vector<rule*>m,/*int level,*/ vector<rule*> add,item* fa) {
//    item* a = new item();
//    for (int j = 0; j < add.size(); j++) {
//        a->push_rule(add[j]);
//    }
//    for (int j = 0; j < a->len; j++) {//遍历该状态的所有规则
//        string templ = a->I[j]->r_l[0];//某个规则的左边
//        string tempr = a->I[j]->r_r[0];//某个规则的右边
//        auto it = find(tempr.begin(), tempr.end(), '.');
//        auto itt=find(tempr.begin(), tempr.end(), '.');
//        it++;
//        if (it == tempr.end()) continue;
//        string str = string(1, * it);
//        if (type[str] == 0) {//.后面是非终结符
//            //找到S->.M这样的规则
//            //加入
//            for (int i = 0; i < m.size(); i++) {//遍历所有的规则
//                for (int k = 0; k < m[i]->len; k++) {
//                    //if (m[i]->r_l[k] == str && m[i]->r_r[k] == ".") {
//                    //    swap(*it, *itt);
//                    //    a->push_rule(new rule(m[i]->r_l[k], tempr));
//                    //    //swap(*it, *itt);
//                    //}
//                    if (m[i]->r_l[k] == str&&m[i]->r_r[k][0]=='.') {
//                        a->push_rule(new rule(m[i]->r_l[k], m[i]->r_r[k]));
//                    }
//                }
//            }
//        }
//        
//    }
//    
//    int exist = 0;
//    int num;
//    for (int i = 0; i < dfa.size(); i++) {
//        if (*dfa[i] == *a) {
//            exist = 1;
//            num = i;
//            break;
//        }
//    }
//    if (exist) {
//        return dfa[num];
//    }
//    else {
//        level++;
//        //cout << "I" << level << ":" << endl;
//        //a->show();
//        a->numm = level;
//        dfa.push_back(a);
//    }
//
//    //开始dfs
//    for (int j = 0; j < a->len; j++) {
//        string templ = a->I[j]->r_l[0];
//        string tempr = a->I[j]->r_r[0];
//        auto it = find(tempr.begin(), tempr.end(), '.');
//        it++;
//        if (it == tempr.end()) continue;
//        string str = string(1, *it);
//        if (type[str] == 0) {//是终结符
//            vector<rule*> temp;
//            if (!a->mp[{a, str}]) {
//                for (int i = 0; i < a->len; i++) {
//                    string templl = a->I[i]->r_l[0];
//                    string temprr = a->I[i]->r_r[0];
//                    auto it_2 = find(temprr.begin(), temprr.end(), '.');
//                    it_2++;
//                    if (it_2 == temprr.end()) {
//                        continue;
//                    }
//
//                    string str_2 = string(1, *it_2);
//                    if (str_2 == str) {
//                        it_2--;
//                        auto it_l = it_2;
//                        it_2++;
//                        swap(*it_l, *it_2);
//                        temp.push_back(new rule(templl, temprr));
//                    }
//                }
//                
//                a->mp[{a, str}] = DFA_construct(m, temp, a);
//            }
//        }
//        else {//是非终结符
//            vector<rule*>temp;
//            if (!a->mp[{a, str}]) {
//                for (int i = 0; i < a->len; i++) {
//                    string templl = a->I[i]->r_l[0];
//                    string temprr = a->I[i]->r_r[0];
//                    auto it_2 = find(temprr.begin(), temprr.end(), '.');
//                    it_2++;
//                    if (it_2 == temprr.end()) {
//                        continue;
//                    }
//
//                    string str_2 = string(1, *it_2);
//                    if (str_2 == str) {
//                        it_2--;
//                        auto it_l = it_2;
//                        it_2++;
//                        swap(*it_l, *it_2);
//                        temp.push_back(new rule(templl, temprr));
//                    }
//                }
//                
//                a->mp[{a, str}] = DFA_construct(m, temp, a);
//            }
//        }
//    }
//    return a;
//}

//void set_type() {
//    for (int i = 0; i <= 25; i++) {
//        char temp = 'a' + i;
//        char tempp = 'A' + i;
//        string str(1, temp);
//        string strr(1, tempp);
//        type[str] = 1;
//        type[strr] = 0;
//    }
//    type["0"] = 0;
//    type["1"] = 0;
//    type["2"] = 0;
//    type["3"] = 0;
//    type["4"] = 0;
//    type["6"] = 0;
//    type["5"] = 0;
//}

