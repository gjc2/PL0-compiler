#include<iostream>
#include "item.h"
using namespace std;
item::item(rule m) {
    if (m.r_r == "@") {
        item_l.push_back(m.r_l);
        item_r.push_back(".");
        len++;
    }
    else {
        for (int i = 0; i <= m.r_r.length(); i++) {
            string temp_l;
            string temp_r;
            for (int j = 0; j < i; j++) {
                temp_l.push_back(m.r_r[j]);
            }
            for (int j = i; j < m.r_r.length(); j++) {
                temp_r.push_back(m.r_r[j]);
            }
            string a = temp_l + "." + temp_r;
            item_l.push_back(m.r_l);
            item_r.push_back(a);
            len++;
        }
    }
};

void item::show() {
    for (int i = 0; i < len; i++) {
        std::cout << item_l[i] << " -> " << item_r[i] << std::endl;
    }
};

