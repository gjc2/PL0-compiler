#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class quad {
public:
	string q[4];
	string mid_code = " ";
	quad(string a[4]) {
		for (int i = 0; i < 4; i++) {
			q[i] = a[i];
		}
	}
	void show() {
		ofstream file(mid_code, ios::app);
		file << "(";
		for (int i = 0; i < 4; i++) {
			if (i != 3)
				file << q[i] << ",";
			else file << q[i] << ")" << endl;
		}
		file.close();
	}
};
