#include<string>
using namespace std;
class entry {
public:
	string name;
	string kind;
	string var;
	int level;
	int addr;
	entry(string _name, string _kind, string _var, int _level, int _addr);
	void show();
};
