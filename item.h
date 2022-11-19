#include "rule.h"
#include <vector>
using namespace std;
class item {
public:
    vector<string>item_l;
    vector<string>item_r;
    int len = 0;
    item(rule m);
    void show();
};