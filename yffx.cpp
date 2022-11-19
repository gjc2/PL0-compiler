#include <iostream>
#include  <string>
#include <vector>
#include "item.h"

using namespace std;




int main() {
    rule a = rule("A", "BCD");
    item b(a);
    b.show();
}