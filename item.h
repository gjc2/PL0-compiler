#include "rule.h"
#include <vector>
#include <map>
using namespace std;
class item {
    public:
        vector<rule*>I;
        map<pair<item*, string>, item*>mp;
        int len=0;
        int numm = 0;
        item(){}
        void push_rule(rule* r);
        void push_map(pair<item*, string>a, item* b);
        bool operator==(const item b);
        void show();
        void show_all();
};