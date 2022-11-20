#include <string>
#include<vector>
using namespace std;
class rule {
public:
	vector<string>r_l;
	vector<string>r_r;
	int len = 0;
	int numm = 0;
	rule(string s1, string s2);
	void back_rule();
	void show();
	bool operator==(const rule b);
};