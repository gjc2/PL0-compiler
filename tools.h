#include<fstream>
#include <vector>
#include <string>
#include "gen.h"
using namespace std;
pair<vector<rule*>, vector<rule*> > read_rule();
pair<vector<string>,vector<string> > read_instance(string file);
void set_type();
item* DFA_construct(vector<rule*>m,/*int level,*/ vector<rule*> add, item* fa);
table* dfs_dfa(vector<rule*>x,vector<rule*>y);
void generate(vector<string>sym, vector<string>name, vector<rule*>the_rule, table* lr, string lr_table, string mid_code);
