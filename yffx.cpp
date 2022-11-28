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



